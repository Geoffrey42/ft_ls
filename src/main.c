/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:52:56 by ggane             #+#    #+#             */
/*   Updated: 2016/06/08 13:07:35 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int ac, char **av)
{
	t_btree		*directories_list;
	int			*flags;

	directories_list = NULL;
	if ((flags = parse_flags(ac, av)) == NULL)
		return (1);
	//if (check_if_directories(ac, av))
	//	av = cut_flags_arguments(ac, av);
	directories_list = sort_directories(directories_list, ac, av);
	sort_and_display_content(directories_list, flags);
	return (0);
}
