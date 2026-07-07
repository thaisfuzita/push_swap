int	ft_check_disorder(stack a) //verifica a desordem da stack
{
	int	mistakes;
	int	total_pairs;
	int	size;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	size = ft_lstsize(t_stack a); //provavelmente esta errado
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
	return (mistakes / total_pairs); //retorna a media de desordem
	//desordem 1 totalmente desordenado
	//desordem 0 totalmente ordenado
}