/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 09:33:56 by ggane             #+#    #+#             */
/*   Updated: 2016/06/16 11:59:59 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_btree		*put_directories_in_a_tree(int start, int ac, char **av)
{
	t_btree		*sorted_directories;
	int			(*cmpf)(void *, void *);

	sorted_directories = NULL;
	cmpf = &cb_ft_strcmp;
	while (start <= ac - 1)
	{
		btree_insert_data(&sorted_directories, av[start], cmpf);
		start++;
	}
	return (sorted_directories);
}

int			check_directories_presence(int ac, char **av)
{
	int		i;

	i = 1;
	while (i <= ac - 1 && av[i][0] == '-')
		i++;
	if (i < ac)
		return (i);
	return (0);
}

t_btree		*sort_directories(int ac, char **av)
{
	t_btree		*sorted_directories;
	char		current_directory;
	int			(*cmpf)(void *, void *);
	int			position_dir;

	sorted_directories = NULL;
	current_directory = '.';
	cmpf = &cb_ft_strcmp;
	if ((position_dir = check_directories_presence(ac, av)))
		sorted_directories = put_directories_in_a_tree(position_dir, ac, av);
	else
		btree_insert_data(&sorted_directories, (void *)&current_directory, cmpf);
	return (sorted_directories);
}
