/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_directories.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:20:11 by ggane             #+#    #+#             */
/*   Updated: 2016/06/22 21:27:06 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"

int		main(int ac, char **av)
{
	t_btree		*line;
	t_info		info_line;
	void 		(*applyf)(void *);

	line = NULL;
	if (parse_flags(ac, av, &info_line))
		return (1);
	applyf = &cb_ft_putendl;
	line = sort_directories(&info_line, av, line);
	if (info_line.flags & LOW_R_FLAG)
	{
		printf("rev_infix :\n");
		btree_apply_rev_infix(line, applyf);
	}
	else
		btree_apply_infix(line, applyf);
	return (0);
}