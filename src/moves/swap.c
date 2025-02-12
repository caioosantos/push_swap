/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:58:10 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:36:28 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack **a, int value)
{
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (value == 1)
		ft_printf("sa\n");
	update_index(*a);
}

void	ft_sb(t_stack **b, int value)
{
	t_stack	*temp;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (value == 1)
		ft_printf("sb\n");
	update_index(*b);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	ft_printf("ss\n");
}
