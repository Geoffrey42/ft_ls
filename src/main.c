/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:52:56 by ggane             #+#    #+#             */
/*   Updated: 2016/06/16 09:35:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int ac, char **av)
{
	t_btree		*directories_to_sort;
	int			*flags;

	directories_to_sort = NULL;
	if (!(flags = parse_flags(ac, av)))
		return (1);
	directories_to_sort = sort_directories(ac, av);
	sort_content(flags, directories_to_sort);
	return (0);
}
