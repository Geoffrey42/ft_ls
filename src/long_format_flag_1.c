/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format_flag_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:54:11 by ggane             #+#    #+#             */
/*   Updated: 2016/09/28 09:01:18 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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
	display_short_format(data);
}
