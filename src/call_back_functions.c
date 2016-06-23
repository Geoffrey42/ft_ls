/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_back_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 19:37:20 by ggane             #+#    #+#             */
/*   Updated: 2016/06/23 15:09:37 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	cb_non_recursive_applyf(void *item)
{
}

void	cb_ft_putendl(void *str)
{
	t_data	*tmp;

	tmp = (t_data *)str;
	ft_putstr("\t\t");
	//ft_putendl(str);
	ft_putendl(tmp->file_name);
}

int		check_nanosec(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;
	t_data	*tmp1;
	t_data	*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	lstat(tmp1->file_name, &item_stat1);
	lstat(tmp2->file_name, &item_stat2);
	//lstat(item1, &item_stat1);
	//lstat(item2, &item_stat2);
	if (item_stat1.st_mtimespec.tv_nsec < item_stat2.st_mtimespec.tv_nsec)
		return (1);
	else if (item_stat1.st_mtimespec.tv_nsec > item_stat2.st_mtimespec.tv_nsec)
		return (-1);
	else if (item_stat1.st_mtimespec.tv_nsec == item_stat2.st_mtimespec.tv_nsec)
		return (cb_ft_strcmp(item1, item2));
	return (0);
}

int		cb_ft_timecmp(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;
	t_data	*tmp1;
	t_data	*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	lstat(tmp1->file_name, &item_stat1);
	lstat(tmp2->file_name, &item_stat2);
	//lstat(item1, &item_stat1);
	//lstat(item2, &item_stat2);
	if (item_stat1.st_mtime < item_stat2.st_mtime)
		return (1);
	else if (item_stat1.st_mtime > item_stat2.st_mtime)
		return (-1);
	else if (item_stat1.st_mtime == item_stat2.st_mtime)
		return (check_nanosec(item1, item2));
	return (0);
}

int		cb_ft_strcmp(void *item1, void *item2)
{
	t_data	*tmp1;
	t_data	*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	//return (ft_strcmp(item1, item2));
	return (ft_strcmp(tmp1->file_name, tmp2->file_name));
}
