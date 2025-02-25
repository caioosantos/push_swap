/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:58:06 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/24 20:32:53 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// moves
void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **a, t_stack **b);

// get_args
int		ft_get_args(t_stack **a, int ac, char **av);
int		free_arr(char **arr);
int		is_valid_int(char *str);
int		check_dup(t_stack *stack, int val);

// stack
int		init_stack(t_stack **a, char **args);
int		ft_stacksize(t_stack *stack);

// utils
void	handle_error(t_stack **a, t_stack **b, char *op);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);

#endif
