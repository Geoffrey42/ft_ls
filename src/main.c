/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:52:56 by ggane             #+#    #+#             */
/*   Updated: 2016/06/27 17:08:42 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int ac, char **av)
{
	t_btree		*directories_to_sort;
	t_info		info_line;

	directories_to_sort = NULL;
	if (parse_flags(ac, av, &info_line))
		return (1);
	directories_to_sort = sort_directories(&info_line, av, directories_to_sort);
	sort_content(info_line, directories_to_sort);
	delete_tree(directories_to_sort);
	return (0);
}
