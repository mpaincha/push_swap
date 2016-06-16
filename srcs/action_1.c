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

void	sa(t_lst *l)
{
	t_elem	*tmp;
	int		copy;
	t_act	act;

	tmp = (l->a)->tail;
	act.name = NULL;
	copy = 0;
	if ((l->a)->length <= 1)
		return ;
	else
	{
		act.name = ft_strdup("sa");
		copy = NB(tmp)->n;
		NB(tmp)->n = NB(tmp->prev)->n;
		NB(tmp->prev)->n = copy;
		ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
	}
}

void	sb(t_lst *l)
{
	t_elem	*tmp;
	int		copy;
	t_act	act;

	tmp = (l->b)->tail;
	act.name = NULL;
	copy = 0;
	if ((l->b)->length <= 1)
		return ;
	else
	{
		act.name = ft_strdup("sb");
		copy = NB(tmp)->n;
		NB(tmp)->n = NB(tmp->prev)->n;
		NB(tmp->prev)->n = copy;
		ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
	}
}

void	ss(t_lst *l)
{
	t_act	act;
	int		act_sa;
	int		act_sb;

	act.name = NULL;
	act_sa = 0;
	act_sb = 0;
	if ((l->a)->length > 1)
		act_sa = 1;
	if ((l->b)->length > 1)
		act_sb = 1;
	if (act_sa != 0 || act_sb != 0)
		act.name = ft_strdup("ss");
	else
		return ;
	sa(l);
	sb(l);
	if (act_sa == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	if (act_sb == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}
