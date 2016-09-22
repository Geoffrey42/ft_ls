/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_stage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:30:38 by ggane             #+#    #+#             */
/*   Updated: 2016/09/22 14:03:09 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		choose_infix_traversal
			(int flags, t_btree *tree, void (*applyf)(void *))	
{
	if ((flags & LOW_R_FLAG) != 0)
		btree_apply_rev_infix(tree, applyf);
	else
		btree_apply_infix(tree, applyf);
}

void		display_content(void *item)
{
	t_data	*data;

	data = (t_data *)item;
	if (data->error == 0 && data->name[0] != '.')
	{
		ft_putstr(data->name);
		ft_putendl(" -- est un dossier");
	}
	else if (data->error != 0 && data->name[0] != '.')
		ft_putendl(data->name);
}

/*t_list		*traversal_stage(t_list *directories)
{
	t_data	*tmp;
	t_list	*tmp_list;
	void	(*applyf)(void *);

	applyf = &display_content;
	tmp_list = directories;
	while (tmp_list)
	{
		tmp = (t_data *)tmp_list->content;
		display_dir_title(tmp->pathname);
		choose_infix_traversal(tmp->flags, tmp->file, applyf);
		tmp_list = tmp_list->next;
	}
	return (directories);
}*/

void		traversal_stage(t_list *directories)
{
	t_data	*tmp;
	t_list	*tmp_list;
	void	(*applyf)(void *);

	applyf = &display_content;
	tmp_list = directories;
	while (tmp_list)
	{
		tmp = (t_data *)tmp_list->content;
		display_dir_title(tmp->pathname);
		choose_infix_traversal(tmp->flags, tmp->file, applyf);
		tmp_list = tmp_list->next;
	}
}

void		display_dir_title(char *name)
{
	ft_putchar('\n');
	ft_putstr(name);
	ft_putendl(":");
}
