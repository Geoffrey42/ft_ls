/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:36:09 by ggane             #+#    #+#             */
/*   Updated: 2016/09/28 20:31:35 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	add_data_to_list(t_data *old_data, t_list **new_dir)
{
	t_data	*new_data;

	new_data = NULL;
	new_data = initialize_data_dir_first_call(old_data->pathname,
	old_data->pathname, old_data);
	ft_lstadd(new_dir, ft_lstnew(new_data, sizeof(t_data)));
}

void	create_new_dir_list(t_data *old_data, t_list **new_dir)
{
	if ((old_data->flags & LOW_A_FLAG) && old_data->error == 0
	&& ft_strcmp(old_data->name, ".") != 0
		&& ft_strcmp(old_data->name, "..") != 0)
		add_data_to_list(old_data, new_dir);
	else if ((old_data->flags & LOW_A_FLAG) == 0
			&& old_data->name[0] != '.' && old_data->error == 0)
		add_data_to_list(old_data, new_dir);
}

void	reverse_recursive_infix(int flags, t_btree *root, t_list **new_dir)
{
	t_data	*old_data;

	old_data = NULL;
	if (is_empty(root))
	{
		old_data = (t_data *)root->item;
		reverse_recursive_infix(flags, root->right, new_dir);
		display_content(root->item);
		create_new_dir_list(old_data, new_dir);
		reverse_recursive_infix(flags, root->left, new_dir);
	}
}

void	regular_recursive_infix(int flags, t_btree *root, t_list **new_dir)
{
	t_data	*old_data;

	old_data = NULL;
	if (is_empty(root))
	{
		old_data = (t_data *)root->item;
		regular_recursive_infix(flags, root->left, new_dir);
		display_content(root->item);
		create_new_dir_list(old_data, new_dir);
		regular_recursive_infix(flags, root->right, new_dir);
	}
}

t_list	*choose_recursive_infix_traversal(t_list *list, t_list *new_dir)
{
	t_data	*data;

	data = (t_data *)list->content;
	if ((data->flags & LOW_R_FLAG) != 0)
		reverse_recursive_infix(data->flags, data->file, &new_dir);
	else
		regular_recursive_infix(data->flags, data->file, &new_dir);
	return (new_dir);
}
