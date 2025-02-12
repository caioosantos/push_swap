/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:08 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:56:24 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

int	find_index(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

int	find_cheaper(t_stack *stack)
{
	int	cost;
	int	index;

	cost = stack->cost;
	index = stack->index;
	while (stack)
	{
		if (stack->cost < cost)
		{
			cost = stack->cost;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

int	calculate_steps(t_stack *stack, int index)
{
	int	steps;

	if (index <= (ft_stacksize(stack) - 1) / 2)
		steps = index;
	else
		steps = ft_stacksize(stack) - index;
	return (steps);
}

void	handle_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
