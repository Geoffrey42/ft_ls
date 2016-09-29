/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_stage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:30:38 by ggane             #+#    #+#             */
/*   Updated: 2016/09/29 17:54:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		files_list(t_list *files)
{
	t_data	*content;
	int		stop;

	while (files)
	{
		content = (t_data *)files->content;
		if (content->error == 20)
		{
			display_content(content);
			stop = 1;
		}
		files = files->next;
	}
	if (check_flags_for_new_line(content) && stop != 0)
	{
		//ft_putstr("---");
		ft_putchar('\n');
		//ft_putendl("1\n---");
	}
}

t_list		*display_only_directories(t_list *directories)
{
	t_data	*content;
	t_list	*recursive;

	content = (t_data *)directories->content;
	recursive = NULL;
	/*if (!ft_strcmp(content->name, "src"))
	{
		ft_putstr("first_call : ");
		ft_putnbr(content->first_call);
		ft_putchar('\n');
	}*/
	if (content->error == 13)
		display_permission_denied(content);
	else if (content->error != 20 && content->error != 2)
	{
		display_dir_title(content);
		if ((content->flags & LOW_L_FLAG) != 0)
			display_total_size(content);
		recursive = choose_recursive_infix_traversal(directories, recursive);
	}
	return (recursive);
}

void		initialize_first_call(t_list *list)
{
	t_list	*tmp;
	t_data	*content;

	tmp = list;
	content = NULL;
	while (tmp)	
	{
		content = (t_data *)tmp->content;
		content->first_call = 1;
		tmp = tmp->next;
	}
}

t_list		*directories_list(t_list *directories)
{
	t_list	*tmp;
	t_list	*recursive;
	t_data	*content;

	tmp = directories;
	recursive = NULL;
	content = NULL;
	while (tmp)
	{
		content = (t_data *)tmp->content;
		recursive = display_only_directories(tmp);
		if (recursive)
		{
			recursive_call(recursive);
			initialize_first_call(tmp);
		}
		/*ft_putendl("----");
		print_list(tmp);
		ft_putendl("----");*/
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
	display_unknow_files(files);
	files_list(files);
	directories_list(directories);
}
