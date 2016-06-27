/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:30:06 by ggane             #+#    #+#             */
/*   Updated: 2016/06/27 15:57:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_btree		*add_content_tree
			(int flags, t_btree *tree, char *file_name,
			int (*cmpf)(void *, void *))
{
	t_data	*meta_data;

	meta_data = NULL;
	meta_data = init_meta_data(flags, file->file_name);
	btree_insert_data(&tree, (void *)meta_data, cmpf);
	return (tree);
}

t_btree		*put_content_in_a_tree
			(t_data *meta_data, DIR *dirp, t_btree *tree,
			int (*cmpf)(void *, void *))
{
	struct dirent	*file;

	while ((file = readdir(dirp)))
		tree = add_content_tree(meta_data->flags, tree, file->d_name);
	return (tree);
}

t_btree		*insert_files(t_data *meta_data, int (*cmpf)(void *, void *))
{
	t_btree	*tree;
	DIR		*dirp;

	tree = NULL;
	if (!(dirp = opendir(meta_data->file_name)))
		return (NULL);
	tree = put_content_in_a_tree(meta_data, dirp, tree, cmpf); 
	closedir(dirp);
	return (tree);
}

t_btree		*sort_files(t_data *meta_data, t_btree *tree)
{
	int		(*cmpf)(void *, void *);

	cmpf = choose_compare_file_function(meta_data, 0);
	tree = insert_files(meta_data, cmpf);
	return (tree);
}

t_applyf	choose_apply_function(t_info *info_line)
{
	void	(*applyf)(void *);

	if (info_line->flags & UPP_R_FLAG)
		return (applyf = &cb_recursive_applyf);
	else
		return (applyf = &cb_non_recursive_applyf);
}

void		sort_content(t_info *info_line, t_btree *directories)
{
	void	(*applyf)(void *);

	applyf = choose_apply_function(info_line);
	directories = choose_traversal_function(info_line, directories);
	erase_directories_tree(&directories);
}
