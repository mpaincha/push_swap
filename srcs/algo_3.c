/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:22:54 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/14 16:22:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		separate_lst(t_lst *l, int pivot, t_options *options)
{
	t_elem	*tmp;
	int		count;

	(void)pivot;
	(void)options;
	tmp = (l->a)->tail;
	count = (l->a)->length;
	while (count > 0)
	{
		if (NB(tmp)->n < pivot)
			pb(l);
		else
			ra(l);
		count--;
		tmp = (l->a)->tail;
	}
}

static	int		define_pivot(t_lst *l)
{
	lst_pivot(l);
	return (which_pivot(l, 1));
}

void			tri_quicksort(t_lst *l, t_options *options, int *tri)
{
	int		value_pivot;

	(void)options;
	value_pivot = define_pivot(l);
	separate_lst(l, value_pivot, options);
	if (!(is_sorted(l->a)))
		tri_a(l, options);
	if (!(is_reversed(l->b)))
		tri_b(l, options);
	while (l->b->length > 0)
	{
		pa(l);
		if (options->v == 1)
			show_piles(l, "pa");
	}
	*tri = 3;
}

int				is_sorted(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->head;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && NB(tmp)->n < NB(tmp->next)->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				is_reversed(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->head;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && NB(tmp)->n > NB(tmp->next)->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
