/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:01:47 by ggane             #+#    #+#             */
/*   Updated: 2016/09/22 18:35:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_content(void *item)
{
	t_data	*data;

	data = (t_data *)item;
	if (data->error == 0 && data->name[0] != '.')
	{
		ft_putstr(data->name);
		ft_putendl("/");
	}
	else if (data->error != 0 && data->name[0] != '.')
		ft_putendl(data->name);
}
