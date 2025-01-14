/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:24:30 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/04 19:42:05 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	valid_argument(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	data_validation(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	if (!ft_isdigit(num[i]))
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**initialize_args(int argc, char *argv[], int *start_index)
{
	char	**args;

	*start_index = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		*start_index = 1;
		args = argv;
	}
	return (args);
}

static int	validate_args(char **args, int start_index)
{
	long	tmp;
	int		i;

	i = start_index;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!data_validation(args[i]))
			return (0);
		if (valid_argument(tmp, args, i))
			return (0);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	input_validation(int argc, char *argv[])
{
	char	**args;
	int		i;
	int		result;

	args = initialize_args(argc, argv, &i);
	if (args[1] == NULL)
		return (0);
	if (!args)
		return (0);
	result = validate_args(args, i);
	if (argc == 2)
		free_split(args);
	return (result);
}
