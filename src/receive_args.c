/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:36:35 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/24 16:36:37 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_memory(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = 0;
}

char	**recieve_argv(char **argv)
{
	char	**arr;
	int		i;
	char	*str;
	char	*s1;

	i = -1;
	while (argv[++i])
	{
		if (i == 0)
			str = ft_strjoin(argv[i], " ");
		else
		{
			s1 = str;
			str = ft_strjoin(str, argv[i]);
			free_memory(&s1);
			s1 = str;
			str = ft_strjoin(str, " ");
			free_memory(&s1);
		}
	}
	arr = ft_split(str, ' ');
	free_memory(&str);
	return (arr);
}

int	recieve_argc(char **argv)
{
	int		i;
	char	*str;
	int		argc;
	char	*s1;

	i = 0;
	while (argv[i])
	{
		if (i == 0)
			str = ft_strjoin(argv[i], " ");
		else
		{
			s1 = str;
			str = ft_strjoin(str, argv[i]);
			free_memory(&s1);
			s1 = str;
			str = ft_strjoin(str, " ");
			free_memory(&s1);
		}
		i++;
	}
	argc = count_strings(str, ' ');
	free_memory(&str);
	return (argc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sublen;
	char	*r;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	sublen = ft_strlen(s + start);
	if (sublen < len)
		len = sublen;
	r = malloc((len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s + start, len + 1);
	return (r);
}

int	validation(char **argv)
{
	int	t;
	int	i;
	int	countofzeros;

	t = 0;
	countofzeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		countofzeros += arg_is_zero(argv[i]);
		if (a(argv, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
