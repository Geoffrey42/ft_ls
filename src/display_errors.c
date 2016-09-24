/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 20:05:21 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 23:24:06 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	zero_flags(t_list *error)
{
	t_data	*content;
	t_list	*tmp;

	tmp = error;
	content = (t_data *)tmp->content;
	while (tmp)
	{
		content->flags = 0;
		tmp = tmp->next;
	}
}

void	display_error_list(t_list *error)
{
	t_data	*content;

	content = NULL;
	while (error)
	{
		content = (t_data *)error->content;
		display_unknow_error_msg(content->name);
		error = error->next;
	}
}

void	display_unknow_error_msg(char *file)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	display_unknow_files(t_list *files)
{
	t_data	*content;
	t_list	*error;

	error = NULL;
	content = NULL;
	if (files)
	{
		while (files)
		{
			content = (t_data *)files->content;
			if (content->error == 2)
				ft_lstadd(&error, ft_lstnew(content, sizeof(t_data)));
			files = files->next;
		}
		zero_flags(error);
		merge_sort(&error);
		display_error_list(error);
	}
}

void	display_flag_error_msg(char bad_option)
{
	ft_putstr_fd("ls : illegal option -- ", 2);
	ft_putchar_fd(bad_option, 2);
	ft_putendl_fd("\nusage: ls [-Raltr] [file ...]", 2);
}
