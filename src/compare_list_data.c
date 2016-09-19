/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_list_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:09:59 by ggane             #+#    #+#             */
/*   Updated: 2016/09/19 18:20:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		choose_compare_list_function(t_list *item1, t_list *item2)
{
	t_data	*ptr_1;
	t_data	*ptr_2;

	ptr_1 = (t_data *)item1->content;
	ptr_2 = (t_data *)item2->content;
	if ((ptr_1->flags & LOW_T_FLAG) == 0 && (ptr_1->flags & LOW_R_FLAG) == 0)
		return (ft_strcmp(ptr_1->name, ptr_2->name));
	else if ((ptr_1->flags & LOW_T_FLAG) == 0 && (ptr_1->flags & LOW_R_FLAG)
			!= 0)
		return (ft_strcmp(ptr_2->name, ptr_1->name));
	else if (((ptr_1->flags & LOW_T_FLAG) != 0 && (ptr_1->flags & LOW_R_FLAG)
			== 0))
		return (cb_timecmp_list(ptr_1->name, ptr_2->name));
	else if (((ptr_1->flags & LOW_T_FLAG) != 0 && (ptr_1->flags & LOW_R_FLAG)
			!= 0))
		return (cb_timecmp_list(ptr_2->name, ptr_1->name));
	return (-1);
}

int		check_nanoseconds(char *str1, char *str2)
{
	struct stat		str_stat1;
	struct stat		str_stat2;

	lstat(str1, &str_stat1);
	lstat(str2, &str_stat2);
	if (str_stat1.st_mtimespec.tv_nsec < str_stat2.st_mtimespec.tv_nsec)
		return (1);
	else if (str_stat1.st_mtimespec.tv_nsec > str_stat2.st_mtimespec.tv_nsec)
		return (-1);
	else if (str_stat1.st_mtimespec.tv_nsec == str_stat2.st_mtimespec.tv_nsec)
		return (ft_strcmp(str1, str2));
	return (0);
}

int		cb_timecmp_list(char *str1, char *str2)
{
	struct stat		str_stat1;
	struct stat		str_stat2;

	lstat(str1, &str_stat1);
	lstat(str2, &str_stat2);
	if (str_stat1.st_mtime < str_stat2.st_mtime)
		return (1);
	else if (str_stat1.st_mtime > str_stat2.st_mtime)
		return (-1);
	else if (str_stat1.st_mtime == str_stat2.st_mtime)
		return (check_nanoseconds(str1, str2));
	return (-1);
}

int		cb_timecmp_tree(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;
	t_data	*tmp1;
	t_data	*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	lstat(tmp1->pathname, &item_stat1);
	lstat(tmp2->pathname, &item_stat2);
	if (item_stat1.st_mtime < item_stat2.st_mtime)
		return (1);
	else if (item_stat1.st_mtime > item_stat2.st_mtime)
		return (-1);
	else if (item_stat1.st_mtime == item_stat2.st_mtime)
		return (check_nanoseconds(item1, item2));
	return (0);
}

int		cb_strcmp_tree(void *item1, void *item2)
{
	t_data	*tmp1;
	t_data	*tmp2;

	tmp1 = (t_data *)item1;
	tmp2 = (t_data *)item2;
	return (ft_strcmp(tmp1->name, tmp2->name));
}
