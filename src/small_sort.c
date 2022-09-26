/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:37:05 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/24 16:37:07 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	index_of_min(t_stack *a)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = a->value;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			index = i;
		}
		i++;
		a = a->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	i;

	i = index_of_min(*a);
	if (i == 1)
		sa(a);
	else if (i == 2)
	{
		rra(a);
		rra(a);
	}
	else if (i == 3)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	i;

	i = index_of_min(*a);
	if (i == 1)
		sa(a);
	else if (i == 2)
	{
		ra(a);
		ra(a);
	}
	else if (i == 3)
	{
		rra(a);
		rra(a);
	}
	else if (i == 4)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
