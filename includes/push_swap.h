/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:58:51 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/02/12 15:43:05 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	int				target_value;
	int				target_index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// moves
void	ft_pa(t_stack **a, t_stack **b, int value);
void	ft_pb(t_stack **a, t_stack **b, int value);
void	ft_sa(t_stack **a, int value);
void	ft_sb(t_stack **b, int value);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a, int value);
void	ft_rb(t_stack **b, int value);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a, int value);
void	ft_rrb(t_stack **b, int value);
void	ft_rrr(t_stack **a, t_stack **b);
void	update_index(t_stack *stack);

// check_args
int		is_valid_int(char *str);
int		check_dup(t_stack *stack, int val);
int		ft_get_args(t_stack **a, int ac, char **av);
void	free_arr(char **arr);

// init_stack
int		init_stack(t_stack **a, char **args);
void	free_stack(t_stack **stack);

// utils
int		ft_greater(int num1, int num2);
int		ft_stacksize(t_stack *stack);
int		find_index(t_stack *stack, int value);
int		find_cheaper(t_stack *stack);
void	handle_error(t_stack **a, t_stack **b);

// main
void	ft_small_sort(t_stack **a);
int		is_sorted(t_stack *stack);

// cost
void	calculate_cost_a(t_stack *a, t_stack *b);
void	calculate_cost_b(t_stack *a, t_stack *b);
int		calculate_steps(t_stack *stack, int index);

// push
void	push_to_a(t_stack **a, t_stack **b, int index);
void	push_to_b(t_stack **a, t_stack **b, int index);

#endif
