/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:22:00 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/11 12:22:01 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			which_tri(int tri)
{
	if (tri == 1)
		ft_printf("\nSorting method used : Basic Swap\n");
	else if (tri == 2)
		ft_printf("\nSorting method used : Selection Sort\n");
	else if (tri == 3)
		ft_printf("\nSorting method used : Merge Sort\n");
	else if (tri == 4)
		ft_printf("\nSorting method used : Just one inversion\n");
}
