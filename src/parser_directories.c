/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_directories.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:58:48 by ggane             #+#    #+#             */
/*   Updated: 2016/09/29 10:31:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	check_dir_position(t_data *info_line)
{
	int		i;

	i = 0;
	while (info_line->av[i] && info_line->av[i][0] == '-'
	&& ft_strcmp(info_line->av[i], "-"))
		i++;
	if (info_line->av[i])
		info_line->dir_pos = i;
}

void	check_nb_directories(t_data *info_line)
{
	int		i;

	if (info_line->dir_pos > -1)
		i = info_line->dir_pos;
	else
		return ;
	while (info_line->av[i])
		i++;
	info_line->nb_dir = i - info_line->dir_pos;
}

void	parse_directories(t_data *info_line)
{
	check_dir_position(info_line);
	check_nb_directories(info_line);
}
