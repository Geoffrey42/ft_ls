/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format_flag_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:54:11 by ggane             #+#    #+#             */
/*   Updated: 2016/09/28 20:19:34 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_link(t_data *data)
{
	char	buf[256];
	int		len;

	ft_putstr(data->name);
	ft_putstr(" -> ");
	len = readlink(data->pathname, buf, sizeof(buf)); 
	buf[len] = '\0';
	ft_putendl(buf);
}

void		display_file_mode(struct stat file_stat)
{
	display_type_file(file_stat);
	display_rights(file_stat);
	ft_putstr("  ");
}

void		display_long_format(t_data *data)
{
	struct stat		file_stat;

	if (lstat(data->pathname, &file_stat) < 0)
		return ;
	display_file_mode(file_stat);
	display_links(file_stat);
	display_id(file_stat);
	if (!check_special_file(file_stat))
		display_size(file_stat);
	else
		display_major_minor(file_stat);
	display_date(file_stat);
	if (!S_ISLNK(file_stat.st_mode))
		display_short_format(data);
	else
		display_link(data);
}
