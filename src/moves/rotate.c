/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:21 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:35:51 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **a, int value)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (value == 1)
		ft_printf("ra\n");
	update_index(*a);
}

void	ft_rb(t_stack **b, int value)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (value == 1)
		ft_printf("rb\n");
	update_index(*b);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	ft_printf("rr\n");
}
