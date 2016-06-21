/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_back_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 19:37:20 by ggane             #+#    #+#             */
/*   Updated: 2016/06/21 15:26:52 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	cb_ft_putendl(void *str)
{
	ft_putendl(str);
	ft_putchar('\n');
}

int		cb_ft_timecmp(void *item1, void *item2)
{
	struct stat		item_stat1;
	struct stat		item_stat2;
	int				res;

	lstat(item1, &item_stat1);
	lstat(item2, &item_stat2);
	res = item_stat1.st_mtime - item_stat2.st_mtime;
	return (res);
}

int		cb_ft_strcmp(void *s1, void *s2)
{
	return (ft_strcmp(s1, s2));
}
