/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:15:57 by ggane             #+#    #+#             */
/*   Updated: 2016/09/28 08:57:43 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			check_special_file(struct stat file_stat)
{
	if ((S_ISCHR(file_stat.st_mode)) || S_ISBLK(file_stat.st_mode))
		return (1);
	return (0);
}

int			major_device(unsigned int dev)
{
	int		res;

	res = dev >> 24 & 0xff;
	return (res);
}

int			minor_device(int dev)
{
	int		res;

	res = dev & 0xffffff;
	return (res);
}

void		display_major_minor(struct stat file_stat)
{
	ft_putnbr(major_device(file_stat.st_rdev));
	ft_putstr(", ");
	ft_putnbr(minor_device(file_stat.st_rdev));
	ft_putchar(' ');
}
