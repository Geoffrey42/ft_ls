/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:30:06 by ggane             #+#    #+#             */
/*   Updated: 2016/07/11 14:53:56 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

long long int	add_size(char *file, long long int size)
{
	struct stat	file_stat;

	lstat(file, &file_stat);
	size = size + file_stat.st_size;
	return (size);
}

int				check_if_dir(char *file)
{
	struct stat	file_stat;

	lstat(file, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		return (1);
	else
		return (0);
}

/*t_btree			*add_content_tree
			(int flags, t_btree *tree, char *file_name,
			int (*cmpf)(void *, void *))
{
	t_data	*meta_data;

	meta_data = NULL;
	meta_data = init_meta_data(flags, file_name);
	meta_data->total_size = add_size(file_name, meta_data->total_size);
	meta_data->is_dir = check_if_dir(file_name);
	btree_insert_data(&tree, (void *)meta_data, cmpf);
	return (tree);
}*/

char			*create_pathname(char *parent, char *son)
{
	parent = ft_strjoin(parent, "/");
	son = ft_strjoin(parent, son);
	return (son);
}

t_btree			*add_content_tree
				(t_data *parent, t_btree *tree, char *file_name,
				int (*cmpf)(void *, void *))
{
	t_data	*meta_data;

	meta_data = NULL;
	meta_data = init_meta_data(parent->flags, file_name);
	meta_data->pathname = create_pathname(parent->file_name, meta_data->file_name);
	meta_data->total_size = add_size(meta_data->pathname, meta_data->total_size);
	meta_data->is_dir = check_if_dir(meta_data->pathname);
	btree_insert_data(&tree, (void *)meta_data, cmpf);
	return (tree);
}

t_btree			*put_content_in_a_tree
			(t_data *meta_data, DIR *dirp, t_btree *tree,
			int (*cmpf)(void *, void *))
{
	struct dirent	*file;

	while ((file = readdir(dirp)))
		//tree = add_content_tree(meta_data->flags, tree, file->d_name, cmpf);
		tree = add_content_tree(meta_data, tree, file->d_name, cmpf);
	return (tree);
}

t_btree			*insert_files(t_data *meta_data, int (*cmpf)(void *, void *))
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

t_btree			*sort_files(t_data *meta_data, t_btree *tree)
{
	int		(*cmpf)(void *, void *);

	cmpf = choose_compare_function(meta_data, 0);
	tree = insert_files(meta_data, cmpf);
	return (tree);
}

t_applyf		choose_apply_function(t_info *info_line)
{
	void	(*applyf)(void *);

	if (info_line->flags & UPP_R_FLAG)
		return (applyf = &cb_recursive_applyf);
	else
		return (applyf = &cb_non_recursive_applyf);
}

void			sort_content(t_info *info_line, t_btree *directories)
{
	void	(*applyf)(void *);

	applyf = choose_apply_function(info_line);
	choose_infix_traversal(info_line, 1, directories, applyf);
	//btree_delete(directories);
}
