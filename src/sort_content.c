/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:30:06 by ggane             #+#    #+#             */
/*   Updated: 2016/06/23 21:56:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_btree		*put_content_in_a_tree(DIR *dirp, t_btree *tree)
{
	struct dirent	*files;

	while ((file = readdir(dirp)))
		tree = btree_insert_data(&tree, (void *)file->d_name, cmpf);
	return (tree);
}

t_btree		*insert_files(t_data *meta_data, int (*cmpf)(void *, void *))
{
	t_btree	*tree;
	DIR		*dirp;

	tree = NULL;
	if (!(dirp = opendir(meta_data->file_name)))
		return (NULL);
	tree = put_content_in_a_tree(dirp, tree); 
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
