#include "push_swap.h"

static void	change_top_bot(t_stack *x, t_node *new)
{
	x->top = new;
	x->bottom = new;
}

t_stack	*init_stack(int *values, int count)
{
	t_stack	*s;
	t_node	*new_node;

	int		i;
	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
	i = 0;
	while (i < count)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->value = values[i];
		new_node->next = NULL;
		new_node->prev = NULL;
		if (s->bottom == NULL)
			change_top_bot(s, new_node);
		else
		{
			s->bottom->next = new_node;
			new_node->prev = s->bottom;
			s->bottom = new_node;
		}
		s->size++;
		i++;
	}
	return (s);
}

void	print_stack(t_stack *s, char *name)
{
	t_node	*current;

	current = s->top;
	if (current)
	{
		ft_printf("%s: ", name);
		while (current)
		{
			ft_printf("%d", current->value);
			current = current->next;
			if (current)
				ft_printf("%c", ' ');
		}
		ft_printf("\n");
	}
}

/*
** Conversao simples de argv para int, SEM validacao completa
** (is_valid_number, is_overflow, is_duplicate) -- isso e so pro
** tester local, nao para o push_swap final que sera entregue.
*/
static int	*args_to_values(char **argv, int count)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * count);
	if (!values)
		return (NULL);
	i = 0;
	while (i < count)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (values);
}

static void	print_both(t_stack *a, t_stack *b)
{
	print_stack(a, "A");
	print_stack(b, "B");
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*values;
	int		count;
	t_bench bench;

	if (argc < 2)
	{
		ft_printf("uso: %s numero1 numero2 ...\n", argv[0]);
		return (1);
	}
	ft_bzero(&bench, sizeof(t_bench));
	count = argc - 1;
	values = args_to_values(argv, count);
	if (!values)
		return (1);
	a = init_stack(values, count);
	b = init_stack(NULL, 0);
	free(values);
	if (!a || !b)
		return (1);

	ft_printf("--- estado inicial ---\n");
	print_both(a, b);

	/* Edite essa sequencia livremente para testar o que quiser */

	ft_printf("--- exec sa ---\n");
	ft_sa(a, &bench);
	print_both(a, b);

	ft_printf("--- exec pb ---\n");
	ft_pb(a, b, &bench);
	print_both(a, b);

	ft_printf("--- exec pb ---\n");
	ft_pb(a, b, &bench);
	print_both(a, b);

	ft_printf("--- exec pb ---\n");
	ft_pb(a, b, &bench);
	print_both(a, b);

	ft_printf("--- exec rr ---\n");
	ft_rr(a, b, &bench);
	print_both(a, b);

	ft_printf("--- exec r_rr ---\n");
	ft_r_rr(a, b, &bench);
	print_both(a, b);

	ft_printf("--- exec pa ---\n");
	ft_pa(a, b, &bench);
	print_both(a, b);

	ft_printf("Total ops: %d\n", bench.total_ops);

	return (0);
}
