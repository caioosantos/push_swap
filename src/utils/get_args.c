/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:42 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 13:55:43 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_valid_int(char *str)
{
	int		sign;
	long	result;

	if (!str || !*str)
		return (0);
	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		result = result * 10 + (*str - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (0);
		str++;
	}
	return (1);
}

int	check_dup(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_get_args(t_stack **a, int ac, char **av)
{
	int		i;
	char	*args;
	char	*temp;
	char	**arr;

	i = 2;
	args = ft_strdup(av[1]);
	while (i < ac)
	{
		temp = ft_strjoin(args, " ");
		free(args);
		args = ft_strjoin(temp, av[i]);
		free(temp);
		i++;
	}
	if (!args)
		return (0);
	arr = ft_split(args, ' ');
	free(args);
	if (!init_stack(a, arr))
	{
		free_arr(arr);
		return (0);
	}
	return (1);
}
