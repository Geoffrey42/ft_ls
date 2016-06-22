/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_back_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 19:37:20 by ggane             #+#    #+#             */
/*   Updated: 2016/06/22 11:41:38 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	cb_ft_putendl(void *str)
{
	ft_putstr("\t\t");
	ft_putendl(str);
}

int		check_nanosec(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;

	lstat(item1, &item_stat1);
	lstat(item2, &item_stat2);
	if (item_stat1.st_mtimespec.tv_nsec < item_stat2.st_mtimespec.tv_nsec)
		return (1);
	else if (item_stat1.st_mtimespec.tv_nsec > item_stat2.st_mtimespec.tv_nsec)
		return (-1);
	else if (item_stat1.st_mtimespec.tv_nsec == item_stat2.st_mtimespec.tv_nsec)
		return (ft_strcmp(item1, item2));
	return (0);
}

int		cb_ft_timecmp(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;

	lstat(item1, &item_stat1);
	lstat(item2, &item_stat2);
	if (item_stat1.st_mtime < item_stat2.st_mtime)
		return (1);
	else if (item_stat1.st_mtime > item_stat2.st_mtime)
		return (-1);
	else if (item_stat1.st_mtime == item_stat2.st_mtime)
		return (check_nanosec(item1, item2));
	return (0);
}

int		cb_ft_strcmp(void *s1, void *s2)
{
	return (ft_strcmp(s1, s2));
}
