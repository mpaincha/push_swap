/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:51:14 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/11 11:51:15 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int		findn(int n, t_dbllist *a)
{
	t_elem	*tmp;

	tmp = a->head;
	while (tmp != NULL)
	{
		if (NB(tmp)->check == 0 && n == NB(tmp)->n)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int				verif_dup(t_dbllist **a)
{
	t_elem	*tmp;

	tmp = (*a)->head;
	while (tmp != NULL)
	{
		NB(tmp)->check = 1;
		if (findn(NB(tmp)->n, *a) == 1)
			return (0);
		NB(tmp)->check = 0;
		tmp = tmp->next;
	}
	return (1);
}

int				verif_limits(char *av)
{
	if (INT_MIN > ft_atoi_intmax(av) || ft_atoi_intmax(av) > INT_MAX)
		return (0);
	return (1);
}

int				verif_digit(char *av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (i == 0 && av[i] == '-')
		{
			if (av[i + 1] && ft_isdigit(av[i + 1]))
				i++;
			else
				return (0);
		}
		else if (!(ft_isdigit(av[i])))
			return (0);
		else
			i++;
	}
	return (1);
}
