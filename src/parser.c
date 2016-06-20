/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 09:26:05 by ggane             #+#    #+#             */
/*   Updated: 2016/06/20 17:33:59 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_info		*set_directories_info(t_info *info_line, int start)
{
	info_line->directory_presence = 1;
	info_line->directory_position = start;	
	return (info_line);
}

int			add_flags(char	*to_check, int ***flags, int i)
{
	char	*authorized_flags;

	authorized_flags = "alRtr";
	if (to_check[0] == '-' && ft_strchr(authorized_flags, to_check[i]))
		**flags[to_check[i]] = 1;
	else
	{
		display_flags_error_msg(to_check[i]);
		return (1);
	}
	return (0);
}

int			check_authorized_flags(char *to_check, int **flags)
{
	int		i;

	i = 1;
	while (to_check[i])
	{
		if (add_flags(to_check, &flags, i))
			return (1);
		i++;
	}
	return (0);
}

t_info		*initialize_info_line(t_info *info_line)
{
	if (!(info_line = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	if (!(info_line->flags = (int *)ft_memalloc(FLAGS_SIZE)))
		return (NULL);
	info_line->directory_presence = 0;
	info_line->directory_position = -1;
	return (info_line);
}

t_info		*parse_flags(int ac, char **av, t_info *info_line)
{
	int		i;

	info_line = initialize_info_line(info_line);
	i = 1;
	while (i <= ac - 1 && ft_strcmp(av[i], "--"))
	{
		if (check_authorized_flags(av[i], &info_line->flags))
			return (NULL);
		i++;
	}
	if (i < ac)
		info_line = set_directories_info(info_line, i);
	return (info_line);
}
