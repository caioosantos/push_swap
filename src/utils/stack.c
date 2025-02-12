/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:24:22 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:55:01 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

static t_stack	*new_stack_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->cost = 0;
	node->target_value = 0;
	node->target_index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	append_stack_node(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = *stack;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int	init_stack(t_stack **a, char **args)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			return (0);
		if (!check_dup(*a, ft_atoi(args[i])))
			return (0);
		new = new_stack_node(ft_atoi(args[i]), i);
		if (!new)
			return (0);
		append_stack_node(a, new);
		i++;
	}
	free_arr(args);
	return (1);
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
