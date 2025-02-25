/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:08 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/18 19:24:24 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	clear_stdin_buffer(char *op)
{
	while (op)
	{
		free(op);
		op = get_next_line(0);
	}
}

void	handle_error(t_stack **a, t_stack **b, char *op)
{
	free_stack(a);
	free_stack(b);
	clear_stdin_buffer(op);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
