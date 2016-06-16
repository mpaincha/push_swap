/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:22:54 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/14 16:22:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_elem	*find_min(t_dbllist **pile)
{
	t_elem	*tmp;
	t_elem	*min;

	tmp = NULL;
	min = NULL;
	if ((*pile)->length < 1)
		return (NULL);
	tmp = (*pile)->head;
	min = (*pile)->head;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && NB(min)->n > NB(tmp->next)->n)
			min = tmp->next;
		tmp = tmp->next;
	}
	return (min);
}

int		which_side(t_dbllist **pile, t_elem *elem, int *count)
{
	t_elem	*tmp_head;
	t_elem	*tmp_tail;
	int		count_head;
	int		count_tail;

	tmp_head = (*pile)->head;
	tmp_tail = (*pile)->tail;
	count_head = 0;
	count_tail = 0;
	while (tmp_head != NULL && tmp_head != elem)
	{
		count_head++;
		tmp_head = tmp_head->next;
	}
	count_tail = (*pile)->length - 1 - count_head;
	if (count_head >= count_tail)
		*count = count_tail;
	else
		*count = count_head;
	return (count_head >= count_tail) ? 0 : 1;
}

void	tri_simple(t_lst *l, t_options *options, int *tri)
{
	while ((l->a)->length > 0)
	{
		more_effective_moving(l, find_min(&l->a), options);
		pb(l);
		if (options->v == 1)
			show_piles(l, "pb");
	}
	while ((l->b)->length > 0)
	{
		pa(l);
		if (options->v == 1)
			show_piles(l, "pa");
	}
	*tri = 2;
}

void	algo(t_lst *l, t_options *options)
{
	int		tri;

	tri = 0;
	if (l->a->length > 1)
	{
		while (!(is_sorted(l->a)))
		{
			if ((l->a)->length <= 19)
			{
				if ((l->a)->length == 3 && is_reversed(l->a) == 1)
					be_almost_sorted_2(l, options, &tri);
				else if (!(a_is_almost_sorted(l, options, &tri)))
					tri_simple(l, options, &tri);
			}
			else if (!(a_is_almost_sorted(l, options, &tri)))
				tri_quicksort(l, options, &tri);
		}
	}
	if (l->a->length != 0)
		display(l, options, tri);
}
