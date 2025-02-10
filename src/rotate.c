/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:21 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/10 00:25:05 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
}

void	do_ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	do_rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	do_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

