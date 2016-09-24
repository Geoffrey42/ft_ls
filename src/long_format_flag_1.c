/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format_flag_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:54:11 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 20:17:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_file_mode(struct stat file_stat)
{
	display_type_file(file_stat);
	display_rights(file_stat);
	ft_putstr("  ");
}

char	*keep_necessary_timedata(char *long_time)
{
	char	*shorter_time;
	char	*ptr;

	shorter_time = (char *)malloc(sizeof(char) * 13);
	if (!shorter_time)
		return (NULL);
	ptr = long_time + 4;
	shorter_time = strncpy(shorter_time, ptr, 12);
	shorter_time[12] = '\0';
	return (shorter_time);
}

void		display_date(struct stat file_stat)
{
	char	*date;

	date = keep_necessary_timedata(ctime(&file_stat.st_mtime));
	ft_putstr(date);
	ft_putchar(' ');
}

void		display_long_format(t_data *data)
{
	struct stat		file_stat;

	if (lstat(data->pathname, &file_stat) < 0)
		return ;
	display_file_mode(file_stat);
	display_links(file_stat);
	display_id(file_stat);
	display_size(file_stat);
	display_date(file_stat);
	display_short_format(data);
}
