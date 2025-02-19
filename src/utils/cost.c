/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:39:39 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/17 21:23:39 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_total_cost(int index_a, int index_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (index_a <= (size_a - 1) / 2)
		cost_a = index_a;
	else
		cost_a = size_a - index_a;
	if (index_b <= (size_b - 1) / 2)
		cost_b = index_b;
	else
		cost_b = size_b - index_b;
	return (cost_a + cost_b);
}

static int	define_target_b(t_stack *b, int value)
{
	int		closest_smaller;
	int		max;
	t_stack	*trav;

	closest_smaller = INT_MIN;
	max = INT_MIN;
	trav = b;
	while (trav)
	{
		if (trav->value > max)
			max = trav->value;
		if (trav->value < value && trav->value > closest_smaller)
			closest_smaller = trav->value;
		trav = trav->next;
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
	t_stack	*trav;

	closest_larger = INT_MAX;
	min = INT_MAX;
	trav = a;
	while (trav)
	{
		if (trav->value < min)
			min = trav->value;
		if (trav->value > value && trav->value < closest_larger)
			closest_larger = trav->value;
		trav = trav->next;
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
	t_stack	*trav;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	trav = a;
	while (trav)
	{
		trav->target_value = define_target_b(b, trav->value);
		trav->target_index = find_index(b, trav->target_value);
		trav->cost = calculate_total_cost(trav->index, trav->target_index, \
			size_a, size_b);
		trav = trav->next;
	}
}

void	calculate_cost_b(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*trav;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	trav = b;
	while (trav)
	{
		trav->target_value = define_target_a(a, trav->value);
		trav->target_index = find_index(a, trav->target_value);
		trav->cost = calculate_total_cost(trav->target_index, trav->index, \
			size_a, size_b);
		trav = trav->next;
	}
}
