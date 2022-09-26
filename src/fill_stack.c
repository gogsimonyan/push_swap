/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:35:20 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/24 16:35:22 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*fill(int argc, char **argv)
{
	t_stack		*stack_a;
	int			number;
	int			i;

	stack_a = NULL;
	number = 0;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		if ((number > 2147483647) || (number < -2147483647 -1))
			print_error(&stack_a, NULL);
		if (i == 1)
			stack_a = create_node(number);
		else
			insert_bottom(&stack_a, create_node((number)));
		i++;
	}
	return (stack_a);
}

int	*create_array(t_stack *node)
{
	int	array_length;
	int	i;
	int	*array;

	array_length = ft_list_size(node);
	array = (int *)malloc(array_length * sizeof(int));
	i = 0;
	while (node != NULL)
	{
		array[i] = node->value;
		node = (node)->next;
		i++;
	}
	return (array);
}

void	swap_values(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				s;

	s = 1;
	while (s == 1)
	{
		i = 1;
		s = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap_values(&tab[i - 1], &tab[i]);
				s = 1;
			}
			++i;
		}
	}
}

void	indexation(t_stack *stack_a, int stack_size)
{
	int	*num;
	int	y;

	num = create_array(stack_a);
	sort_int_tab(num, stack_size);
	while (stack_a != NULL)
	{
		y = 0;
		while (y < stack_size)
		{
			if (stack_a->value == num[y])
			{
				stack_a->index = y;
			}
			y++;
		}
		stack_a = stack_a->next;
	}
	free(num);
}
