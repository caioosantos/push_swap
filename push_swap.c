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

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	lowest_to_top(t_stack **a)
{
	int		min_val;
	int		min_index;
	t_stack	*trav;

	update_index(*a);
	min_val = INT_MAX;
	trav = *a;
	while (trav)
	{
		if (trav->value < min_val)
		{
			min_val = trav->value;
			min_index = trav->index;
		}
		trav = trav->next;
	}
	if (min_index <= (ft_stacksize(*a) - 1) / 2)
		while ((*a)->value != min_val)
			ft_ra(a, 1);
	else
		while ((*a)->value != min_val)
			ft_rra(a, 1);
}

void	ft_small_sort(t_stack **a)
{
	if (ft_stacksize(*a) == 2 && !is_sorted(*a))
		ft_sa(a, 1);
	else if (ft_stacksize(*a))
	{
		if (is_sorted(*a))
			return ;
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 1);
		if (!is_sorted(*a))
			ft_rra(a, 1);
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 1);
	}
}

static void	ft_big_sort(t_stack **a, t_stack **b)
{
	int	index;

	if (ft_stacksize(*a) > 3 && !is_sorted(*a))
		ft_pb(a, b, 1);
	if (ft_stacksize(*a) > 3 && !is_sorted(*a))
		ft_pb(a, b, 1);
	while (ft_stacksize(*a) > 3 && !is_sorted(*a))
	{
		calculate_cost_a(*a, *b);
		index = find_cheaper(*a);
		push_to_b(a, b, index);
	}
	if (!is_sorted(*a))
		ft_small_sort(a);
	while (ft_stacksize(*b) > 0)
	{
		calculate_cost_b(*a, *b);
		index = find_cheaper(*b);
		push_to_a(a, b, index);
	}
	if (!is_sorted(*a))
		lowest_to_top(a);
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
			handle_error(&a, &b);
		if (!is_sorted(a))
		{
			if (ft_stacksize(a) <= 3)
				ft_small_sort(&a);
			else
				ft_big_sort(&a, &b);
		}
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	ft_pa(t_stack **a, t_stack **b, int value)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	if (value == 1)
		ft_printf("pa\n");
	update_index(*a);
	update_index(*b);
}

void	ft_pb(t_stack **a, t_stack **b, int value)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	if (value == 1)
		ft_printf("pb\n");
	update_index(*a);
	update_index(*b);
}

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

void	ft_ra(t_stack **a, int value)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (value == 1)
		ft_printf("ra\n");
	update_index(*a);
}

void	ft_rb(t_stack **b, int value)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (value == 1)
		ft_printf("rb\n");
	update_index(*b);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	ft_printf("rr\n");
}

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

int	calculate_total_cost(int index_a, int index_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (index_a <= (size_a - 1) / 2)
		cost_a = index_a;
	else
		cost_a = size_a - index_a;
	if (index_b <= (size_b - 1) / 2)
		cost_b = index_b;
	else
		cost_b = size_b - index_b;
	return (cost_a + cost_b);
}

static int	define_target_b(t_stack *b, int value)
{
	int		closest_smaller;
	int		max;
	t_stack	*trav;

	closest_smaller = INT_MIN;
	max = INT_MIN;
	trav = b;
	while (trav)
	{
		if (trav->value > max)
			max = trav->value;
		if (trav->value < value && trav->value > closest_smaller)
			closest_smaller = trav->value;
		trav = trav->next;
	}
	if (closest_smaller != INT_MIN)
		return (closest_smaller);
	else
		return (max);
}

static int	define_target_a(t_stack *a, int value)
{
	int		closest_larger;
	int		min;
	t_stack	*trav;

	closest_larger = INT_MAX;
	min = INT_MAX;
	trav = a;
	while (trav)
	{
		if (trav->value < min)
			min = trav->value;
		if (trav->value > value && trav->value < closest_larger)
			closest_larger = trav->value;
		trav = trav->next;
	}
	if (closest_larger != INT_MAX)
		return (closest_larger);
	else
		return (min);
}

void	calculate_cost_a(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*trav;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	trav = a;
	while (trav)
	{
		trav->target_value = define_target_b(b, trav->value);
		trav->target_index = find_index(b, trav->target_value);
		trav->cost = calculate_total_cost(trav->index, trav->target_index, \
			size_a, size_b);
		trav = trav->next;
	}
}

void	calculate_cost_b(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*trav;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	trav = b;
	while (trav)
	{
		trav->target_value = define_target_a(a, trav->value);
		trav->target_index = find_index(a, trav->target_value);
		trav->cost = calculate_total_cost(trav->target_index, trav->index, \
			size_a, size_b);
		trav = trav->next;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_valid_int(char *str)
{
	int		sign;
	long	result;

	if (!str || !*str)
		return (0);
	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		result = result * 10 + (*str - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (0);
		str++;
	}
	return (1);
}

int	check_dup(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_get_args(t_stack **a, int ac, char **av)
{
	int		i;
	char	*args;
	char	*temp;
	char	**arr;

	i = 2;
	args = ft_strdup(av[1]);
	while (i < ac)
	{
		temp = ft_strjoin(args, " ");
		free(args);
		args = ft_strjoin(temp, av[i]);
		free(temp);
		i++;
	}
	if (!args)
		return (0);
	arr = ft_split(args, ' ');
	free(args);
	if (!init_stack(a, arr))
	{
		free_arr(arr);
		return (0);
	}
	return (1);
}

static void	push_to_a_rr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		ft_rr(a, b);
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		ft_ra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rb(b, 1);
		steps_b--;
	}
}

static void	push_to_a_rrr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		ft_rrr(a, b);
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		ft_rra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rrb(b, 1);
		steps_b--;
	}
}

static void	push_to_a_rmrrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		ft_ra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rrb(b, 1);
		steps_b--;
	}
}

static void	push_to_a_rrmrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		ft_rra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rb(b, 1);
		steps_b--;
	}
}

void	push_to_a(t_stack **a, t_stack **b, int b_index)
{
	t_stack	*node;
	int		steps_a;
	int		steps_b;

	node = *b;
	while (node && node->index != b_index)
		node = node->next;
	steps_a = calculate_steps(*a, node->target_index);
	steps_b = calculate_steps(*b, b_index);
	if (node->target_index <= (ft_stacksize(*a) - 1) / 2
		&& b_index <= (ft_stacksize(*b) - 1) / 2)
		push_to_a_rr(a, b, steps_a, steps_b);
	else if (node->target_index > (ft_stacksize(*a) - 1) / 2
		&& b_index > (ft_stacksize(*b) - 1) / 2)
		push_to_a_rrr(a, b, steps_a, steps_b);
	else if (node->target_index <= (ft_stacksize(*a) - 1) / 2
		&& b_index > (ft_stacksize(*b) - 1) / 2)
		push_to_a_rmrrm(a, b, steps_a, steps_b);
	else
		push_to_a_rrmrm(a, b, steps_a, steps_b);
	ft_pa(a, b, 1);
	update_index(*a);
	update_index(*b);
}


static void	push_to_b_rr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		ft_rr(a, b);
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		ft_ra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rb(b, 1);
		steps_b--;
	}
}

static void	push_to_b_rrr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		ft_rrr(a, b);
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		ft_rra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rrb(b, 1);
		steps_b--;
	}
}

static void	push_to_b_rmrrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		ft_ra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rrb(b, 1);
		steps_b--;
	}
}

static void	push_to_b_rrmrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		ft_rra(a, 1);
		steps_a--;
	}
	while (steps_b)
	{
		ft_rb(b, 1);
		steps_b--;
	}
}

void	push_to_b(t_stack **a, t_stack **b, int a_index)
{
	t_stack	*node;
	int		steps_a;
	int		steps_b;

	node = *a;
	while (node && node->index != a_index)
		node = node->next;
	steps_a = calculate_steps(*a, a_index);
	steps_b = calculate_steps(*b, node->target_index);
	if (a_index <= (ft_stacksize(*a) - 1) / 2
		&& node->target_index <= (ft_stacksize(*b) - 1) / 2)
		push_to_b_rr(a, b, steps_a, steps_b);
	else if (a_index > (ft_stacksize(*a) - 1) / 2
		&& node->target_index > (ft_stacksize(*b) - 1) / 2)
		push_to_b_rrr(a, b, steps_a, steps_b);
	else if (a_index <= (ft_stacksize(*a) - 1) / 2
		&& node->target_index > (ft_stacksize(*b) - 1) / 2)
		push_to_b_rmrrm(a, b, steps_a, steps_b);
	else
		push_to_b_rrmrm(a, b, steps_a, steps_b);
	ft_pb(a, b, 1);
	update_index(*a);
	update_index(*b);
}

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

int	ft_greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

int	find_index(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

int	find_cheaper(t_stack *stack)
{
	int	cost;
	int	index;

	cost = stack->cost;
	index = stack->index;
	while (stack)
	{
		if (stack->cost < cost)
		{
			cost = stack->cost;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

int	calculate_steps(t_stack *stack, int index)
{
	int	steps;

	if (index <= (ft_stacksize(stack) - 1) / 2)
		steps = index;
	else
		steps = ft_stacksize(stack) - index;
	return (steps);
}

void	handle_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
