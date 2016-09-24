/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:01:47 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 17:04:19 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_new_line(t_list *list)
{
	t_data	*content;

	content = NULL;
	if (list->next)
	{
		content = (t_data *)list->next->content;
		if (content->error == 0)
			ft_putchar('\n');
	}
}

void		display_dir_title(t_data *content)
{
	if (content->nb_dir > 1)
	{
		ft_putstr(content->pathname);
		ft_putendl(":");
	}
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
	if (data->flags & LOW_A_FLAG)
		choose_format_to_display(data);
	else if ((data->flags & LOW_A_FLAG) == 0 && data->name[0] != '.')
		choose_format_to_display(data);
}
