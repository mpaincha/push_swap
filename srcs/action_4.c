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

void	rra(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->a)->length == 0)
		return ;
	act.name = ft_strdup("rra");
	to_move = (l->a)->head;
	if ((l->a)->length > 1)
	{
		(l->a)->head = (l->a)->head->next;
		(l->a)->head->prev = NULL;
		(l->a)->tail->next = to_move;
		to_move->prev = (l->a)->tail;
		(l->a)->tail = to_move;
		to_move->next = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rrb(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->b)->length == 0)
		return ;
	act.name = ft_strdup("rrb");
	to_move = (l->b)->head;
	if ((l->b)->length > 1)
	{
		(l->b)->head = (l->b)->head->next;
		(l->b)->head->prev = NULL;
		(l->b)->tail->next = to_move;
		to_move->prev = (l->b)->tail;
		(l->b)->tail = to_move;
		to_move->next = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rrr(t_lst *l)
{
	t_act	act;
	int		act_rra;
	int		act_rrb;

	act.name = NULL;
	act_rra = 0;
	act_rrb = 0;
	if ((l->a)->length >= 1)
		act_rra = 1;
	if ((l->b)->length >= 1)
		act_rrb = 1;
	if (act_rra != 0 || act_rrb != 0)
		act.name = ft_strdup("rrr");
	rra(l);
	rrb(l);
	if (act_rra == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	if (act_rrb == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}
