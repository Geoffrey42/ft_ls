/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 22:26:39 by ggane             #+#    #+#             */
/*   Updated: 2016/06/28 23:06:48 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_info		*set_directories_info(t_info *info_line, int ac, char **av)
{
	int		i;

	i = 1;
	while (i <= ac - 1 && av[i][0] == '-')
	{
		if (!ft_strcmp(av[i], "--"))
		{
			i++;
			break ;
		}
		i++;
	}
	if (i < ac)
	{
		info_line->directory_presence = 1;
		info_line->directory_position = i;	
		info_line->nb_directories = ac - i;
		info_line->argc = ac;
	}
	return (info_line);
}

t_info		*initialize_info_line(t_info *info_line)
{
	info_line->flags = 0;
	info_line->argc = 0;
	info_line->directory_presence = 0;
	info_line->directory_position = -1;
	info_line->nb_directories = 0;
	return (info_line);
}
