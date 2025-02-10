/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:58:10 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/10 00:29:37 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **a)
{
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	do_sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	do_sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
