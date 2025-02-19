/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:07:16 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/17 21:23:48 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	lowest_to_top(t_stack **a)
{
	int		min_val;
	int		min_index;
	t_stack	*trav;

	update_index(*a);
	min_val = INT_MAX;
	trav = *a;
	while (trav)
	{
		if (trav->value < min_val)
		{
			min_val = trav->value;
			min_index = trav->index;
		}
		trav = trav->next;
	}
	if (min_index <= (ft_stacksize(*a) - 1) / 2)
		while ((*a)->value != min_val)
			ft_ra(a, 1);
	else
		while ((*a)->value != min_val)
			ft_rra(a, 1);
}

void	ft_small_sort(t_stack **a)
{
	if (ft_stacksize(*a) == 2 && !is_sorted(*a))
		ft_sa(a, 1);
	else if (ft_stacksize(*a))
	{
		if (is_sorted(*a))
			return ;
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 1);
		if (!is_sorted(*a))
			ft_rra(a, 1);
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 1);
	}
}

static void	ft_big_sort(t_stack **a, t_stack **b)
{
	int	index;

	if (ft_stacksize(*a) > 3 && !is_sorted(*a))
		ft_pb(a, b, 1);
	if (ft_stacksize(*a) > 3 && !is_sorted(*a))
		ft_pb(a, b, 1);
	while (ft_stacksize(*a) > 3 && !is_sorted(*a))
	{
		calculate_cost_a(*a, *b);
		index = find_cheaper(*a);
		push_to_b(a, b, index);
	}
	if (!is_sorted(*a))
		ft_small_sort(a);
	while (ft_stacksize(*b) > 0)
	{
		calculate_cost_b(*a, *b);
		index = find_cheaper(*b);
		push_to_a(a, b, index);
	}
	if (!is_sorted(*a))
		lowest_to_top(a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (!ft_get_args(&a, ac, av))
			handle_error(&a, &b);
		if (!is_sorted(a))
		{
			if (ft_stacksize(a) <= 3)
				ft_small_sort(&a);
			else
				ft_big_sort(&a, &b);
		}
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
