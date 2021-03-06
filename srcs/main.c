/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:40:49 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/11 10:40:51 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_lst		l;
	t_options	options;

	ini_lst_empty(&l);
	ini_topt(&options);
	if (ac == 1)
		return (1);
	else
	{
		ini_lst(&l);
		if (!(recover(&l, &options, av)))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	algo(&l, &options);
	return (1);
}
