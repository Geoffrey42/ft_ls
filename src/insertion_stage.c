/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_stage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:30:11 by ggane             #+#    #+#             */
/*   Updated: 2016/09/21 23:40:30 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_cmpf	choose_compare_tree_function(t_data *data)
{
	int		(*cmpf)(void *, void *);

	if ((data->flags & LOW_T_FLAG) == LOW_T_FLAG)
		return (cmpf = &cb_timecmp_tree);
	else
		return (cmpf = &cb_strcmp_tree);
}

t_btree	*insert_data_in_tree(t_data *data,
		t_btree *content, char *file_name, int (*cmpf)(void *, void *))
{
	t_data	*content_data;

	content_data = initialize_data_dir(file_name, data->pathname, data->flags);
	btree_insert_data(&content, (void *)content_data, cmpf);
	return (content);
}

t_btree	*insert_content(t_list *directories, int (*cmpf)(void *, void *))
{
	t_btree			*content;
	t_data			*data;
	DIR				*dirp;
	struct dirent	*file;

	content = NULL;
	data = (t_data *)directories->content;
	if (!(dirp = opendir(data->name)))
		return (NULL);
	while ((file = readdir(dirp)))
		content = insert_data_in_tree(data, content, file->d_name, cmpf);
	return (content);
}

t_list	*open_directory(t_list *directories)
{
	int		(*cmpf)(void *, void *);
	t_data	*tmp;

	tmp = (t_data *)directories->content;
	cmpf = choose_compare_tree_function((t_data *)directories->content);
	tmp->file = insert_content(directories, cmpf);
	return (directories);
}

t_list	*insertion_stage(t_list *directories)
{
	t_list	*tmp;

	tmp = directories;
	while (tmp)
	{
		//tmp = open_directory(tmp);
		open_directory(tmp);
		tmp = tmp->next;
	}
	return (directories);
}

t_list	*put_content_in_trees(t_list *directories)
{
	t_data	*data;

	data = (t_data *)directories->content;
	directories = insertion_stage(directories);
	/*if ((data->flags & UPP_R_FLAG) == 0)
		directories = traversal_stage(directories);
	else
		directories = recursive_traversal_stage(directories);*/
	if ((data->flags & UPP_R_FLAG) == 0)
		traversal_stage(directories);
	else
		recursive_traversal_stage(directories);
	return (directories);
}
