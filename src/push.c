/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:45:17 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/10 00:24:56 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a; // temp recebe a pilha de A
	*a = *b; // A aponta para B
	*b = (*b)->next; // B aponta para o proximo de B
	(*a)->next = temp; // O proximo de A aponta para Temp(pilha de A)
}

void	do_pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	do_pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
}

