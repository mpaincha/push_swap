/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:51:14 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/11 11:51:15 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		save_options(char opt, t_options *options)
{
	if (opt == 'n')
		options->n = 1;
	else if (opt == 'v')
		options->v = 1;
	else if (opt == 'c')
		options->c = 1;
	else if (opt == 'l')
		options->l = 1;
	else if (opt == 'i')
		options->i = 1;
}

int				verif_options(char *av, t_options *options)
{
	int			i;

	i = 1;
	if (av[0] == '-' && av[1])
	{
		while (av[i])
		{
			if (!(ft_strchr(OPTIONS, av[i])))
				return (0);
			save_options(av[i], options);
			i++;
		}
		return (1);
	}
	return (0);
}
