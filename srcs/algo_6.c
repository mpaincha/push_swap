/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:22:54 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/14 16:22:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	more_effective_moving_b(t_lst *l, t_elem *elem, t_options *options)
{
	int		count;

	count = 0;
	if (which_side(&l->b, elem, &count) == 0)
	{
		while (count > 0)
		{
			rb(l);
			if (options->v == 1)
				show_piles(l, "rb");
			count--;
		}
	}
	else
	{
		count++;
		while (count > 0)
		{
			rrb(l);
			if (options->v == 1)
				show_piles(l, "rrb");
			count--;
		}
	}
}

void	more_effective_moving(t_lst *l, t_elem *elem, t_options *options)
{
	int		count;

	count = 0;
	if (which_side(&l->a, elem, &count) == 0)
	{
		while (count > 0)
		{
			ra(l);
			if (options->v == 1)
				show_piles(l, "ra");
			count--;
		}
	}
	else
	{
		while (1 + count > 0)
		{
			rra(l);
			if (options->v == 1)
				show_piles(l, "rra");
			count--;
		}
	}
}
