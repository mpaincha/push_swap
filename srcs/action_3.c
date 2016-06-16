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

void	ra(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->a)->length == 0)
		return ;
	act.name = ft_strdup("ra");
	to_move = (l->a)->tail;
	if ((l->a)->length > 1)
	{
		(l->a)->tail = (l->a)->tail->prev;
		(l->a)->tail->next = NULL;
		(l->a)->head->prev = to_move;
		to_move->next = (l->a)->head;
		(l->a)->head = to_move;
		to_move->prev = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rb(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->b)->length == 0)
		return ;
	act.name = ft_strdup("rb");
	to_move = (l->b)->tail;
	if ((l->b)->length > 1)
	{
		(l->b)->tail = (l->b)->tail->prev;
		(l->b)->tail->next = NULL;
		(l->b)->head->prev = to_move;
		to_move->next = (l->b)->head;
		(l->b)->head = to_move;
		to_move->prev = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rr(t_lst *l)
{
	t_act	act;
	int		act_ra;
	int		act_rb;

	act.name = NULL;
	act_ra = 0;
	act_rb = 0;
	if ((l->a)->length >= 1)
		act_ra = 1;
	if ((l->b)->length >= 1)
		act_rb = 1;
	if (act_ra != 0 || act_rb != 0)
		act.name = ft_strdup("rr");
	ra(l);
	rb(l);
	if (act_ra == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	if (act_rb == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}
