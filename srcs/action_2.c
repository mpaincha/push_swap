/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:25:45 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/11 16:25:48 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pa_src(t_dbllist *lst)
{
	if (lst->length == 1)
	{
		lst->tail = NULL;
		lst->head = NULL;
	}
	else
	{
		lst->tail = lst->tail->prev;
		lst->tail->next = NULL;
	}
	lst->length--;
}

static void	pa_dst(t_dbllist *lst, t_elem *to_move)
{
	if (lst->length >= 1)
	{
		lst->tail->next = to_move;
		to_move->prev = lst->tail;
		lst->tail = to_move;
	}
	else
	{
		to_move->prev = NULL;
		lst->tail = to_move;
		lst->head = to_move;
	}
	lst->length++;
}

void		pa(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = (l->b)->tail;
	act.name = ft_strdup("pa");
	pa_src(l->b);
	pa_dst(l->a, to_move);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void		pb(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = (l->a)->tail;
	act.name = ft_strdup("pb");
	pa_src(l->a);
	pa_dst(l->b, to_move);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}
