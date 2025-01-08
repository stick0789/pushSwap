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

static int	valid_argument(int num, char **argv, int i)
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

void	input_validation(int argc, char *argv[])
{
	char	**args;
	long	tmp;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i =  1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!data_validation(args[i]))
			ft_putstr_fd("Error\n", 2);
		if (valid_argument(tmp, args, i))
			ft_putstr_fd("Error\n", 2);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	if (argc == 2)
		free_split(args);
}
