/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 20:05:21 by ggane             #+#    #+#             */
/*   Updated: 2016/09/06 20:09:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    display_flag_error_msg(char bad_option)
{
    ft_putstr_fd("ls : illegal option -- ", 2);
    ft_putchar_fd(bad_option, 2);
    ft_putendl_fd("\nusage: ls [-Raltr] [file ...]", 2);
}
