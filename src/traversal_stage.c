/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_stage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:30:38 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 14:26:41 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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
	t_data	*tmp;
	t_list	*tmp_list;
	void	(*applyf)(void *);

	applyf = &display_content;
	tmp_list = directories;
	while (tmp_list)
	{
		tmp = (t_data *)tmp_list->content;
		if (tmp->nb_dir > 1)
			display_dir_title(tmp->name);
		choose_infix_traversal(tmp->flags, tmp->file, applyf);
		if (tmp_list->next)
			ft_putchar('\n');
		tmp_list = tmp_list->next;
	}
}
