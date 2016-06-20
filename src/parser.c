/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 09:26:05 by ggane             #+#    #+#             */
/*   Updated: 2016/06/20 20:02:42 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_info		*set_directories_info(t_info *info_line, int start)
{
	info_line->directory_presence = 1;
	info_line->directory_position = start;	
	return (info_line);
}

int			add_flags(char	*to_check, t_info *info_line, int i)
{
	if (to_check[0] == '-')
	{
		if (to_check[i] == 'a')
			info_line->flags |= LOW_A_FLAG;
		else if (to_check[i] == 't')
			info_line->flags |= LOW_T_FLAG;
		else if (to_check[i] == 'l')
			info_line->flags |= LOW_L_FLAG;
		else if (to_check[i] == 'r')
			info_line->flags |= LOW_R_FLAG;
		else if (to_check[i] == 'R')
			info_line->flags |= UPP_R_FLAG;
		else
		{
			display_flags_error_msg(to_check[i]);
			return (1);
		}
	}
	return (0);
}

int			check_authorized_flags(char *to_check, t_info *info_line)
{
	int		i;

	i = 1;
	while (to_check[i])
		if (add_flags(to_check, info_line, i++))
			return (1);
	return (0);
}

t_info		*initialize_info_line(t_info *info_line)
{
	info_line->flags = 0;
	info_line->directory_presence = 0;
	info_line->directory_position = -1;
	return (info_line);
}

int			parse_flags(int ac, char **av, t_info *info_line)
{
	int		i;

	info_line = initialize_info_line(info_line);
	i = 1;
	while (i <= ac - 1 && ft_strcmp(av[i], "--"))
		if (check_authorized_flags(av[i++], info_line))
			return (1);
	if (i < ac)
		info_line = set_directories_info(info_line, i);
	return (0);
}
