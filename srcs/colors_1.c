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

void	sa_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "sa", 2);
	write(1, END, ft_strlen(END));
}

void	sb_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "sb", 2);
	write(1, END, ft_strlen(END));
}

void	ss_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "ss", 2);
	write(1, END, ft_strlen(END));
}

void	pa_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "pa", 2);
	write(1, END, ft_strlen(END));
}

void	pb_color(void)
{
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "pb", 2);
	write(1, END, ft_strlen(END));
}
