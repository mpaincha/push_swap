/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:31:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/17 18:31:35 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "rra", 3);
	write(1, END, ft_strlen(END));
}

void	rrb_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "rrb", 3);
	write(1, END, ft_strlen(END));
}

void	rrr_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "rrr", 3);
	write(1, END, ft_strlen(END));
}
