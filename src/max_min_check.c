/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:36:10 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/25 14:58:45 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	maxmincheck(t_stack *a)
{
	t_stack	*temp;
	t_stack	*b;

	temp = a;
	while (a != NULL)
	{
		if (a->value > 2147483647 || a->value < -2147483648)
			return (0);
		a = a->next;
	}
	a = temp;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (b->value == a->value)
				return (0);
			b = b->next;
		}
		a = a->next;
	}
	return (1);
}

int	a(char **av, int i)
{
	if (av[i][0] != '-' && ft_strcmp("2147483647", av[i]) < 0
			&& ft_strlen(av[i]) >= 10)
		return (0);
	if (av[i][0] == '-' && ft_strcmp("-2147483648", av[i]) < 0
			&& ft_strlen(av[i]) >= 11)
		return (0);
	return (1);
}
