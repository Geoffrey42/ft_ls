/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_directories.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:20:11 by ggane             #+#    #+#             */
/*   Updated: 2016/06/15 21:22:46 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"

void	cb_ft_putstr(void *str)
{
	ft_putstr("\n\t-----\n\n\t");
	ft_putendl(str);
}

int		main(int ac, char **av)
{
	t_btree		*line;
	void (*applyf)(void *);

	line = NULL;
	applyf = &cb_ft_putstr;
	line = sort_directories(ac, av);
	btree_apply_infix(line, applyf);
	return (0);
}
