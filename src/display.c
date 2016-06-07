/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:29:38 by ggane             #+#    #+#             */
/*   Updated: 2016/06/07 13:46:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	display_usage(void)
{
	ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
}

void	display_error_flag(char wrong_flag)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(wrong_flag, 2);
	ft_putchar_fd('\n', 2);
}
