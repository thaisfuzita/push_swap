*This project has been created as part of the 42 curriculum by hesantan, tjulya-c*

# push_swap

## Description

`push_swap` sorts a random list of integers using two stacks (`a` and `b`) and a
limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`,
`rrb`, `rrr`), aiming to do it with the smallest possible number of operations.

The project implements **four sorting strategies**, each targeting a different
complexity class measured in number of push_swap operations generated (not
classical array-based complexity):

| Strategy | Class | Selector flag |
|---|---|---|
| Simple | O(n²) | `--simple` |
| Medium | O(n√n) | `--medium` |
| Complex | O(n log n) | `--complex` |
| Adaptive | picks the above based on measured disorder | `--adaptive` (default) |

A **disorder metric** (0 = already sorted, 1 = worst case) is computed before any
move, and the adaptive strategy uses it to pick the appropriate class:

- `disorder < 0.2` → Simple
- `0.2 ≤ disorder < 0.5` → Medium
- `disorder ≥ 0.5` → Complex

## Instructions

Build:
```bash
make
```

Run:
```bash
./push_swap 2 1 3 6 5 8
```

Force a specific strategy:
```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
```

Benchmark mode (metrics on stderr, operations stay on stdout):
```bash
./push_swap --bench 4 67 3 87 23 2> bench.txt
cat bench.txt
```

## Algorithms — technical choices and justification

### Simple (O(n²))

Repeatedly finds the current minimum in `a`, rotates it to the top using
whichever direction (`ra`/`rra`) is shorter, and pushes it to `b`. Once `a` has
one element left, `b` is drained back into `a`.

Because it always picks the shorter rotation direction, this implementation is
not uniformly O(n²) in practice: fully sorted and fully reversed inputs are
cheap (a reversed array keeps its minimum at the very bottom, so a single `rra`
per extraction suffices), while a genuinely random arrangement is the real
worst case. Empirically, at n=200: 1054 ops on low-disorder input vs 5482 ops
on random input (disorder 49%) — a 5x difference from arrangement alone, at
the same size and nominal complexity class.

### Medium (O(n√n))

Chunk-based sorting. Stack `a`'s values are index-normalized (rank 0..n-1),
then distributed into `b` in increasing index chunks of size `group_size` by
rotating `a` and pushing matching elements (`fill_b`). Once `b` holds
everything, it's drained back into `a` by repeatedly finding and rotating the
current maximum to the top (`find_max` + `shortest_rotation`), which produces
ascending order in `a`.

**Chunk size tuning.** The textbook choice is `group_size = √n`, which balances
two competing costs in this implementation:
- the scanning phase (`fill_b`) costs roughly `n² / group_size` — larger chunks
  mean fewer chunk-boundary confirmation scans;
- the extraction phase (`find_max`/rotation) costs roughly proportional to
  `n × group_size` — larger chunks mean more disorder to resolve inside each
  chunk during extraction.

We benchmarked several multipliers of `√n` (0.5x to 5x) across n = 50 to 1000,
both via a Python simulation of the exact `fill_b`/`find_max`/`shortest_rotation`
logic and directly on the compiled binary. Both agreed: the scanning phase's
constant factor is larger than the extraction phase's in this implementation,
so the true minimum sits past `√n`, around **3× √n**, not exactly at `√n`.

| n | `group_size = √n` | `group_size = 3√n` | improvement |
|---|---|---|---|
| 100 | 1250 ops | 917 ops | 26.6% |
| 500 | 13679 ops | 9614 ops | 29.7% |
| 1000 | 38229 ops | 26824 ops | 29.8% |

Final choice: `group_size = ft_sqrt(a->size) * 3`. This is a constant-factor
optimization only — the strategy remains O(n√n), confirmed empirically:
doubling n from 500 to 1000 multiplies ops by ~2.79x, matching the theoretical
√2 × 2 ≈ 2.83x for O(n√n).

### Complex (O(n log n))

LSD radix sort adapted to stacks. Values are index-normalized to 0..n-1, then
for each bit position (from `get_max_bits`), every element of `a` is routed to
`b` (bit = 0) or rotated in place (bit = 1) via `ra`; after each full pass,
`b` is flushed back into `a`. After `log2(n)` passes, `a` is sorted.

Because every bit position is always processed regardless of the input
arrangement, this algorithm's operation count depends only on `n` — it is
essentially insensitive to disorder, which is exactly the worst-case guarantee
O(n log n) is supposed to provide. This was confirmed empirically at n=200:
2468 ops for every tested pattern except the already-sorted case (sorted,
lightly shuffled, random, mostly reversed, fully reversed all cost the same).

Doubling n from 500 to 1000 multiplies ops by ~2.22x, matching the theoretical
`(1000·log₂1000)/(500·log₂500) ≈ 2.22x` for O(n log n).

### Adaptive

Selects Simple/Medium/Complex using the fixed disorder thresholds (0.2, 0.5)
from the subject. These thresholds were validated empirically, not just
assumed: at n=200, Simple wins clearly under 20% disorder (1054 vs 2530/2468
ops), and its cost grows sharply on random/mid-disorder inputs (5482 ops at
49% disorder), justifying the switch to Medium/Complex before that point.

One nuance worth noting: the disorder metric (pairs out of order) does not
always correlate with computational difficulty for a given implementation —
Simple performs surprisingly well on the fully-reversed case (disorder 100%,
597 ops) because of the shorter-rotation-direction optimization described
above. The thresholds still gate by disorder, as required, since the
guarantee needed is about worst-case behavior over all inputs at that disorder
level, not about any single favorable arrangement.

## Resources

- 42 push_swap subject (provided).
- [Wikipedia — Big-O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Wikipedia — Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Wikipedia — Sqrt decomposition](https://en.wikipedia.org/wiki/Sqrt_decomposition)

### AI usage

AI was used throughout development as a debugging and design
assistant, always reviewed and understood by both learners before being
applied:

- **Bug fixes**: identified and corrected an inverted condition in `print_op`
  that silenced stdout during `--bench`; a debug `ft_printf` in `simple.c` and
  `check_error` writing to stdout instead of stderr, which corrupted the
  operation stream read by the checker; a miscounted `ft_ss` operation
  (incrementing `sa`/`sb` instead of `ss`); and a memory leak in `main.c` on
  the `count < 2` early-return path (allocated `numbers` was never freed).
- **Feature design**: designed and implemented the `--bench` metrics output
  (`bench_print.c`, `bench_print_utils.c`), using `putstr_fd`/`putnbr_fd` to
  keep it on stderr exclusively.
- **Performance tuning**: built benchmark scripts (`bench_by_size.sh`,
  `bench_by_disorder.sh`) to empirically test strategies across sizes and
  disorder levels, and a Python simulation of the medium algorithm to search
  for the optimal chunk-size multiplier, used to justify the `group_size`
  choice documented above.
- **Testing methodology**: suggested the sequence of `valgrind` runs across
  edge cases (empty input, single element, duplicates, overflow, each forced
  strategy) that surfaced the `count < 2` leak.

All generated code and explanations were reviewed, tested, and are understood
by both learners; no code was copy-pasted without verification.