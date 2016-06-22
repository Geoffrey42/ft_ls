/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 09:33:56 by ggane             #+#    #+#             */
/*   Updated: 2016/06/22 21:31:04 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_btree			*insert_directories
				(t_info *info_line, int (*cmpf)(void *, void *), char **av)
{
	t_btree	*sorted_dir;
	int		i;

	sorted_dir = NULL;
	i = info_line->directory_position; 
	while (i <= info_line->argc - 1)
		btree_insert_data(&sorted_dir, (void *)av[i++], cmpf);
	return (sorted_dir);
}

t_cmpf			choose_compare_function(t_info *info_line)
{
	int			(*cmpf)(void *, void *);

	if (info_line->flags & LOW_T_FLAG)
		return (cmpf = &cb_ft_timecmp);
	else
		return (cmpf = &cb_ft_strcmp);
}

t_btree			*put_directories_in_a_tree
				(t_info *info_line, t_btree *sorted_dir, char **av)
{
	int			(*cmpf)(void *, void *);

	cmpf = choose_compare_function(info_line);
	sorted_dir = insert_directories(info_line, cmpf, av);
	return (sorted_dir);
}

t_btree			*put_current_directory_in_a_tree(t_btree *root, t_info *info)
{
	int			(*cmpf)(void *, void *);
	char		*content;

	cmpf = &cb_ft_strcmp;
	content = ft_strdup(".");
	btree_insert_data(&root, content, cmpf);
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
