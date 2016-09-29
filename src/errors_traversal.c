/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_traversal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:06:03 by ggane             #+#    #+#             */
/*   Updated: 2016/09/25 11:09:15 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	zero_flags(t_list *error)
{
	t_data	*content;
	t_list	*tmp;

	tmp = error;
	while (tmp)
	{
		content = (t_data *)tmp->content;
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
