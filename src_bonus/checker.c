/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:57:20 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/18 19:24:02 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	operation(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		ft_sa(a, 0);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ft_sb(b, 0);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ft_ss(a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		ft_pa(a, b, 0);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		ft_pb(a, b, 0);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ft_ra(a, 0);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		ft_rb(b, 0);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ft_rr(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		ft_rra(a, 0);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		ft_rrb(b, 0);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ft_rrr(a, b);
	else
		handle_error(a, b, op);
}

void	ft_checker(t_stack **a, t_stack **b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		operation(a, b, op);
		free(op);
		op = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (!ft_get_args(&a, ac, av))
			handle_error(&a, &b, NULL);
		ft_checker(&a, &b);
		if (is_sorted(a) && ft_stacksize(b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_stack(&a);
	free_stack(&b);
}
