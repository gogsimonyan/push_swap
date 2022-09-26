/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:37:16 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/24 16:37:18 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	smallsort(t_stack **a, t_stack **b)
{
	int	size;

	if (ft_list_size(*a) == 0
		|| ft_list_size(*a) == 1)
		return ;
	size = ft_list_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

void	atob(t_stack **stack_a, t_stack **stack_b, int number)
{
	int	counter;

	counter = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if ((*stack_a)->index <= counter + number)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}

void	btoa(t_stack **a, t_stack **b)
{
	int		id;
	t_stack	*tmp;

	tmp = (*b);
	while ((*b) != NULL)
	{
		id = findmax(b);
		if (id > (ft_list_size(*b) - 1) / 2)
		{
			while ((*b)->index != ft_list_size(*b) - 1)
				rrb(b);
		}
		else
		{
			while ((*b)->index != ft_list_size(*b) - 1)
				rb(b);
		}
		pa(a, b);
		tmp = *b;
	}
}

void	butterfly(t_stack **a, t_stack **b)
{
	int	len;
	int	chunk;

	len = ft_list_size(*a);
	chunk = generate_chunk(len);
	atob(a, b, chunk);
	btoa(a, b);
}

void	push_swap(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size <= 5)
		smallsort(a, b);
	else
		butterfly(a, b);
}
