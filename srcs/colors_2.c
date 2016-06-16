/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:31:39 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/17 18:31:40 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "ra", 2);
	write(1, END, ft_strlen(END));
}

void	rb_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "rb", 2);
	write(1, END, ft_strlen(END));
}

void	rr_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "rr", 2);
	write(1, END, ft_strlen(END));
}
