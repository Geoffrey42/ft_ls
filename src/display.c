/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:01:47 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 11:46:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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

void		display_short_format(t_data *data)
{
	ft_putendl(data->name);
}

void		choose_format_to_display(t_data *data)
{
	if (data->flags & LOW_L_FLAG)
		display_long_format(data);
	else
		display_short_format(data);
}

void		display_content(void *item)
{
	t_data	*data;

	data = (t_data *)item;
	if (data->flags & LOW_A_FLAG != 0)
		choose_format_to_display(data);
	else if (data->flags & LOW_A_FLAG == 0 && data->name[0] != '.')
		choose_format_to_display(data);
}
