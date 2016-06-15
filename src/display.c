/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:41:36 by ggane             #+#    #+#             */
/*   Updated: 2016/06/15 09:31:25 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	display_flags_error_msg(char bad_option)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(bad_option, 2);
	ft_putendl_fd("\nusage: ls [-Raltr] [file ...]", 2);
}
