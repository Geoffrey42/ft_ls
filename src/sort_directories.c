/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 09:33:56 by ggane             #+#    #+#             */
/*   Updated: 2016/06/21 14:41:16 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_btree		*insert_data
			(t_info *info_line, int (*cmpf)(void *, void *), char **av)
{
	t_btree	*sorted_dir;
	int		i;

	sorted_dir = NULL;
	i = info_line->directory_position; 
	while (i <= info_line->nb_directories)
		btree_insert_data(&sorted_dir, (void *)av[i++], cmpf);
	return (sorted_dir);
}

t_btree		*put_directories_in_a_tree
			(t_info *info_line, t_btree *sorted_dir, char **av)
{
	int			(*cmpf)(void *, void *);

	if (info_line->flags & LOW_T_FLAG)
		cmpf = &cb_ft_timecmp;
	else
		cmpf = &cb_ft_strcmp;
	sorted_dir = insert_data(info_line, cmpf, av);
	return (sorted_dir);
}

t_btree		*put_current_directory_in_a_tree(t_btree *root)
{
	char	current;
	int		(*cmpf)(void *, void *);

	cmpf = &cb_ft_strcmp;
	current = '.';
	btree_insert_data(&root, (void *)&current, cmpf);
	return (root);
}

t_btree		*sort_directories(t_info *info_line, char **av, t_btree *sorted_dir)
{
	if (!info_line->directory_presence)
		sorted_dir = put_current_directory_in_a_tree(sorted_dir);
	else
		sorted_dir = put_directories_in_a_tree(info_line, sorted_dir, av);
	return (sorted_dir);
}
