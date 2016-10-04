/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_tree_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:36:52 by ggane             #+#    #+#             */
/*   Updated: 2016/09/30 11:36:32 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cb_timecmp_tree(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;
	t_data			*tmp1;
	t_data			*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	lstat(tmp1->pathname, &item_stat1);
	lstat(tmp2->pathname, &item_stat2);
	if (item_stat1.st_mtime < item_stat2.st_mtime)
		return (1);
	else if (item_stat1.st_mtime > item_stat2.st_mtime)
		return (-1);
	else if (item_stat1.st_mtime == item_stat2.st_mtime)
		return (check_nanoseconds_tree(item1, item2));
	return (0);
}

int		cb_strcmp_tree(void *item1, void *item2)
{
	t_data	*tmp1;
	t_data	*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	return (ft_strcmp(tmp1->pathname, tmp2->pathname));
}

int		check_nanoseconds_tree(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;
	t_data			*tmp1;
	t_data			*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	lstat(tmp1->pathname, &item_stat1);
	lstat(tmp2->pathname, &item_stat2);
	if (item_stat1.st_mtimespec.tv_nsec < item_stat2.st_mtimespec.tv_nsec)
		return (1);
	else if (item_stat1.st_mtimespec.tv_nsec > item_stat2.st_mtimespec.tv_nsec)
		return (-1);
	else if (item_stat1.st_mtimespec.tv_nsec == item_stat2.st_mtimespec.tv_nsec)
		return (cb_strcmp_tree(item1, item2));
	return (0);
}
