/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format_flag_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:55:19 by ggane             #+#    #+#             */
/*   Updated: 2016/09/30 11:06:19 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_type_file(struct stat file_stat)
{
	if (S_ISDIR(file_stat.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(file_stat.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(file_stat.st_mode))
		ft_putchar('b');
	else if (S_ISLNK(file_stat.st_mode))
		ft_putchar('l');
	else if (S_ISFIFO(file_stat.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(file_stat.st_mode))
		ft_putchar('s');
	else if (S_ISREG(file_stat.st_mode))
		ft_putchar('-');
}

void		display_rights(struct stat file_stat)
{
	ft_putstr((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXOTH) ? "x" : "-");
}

void		display_links(struct stat file_stat)
{
	ft_putnbr(file_stat.st_nlink);
	ft_putchar(' ');
}

void		display_id(struct stat file_stat)
{
	struct passwd	*usr_id;
	struct group	*grp_id;

	usr_id = getpwuid(file_stat.st_uid);
	ft_putstr(usr_id->pw_name);
	ft_putstr("  ");
	grp_id = getgrgid(file_stat.st_gid);
	ft_putstr(grp_id->gr_name);
	ft_putstr("  ");
}
