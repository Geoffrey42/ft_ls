/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format_flag_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:16:15 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 20:29:15 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_size(struct stat file_stat)
{
	ft_putnbr(file_stat.st_size);
	ft_putchar(' ');
}

void		print_total_size(size_t size)
{
	ft_putstr("total ");
	ft_putnbr(size);
	ft_putchar('\n');
}

size_t		sum_file_sizes(t_data *directory, struct dirent *file)
{
	size_t			size;
	struct stat		file_stat;
	char			*file_pathname;

	size = 0;
	file_pathname = create_pathname(directory->pathname, file->d_name);
	lstat(file_pathname, &file_stat);
	size = file_stat.st_size;
	return (size);
}

void		display_total_size(t_data *directory)
{
	size_t			size;
	struct dirent	*file;
	DIR				*dirp;

	size = 0;
	if (!(dirp = opendir(directory->name)))
		return ;
	while ((file = readdir(dirp)))
	{
		if (directory->flags & LOW_A_FLAG)
			size = size + sum_file_sizes(directory, file);
		else if ((directory->flags & LOW_A_FLAG) == 0 && file->d_name[0] != '.')
			size = size + sum_file_sizes(directory, file);
	}
	closedir(dirp);
	print_total_size(size);
}
