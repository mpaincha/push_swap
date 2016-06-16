/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:22:54 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/14 16:22:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	pivot_gap(t_pivot *pivot)
{
	if (pivot->upper >= pivot->lower)
		pivot->gap = pivot->upper - pivot->lower;
	else
		pivot->gap = pivot->lower - pivot->upper;
}

static	void	pivot_upper(t_lst *l, t_pivot *pivot)
{
	if ((int)(l->a)->length > pivot->lower)
		pivot->upper = (int)(l->a)->length - pivot->lower - 1;
	else
		pivot->upper = pivot->lower - (int)(l->a)->length - 1;
}

void			lst_pivot(t_lst *l)
{
	t_elem		*tmp;
	int			count;
	t_pivot		pivot;

	tmp = (l->a)->head;
	count = 0;
	ini_pivot(&pivot);
	pivot.pos = (l->a)->head;
	while (pivot.pos != NULL)
	{
		while (tmp != NULL)
		{
			if (tmp != pivot.pos && NB(tmp)->n < NB(pivot.pos)->n)
				pivot.lower++;
			tmp = tmp->next;
		}
		pivot_upper(l, &pivot);
		pivot_gap(&pivot);
		ft_lstdbladd(l->piv, &pivot, sizeof(t_pivot));
		pivot.pos = pivot.pos->next;
		pivot.lower = 0;
		pivot.upper = 0;
		pivot.gap = 0;
		tmp = (l->a)->head;
	}
}

int				which_pivot(t_lst *l, int value)
{
	t_elem	*tmp;
	t_elem	*pivot;

	tmp = l->piv->head;
	pivot = l->piv->head;
	while (tmp != NULL)
	{
		if (PIVOT(pivot)->gap > PIVOT(tmp)->gap)
			pivot = tmp;
		tmp = tmp->next;
	}
	if (value == 1)
		return (NB(PIVOT(pivot)->pos)->n);
	else
		return (PIVOT(pivot)->lower);
}
