/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:43:51 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:08:56 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_index(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
}
