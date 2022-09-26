/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:41:41 by gsimonya          #+#    #+#             */
/*   Updated: 2022/09/25 14:47:04 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				id;
	long long		value;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill(int argc, char **argv);
t_stack		*get_bottom(t_stack *stack);
t_stack		*get_before_bottom(t_stack *stack);
t_stack		*create_node(int value);
t_stack		*next_min(t_stack *a);

int			maxmincheck(t_stack *a);
void		sort_three(t_stack **stack);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		insert_bottom(t_stack **stack, t_stack *new);
void		free_stack_memory(t_stack **stack);
void		ft_putstr(char *str);
void		print_error(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **src, t_stack **dest);
void		swap(t_stack *stack);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);
void		push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
void		sort_int_tab(int *tab, unsigned int size);
void		swap_values(int *a, int *b);
void		indexation(t_stack *stack_a, int stack_size);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_free(char **str);
void		ft_free2(int **num);
void		mainsort(t_stack **a, t_stack **b);
void		index_stack(t_stack **a);
void		atob(t_stack **stack_a, t_stack **stack_b, int number);
void		btoa(t_stack **stack_a, t_stack **stack_b);
void		butterfly(t_stack **a, t_stack **b);
void		identification(t_stack **stack);
void		sort_five(t_stack **a, t_stack **b);
void		sort_four(t_stack **a, t_stack **b);
void		smallsort(t_stack **a, t_stack **b);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_list_size(t_stack	*stack);
int			is_sorted(t_stack *stack);
int			abs(int nb);
int			validation(char **argv);
int			is_digit(char c);
int			is_sign(char c);
int			ft_strcmp(const char *s1, const char *s2);
__int128_t	ft_atoi(const char *str);
int			find_highest_index(t_stack *stack);
int			*create_array(t_stack *node);
int			count_strings(char const *s, char c);
int			recieve_argc(char **argv);
int			arg_is_number(char *argv);
int			have_duplicates(char **argv);
int			arg_is_zero(char *argv);
int			max_min_check(t_stack *a);
int			findmax(t_stack **stack);
int			generate_chunk(int size);
int			generate_chunk(int size);
int			index_of_min(t_stack *a);
int			a(char **av, int i);

char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);

char		**ft_split(char const *s, char c);
char		**recieve_argv(char	**argv);

#endif
