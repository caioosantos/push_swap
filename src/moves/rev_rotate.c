/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:42 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:35:28 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack **a, int value)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *a;
	*a = last;
	if (value == 1)
		ft_printf("rra\n");
	update_index(*a);
}

void	ft_rrb(t_stack **b, int value)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *b;
	*b = last;
	if (value == 1)
		ft_printf("rrb\n");
	update_index(*b);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	ft_printf("rrr\n");
}
