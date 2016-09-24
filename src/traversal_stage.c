/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_stage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:30:38 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 18:11:10 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list		*files_list(t_list *files)
{
	t_data	*content;

	while (files)
	{
		content = (t_data *)files->content;
		if (content->error == 20)
			display_content(content);
		files = files->next;
	}
	return (files);
}

void		display_only_directories(t_list *directories)
{
	t_data	*content;
	void	(*applyf)(void *);

	applyf = &display_content;
	content = (t_data *)directories->content;
	if (content->error != 20)
	{
		display_dir_title(content);
		choose_infix_traversal(content->flags, content->file, applyf);
	}
}

t_list		*directories_list(t_list *directories)
{
	t_list	*tmp;

	tmp = directories;
	while (tmp)
	{
		display_only_directories(tmp);
		display_new_line(tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void		choose_infix_traversal(
			int flags, t_btree *tree, void (*applyf)(void *))
{
	if ((flags & LOW_R_FLAG) != 0)
		btree_apply_rev_infix(tree, applyf);
	else
		btree_apply_infix(tree, applyf);
}

void		traversal_stage(t_list *directories)
{
	t_list	*files;

	files = directories;
	files_list(files);
	directories_list(directories);
}
