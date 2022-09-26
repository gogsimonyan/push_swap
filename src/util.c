/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:38:04 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/25 14:46:06 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*next_min(t_stack *a)
{
	int		head;
	t_stack	*node;
	t_stack	*min_node;

	min_node = NULL;
	head = 0;
	node = a;
	while (node)
	{
		if (node->index == -1 && (head == 0
				|| node->value < min_node->value))
		{
			head = 1;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

void	index_stack(t_stack **a)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = next_min(*a);
	while (head)
	{
		head->index = index++;
		head = next_min(*a);
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	is_sorted(t_stack *stack)
{
	if (!maxmincheck(stack))
	{
		print_error(NULL, NULL);
		return (0);
	}
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
