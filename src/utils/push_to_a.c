/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:40:14 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/17 21:23:47 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_a_rr(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

static void	push_to_a_rrr(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

static void	push_to_a_rmrrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

static void	push_to_a_rrmrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

void	push_to_a(t_stack **a, t_stack **b, int b_index)
{
	t_stack	*node;
	int		steps_a;
	int		steps_b;

	node = *b;
	while (node && node->index != b_index)
		node = node->next;
	steps_a = calculate_steps(*a, node->target_index);
	steps_b = calculate_steps(*b, b_index);
	if (node->target_index <= (ft_stacksize(*a) - 1) / 2
		&& b_index <= (ft_stacksize(*b) - 1) / 2)
		push_to_a_rr(a, b, steps_a, steps_b);
	else if (node->target_index > (ft_stacksize(*a) - 1) / 2
		&& b_index > (ft_stacksize(*b) - 1) / 2)
		push_to_a_rrr(a, b, steps_a, steps_b);
	else if (node->target_index <= (ft_stacksize(*a) - 1) / 2
		&& b_index > (ft_stacksize(*b) - 1) / 2)
		push_to_a_rmrrm(a, b, steps_a, steps_b);
	else
		push_to_a_rrmrm(a, b, steps_a, steps_b);
	ft_pa(a, b, 1);
	update_index(*a);
	update_index(*b);
}
