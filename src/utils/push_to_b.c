/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:41:06 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/17 21:23:46 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_b_rr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		ft_rr(a, b);
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		ft_ra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rb(b, 1);
		steps_b--;
	}
}

static void	push_to_b_rrr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		ft_rrr(a, b);
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		ft_rra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rrb(b, 1);
		steps_b--;
	}
}

static void	push_to_b_rmrrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		ft_ra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rrb(b, 1);
		steps_b--;
	}
}

static void	push_to_b_rrmrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		ft_rra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rb(b, 1);
		steps_b--;
	}
}

void	push_to_b(t_stack **a, t_stack **b, int a_index)
{
	t_stack	*node;
	int		steps_a;
	int		steps_b;

	node = *a;
	while (node && node->index != a_index)
		node = node->next;
	steps_a = calculate_steps(*a, a_index);
	steps_b = calculate_steps(*b, node->target_index);
	if (a_index <= (ft_stacksize(*a) - 1) / 2
		&& node->target_index <= (ft_stacksize(*b) - 1) / 2)
		push_to_b_rr(a, b, steps_a, steps_b);
	else if (a_index > (ft_stacksize(*a) - 1) / 2
		&& node->target_index > (ft_stacksize(*b) - 1) / 2)
		push_to_b_rrr(a, b, steps_a, steps_b);
	else if (a_index <= (ft_stacksize(*a) - 1) / 2
		&& node->target_index > (ft_stacksize(*b) - 1) / 2)
		push_to_b_rmrrm(a, b, steps_a, steps_b);
	else
		push_to_b_rrmrm(a, b, steps_a, steps_b);
	ft_pb(a, b, 1);
	update_index(*a);
	update_index(*b);
}
