/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:22:54 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/14 16:22:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_elem	*find_max(t_dbllist **pile)
{
	t_elem	*tmp;
	t_elem	*max;

	tmp = NULL;
	max = NULL;
	if ((*pile)->length < 1)
		return (NULL);
	tmp = (*pile)->head;
	max = (*pile)->head;
	while (tmp != NULL)
	{
		if (NB(max)->n < NB(tmp)->n)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void			tri_a(t_lst *l, t_options *options)
{
	int		count;

	count = 0;
	while ((l->a)->length > 0)
	{
		more_effective_moving(l, find_min(&l->a), options);
		pb(l);
		count++;
		if (options->v == 1)
			show_piles(l, "pb");
	}
	while (count > 0)
	{
		pa(l);
		if (options->v == 1)
			show_piles(l, "pa");
		count--;
	}
}

void			tri_b(t_lst *l, t_options *options)
{
	int		count;

	count = 0;
	while ((l->b)->length > 0)
	{
		more_effective_moving_b(l, find_max(&l->b), options);
		pa(l);
		count++;
		if (options->v == 1)
			show_piles(l, "pa");
	}
	while (count > 0)
	{
		pb(l);
		if (options->v == 1)
			show_piles(l, "pb");
		count--;
	}
}
