/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:39:39 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/24 21:23:03 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_total_cost(int index_a, int index_b, int size_a, int size_b)
{
	if (index_a <= (size_a - 1) / 2 && index_b <= (size_b - 1) / 2)
		return (ft_greater(index_a, index_b));
	else if (index_a > (size_a - 1) / 2 && index_b > (size_b - 1) / 2)
		return (ft_greater(size_a - index_a, size_b - index_b));
	else if (index_a <= (size_a - 1) / 2 && index_b > (size_b - 1) / 2)
		return (index_a + size_b - index_b);
	else
		return (size_a - index_a + index_b);
}

static int	define_target_b(t_stack *b, int value)
{
	int		closest_smaller;
	int		max;
	t_stack	*temp;

	closest_smaller = INT_MIN;
	max = INT_MIN;
	temp = b;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		if (temp->value < value && temp->value > closest_smaller)
			closest_smaller = temp->value;
		temp = temp->next;
	}
	if (closest_smaller != INT_MIN)
		return (closest_smaller);
	else
		return (max);
}

static int	define_target_a(t_stack *a, int value)
{
	int		closest_larger;
	int		min;
	t_stack	*temp;

	closest_larger = INT_MAX;
	min = INT_MAX;
	temp = a;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		if (temp->value > value && temp->value < closest_larger)
			closest_larger = temp->value;
		temp = temp->next;
	}
	if (closest_larger != INT_MAX)
		return (closest_larger);
	else
		return (min);
}

void	calculate_cost_a(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*temp;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	temp = a;
	while (temp)
	{
		temp->target_value = define_target_b(b, temp->value);
		temp->target_index = find_index(b, temp->target_value);
		temp->cost = calculate_total_cost(temp->index, temp->target_index, \
			size_a, size_b);
		temp = temp->next;
	}
}

void	calculate_cost_b(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*temp;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	temp = b;
	while (temp)
	{
		temp->target_value = define_target_a(a, temp->value);
		temp->target_index = find_index(a, temp->target_value);
		temp->cost = calculate_total_cost(temp->target_index, temp->index, \
			size_a, size_b);
		temp = temp->next;
	}
}
