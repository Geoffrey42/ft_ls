/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_stage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:30:11 by ggane             #+#    #+#             */
/*   Updated: 2016/09/15 16:40:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_cmpf	choose_compare_tree_function(t_data *data)
{
	int		(*cmpf)(void *, void *);

	if (data->flags & LOW_T_FLAG == 0)
		return (cmpf = &cb_timecmp_tree);
	else
		return (cmpf = &cb_strcmp_tree);
}

t_btree	*insert_data_in_tree(t_data *data,
		t_btree *content, char *file_name, int (*cmpf)(void *, void *))
{
	t_data	*content_data;

	content_data = initialize_data_dir(file_name, data->pathname, data->flags);
	btree_insert_data(&tree, (void *)content_data, cmpf);
	return (content);
}

t_btree	*insert_content(t_list *directories, int (*cmpf)(void *, void *))
{
	t_btree			*content;
	t_data			*data;
	DIR				*dirp;
	struct dirent	*file;

	content = NULL;
	data = (t_data)directories->content;
	if (!(dirp = opendir(data->name)))
		return (NULL);
	while ((file = readdir(dirp)))
		content = insert_data_in_tree(data, content, file_name, cmpf);
	return (content);
}

t_list	*open_directory(t_list *directories)
{
	int		(*cmpf)(void *, void *);

	cmpf = choose_compare_tree_function((t_data *)directories->content);
	directories->content->files = (void *)insert_content(directories, cmpf);
	return (directories);
}

t_list	*insertion_stage(t_list *directories)
{
	while (directories)
	{
		directories = open_directory(directories);
		directories = directories->next;
	}
	return (directories);
}

t_list	*put_content_in_trees(t_list *directories)
{
	directories = insertion_stage(directories);
	directories = traversal_stage(directories);
	return (directories);
}
