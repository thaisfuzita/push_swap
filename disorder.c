int	ft_check_disorder(stack a)
{
	int	mistakes;
	int	total_pairs;
	int	size;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	size = ft_lstsize("stack a");
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < (size - 1))
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
		}
	}
	return (mistakes / total_pairs);
}