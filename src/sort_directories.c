/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 09:33:56 by ggane             #+#    #+#             */
/*   Updated: 2016/06/28 11:47:02 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_data			*init_meta_data(int flag, char *dir_name)
{
	t_data		*new;

	new = NULL;
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->file_name = ft_strdup(dir_name);
	new->flags = flag;
	new->total_size = 0;
	return (new);
}

t_btree			*add_data
				(t_info *info, int (*cmpf)(void *, void *), char *dir_name,
				t_btree *sorted_dir)
{
	t_data		*meta_data;

	meta_data = NULL;
	meta_data = init_meta_data(info->flags, dir_name);
	btree_insert_data(&sorted_dir, (void *)meta_data, cmpf);
	return (sorted_dir);
}

t_btree			*insert_directories
				(t_info *info_line, int (*cmpf)(void *, void *), char **av)
{
	t_btree	*sorted_dir;
	int		i;

	sorted_dir = NULL;
	i = info_line->directory_position; 
	while (i <= info_line->argc - 1)
		sorted_dir = add_data(info_line, cmpf, av[i++], sorted_dir);
	return (sorted_dir);
}

int				check_t_flag(void *item, int type)
{
	t_info		*info;
	t_data		*data;

	info = NULL;
	data = NULL;
	if (type)
	{
		info = (t_info *)item;
		return (info->flags & LOW_T_FLAG);
	}
	else
	{
		data = (t_data *)item;
		return (data->flags & LOW_T_FLAG);
	}
	return (-1);
}
t_cmpf			choose_compare_function(void *item, int type)
{
	int			(*cmpf)(void *, void *);

	if (check_t_flag(item, type))
		return (cmpf = &cb_ft_timecmp);
	else
		return (cmpf = &cb_ft_strcmp);
}

t_btree			*put_directories_in_a_tree
				(t_info *info_line, t_btree *sorted_dir, char **av)
{
	int			(*cmpf)(void *, void *);

	cmpf = choose_compare_function(info_line, 1);
	sorted_dir = insert_directories(info_line, cmpf, av);
	return (sorted_dir);
}

t_btree			*put_current_directory_in_a_tree(t_btree *root, t_info *info)
{
	int			(*cmpf)(void *, void *);
	t_data		*content;

	cmpf = &cb_ft_strcmp;
	content = NULL;
	content = init_meta_data(info->flags, ".");
	btree_insert_data(&root, (void *)content, cmpf);
	return (root);
}

t_btree			*sort_directories(t_info *info_line, char **av, t_btree *sorted_dir)
{
	if (!info_line->directory_presence)
		sorted_dir = put_current_directory_in_a_tree(sorted_dir, info_line);
	else
		sorted_dir = put_directories_in_a_tree(info_line, sorted_dir, av);
	return (sorted_dir);
}
