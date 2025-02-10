/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:42 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/10 00:25:03 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	last = *a;
	while (last->next->next)
		last = last->next;
	*a = last->next;
	last->next = NULL;
	(*a)->next = temp;
}

void	do_rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}


