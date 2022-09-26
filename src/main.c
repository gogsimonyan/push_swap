/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:38:47 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/24 16:38:48 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_args(char ***as)
{
	int	x;

	if (!as || !*as)
		return ;
	x = -1;
	while ((*as)[++x])
		free((*as)[x]);
	free(*as);
	*as = 0;
}

void	sort(t_stack **a, t_stack **b, char **arg_array)
{
	int	size;

	size = ft_list_size(*a);
	indexation(*a, size);
	push_swap(a, b, size);
	free_stack_memory(a);
	free_stack_memory(b);
	free_args(&arg_array);
}	

void	free_sorted_stack(char **arg_array, t_stack **a)
{
	free_args(&arg_array);
	free_stack_memory(a);
}

int	check_arguments_count(int count, char **arg_array)
{
	if (count < 2)
	{
		free_args(&arg_array);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arg_array;

	arg_array = recieve_argv(argv);
	count = recieve_argc(arg_array);
	if (argc == 1 || check_arguments_count(count, arg_array) == 0)
		return (0);
	if (validation(arg_array) == 0)
	{
		free_args(&arg_array);
		print_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill(count, arg_array);
	if (is_sorted(stack_a))
	{
		free_sorted_stack(arg_array, &stack_a);
		return (0);
	}
	sort(&stack_a, &stack_b, arg_array);
	return (0);
}
