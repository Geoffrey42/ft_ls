/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 20:05:21 by ggane             #+#    #+#             */
/*   Updated: 2016/09/30 11:39:29 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_permission_denied(t_data *content)
{
	display_dir_title(content);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(content->name, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void	display_unknow_error_msg(char *file)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	display_flag_error_msg(char bad_option)
{
	ft_putstr_fd("ls : illegal option -- ", 2);
	ft_putchar_fd(bad_option, 2);
	ft_putendl_fd("\nusage: ls [-Raltr] [file ...]", 2);
}
