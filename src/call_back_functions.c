/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_back_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 19:37:20 by ggane             #+#    #+#             */
/*   Updated: 2016/06/28 12:02:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	cb_non_recursive_applyf(void *item)
{
	t_btree		*content;
	t_data		*meta_data;

	content = NULL;
	meta_data = (t_data *)item;
	content = sort_files(meta_data, content);
	display_content(content, meta_data);
	//btree_delete(content);
}

void	cb_recursive_applyf(void *item)
{
	t_data	*nothing;

	nothing = (t_data *)item;
}

void	cb_display_format(void *item)
{
	t_data	*tmp;

	tmp = (t_data *)item;
	if (tmp->flags & LOW_A_FLAG)
		choose_format_to_display(tmp);
	else if ((!tmp->flags & LOW_A_FLAG) && tmp->file_name[0] != '.')
		choose_format_to_display(tmp);
}

void	cb_ft_putendl(void *str)
{
	t_data	*tmp;

	tmp = (t_data *)str;
	if (!tmp->flags & LOW_A_FLAG)
		ft_putendl(tmp->file_name);
	else if ((tmp->flags & LOW_A_FLAG) && tmp->file_name[0] != '.')
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
	return (ft_strcmp(tmp1->file_name, tmp2->file_name));
}
