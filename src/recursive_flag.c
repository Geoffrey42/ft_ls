/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:36:09 by ggane             #+#    #+#             */
/*   Updated: 2016/09/21 23:14:08 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list	*create_new_dir_list(t_data *old_data, t_list *new_dir)
{
	t_data	*new_data;

	new_data = NULL;
	if (old_data->error == 0)
	{
		new_data = initialize_data_dir_first_call(old_data->pathname, old_data->pathname, old_data->flags);
		ft_lstadd(&new_dir, ft_lstnew(new_data, sizeof(t_data *)));
	}
	return (new_dir);
}

t_list	*reverse_recursive_infix(int flags, t_btree *root)
{
	t_data	*old_data;
	t_list	*new_dir;

	old_data = NULL;
	new_dir = NULL;
	if (is_empty(root))
	{
		old_data = (t_data *)root->item;
		regular_recursive_infix(root->right);
		display_content(root->item);
		new_dir = create_new_dir_list(old_data, new_dir);
		regular_recursive_infix(root->left);
	}
	return (new_dir);
}

t_list	*regular_recursive_infix(int flags, t_btree *root)
{
	t_data	*old_data;
	t_list	*new_dir;

	old_data = NULL;
	new_dir = NULL;
	if (is_empty(root))
	{
		old_data = (t_data *)root->item;
		regular_recursive_infix(root->left);
		new_dir = create_new_dir_list(old_data, new_dir);
		regular_recursive_infix(root->right);
	}
	return (new_dir);
}

t_list	*choose_recursive_infix_traversal(t_list *list)
{
	t_data	*data;

	data = (t_data *)list->content;
	if ((data->flags & LOW_R_FLAG) != 0)
		return (list = reverse_recursive_infix(data->flags, data->file));
	else
		return (list = regular_recursive_infix(data->flags, data->file));
}

t_list	*recursive_traversal_stage(t_list *directories)
{
	t_list	*new_dir;
	t_list	*tmp;

	new_dir = NULL;
	tmp = directories;
	while (tmp)
	{
		new_dir = choose_recursive_infix_traversal(tmp);
		tmp = tmp->next;
	}
	if (new_dir)
	{
		display_dir_title((char *)new_dir->content->name);
		new_dir = put_content_in_trees(new_dir);
	}
	return (directories);
}
