/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:36:09 by ggane             #+#    #+#             */
/*   Updated: 2016/09/21 23:43:01 by ggane            ###   ########.fr       */
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
		reverse_recursive_infix(flags, root->right);
		display_content(root->item);
		new_dir = create_new_dir_list(old_data, new_dir);
		reverse_recursive_infix(flags, root->left);
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
		regular_recursive_infix(flags, root->left);
		new_dir = create_new_dir_list(old_data, new_dir);
		regular_recursive_infix(flags, root->right);
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

/*t_list	*recursive_traversal_stage(t_list *directories)
{
	t_list	*new_dir;
	t_list	*tmp;
	t_data	*data_new_dir;

	new_dir = NULL;
	tmp = directories;
	while (tmp)
	{
		new_dir = choose_recursive_infix_traversal(tmp);
		tmp = tmp->next;
	}
	if (new_dir)
	{
		ft_putendl("new_dir not empty");
		data_new_dir = (t_data *)new_dir->content;
		display_dir_title(data_new_dir->name);
		new_dir = put_content_in_trees(new_dir);
	}
	return (directories);
}*/

void	recursive_traversal_stage(t_list *directories)
{
	t_list	*new_dir;
	t_list	*tmp;
	t_data	*data_new_dir;
	int		i = 0;

	new_dir = NULL;
	tmp = directories;
	ft_putendl("\tstart recursive_traversal_stage");
	while (tmp)
	{
		ft_putstr("tour : ");
		ft_putnbr(i);
		ft_putchar('\n');
		new_dir = choose_recursive_infix_traversal(tmp);
		tmp = tmp->next;
		i++;
	}
	if (new_dir)
	{
		ft_putendl("new_dir not empty");
		data_new_dir = (t_data *)new_dir->content;
		display_dir_title(data_new_dir->name);
		new_dir = put_content_in_trees(new_dir);
	}
	ft_putendl("\tend recursive_traversal_stage");
}
