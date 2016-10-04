/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:25:08 by ggane             #+#    #+#             */
/*   Updated: 2016/09/30 11:39:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			empty_dir(t_data *dir)
{
	struct dirent	*file;
	DIR				*dirp;
	int				hidden;
	int				turns;

	hidden = 0;
	turns = 0;
	if (dir->flags & LOW_A_FLAG)
		return (0);
	if (!(dirp = opendir(dir->name)))
		return (1);
	while ((file = readdir(dirp)))
	{
		if (ft_strcmp(file->d_name, ".") == 0 ||
			ft_strcmp(file->d_name, "..") == 0)
			hidden++;
		turns++;
	}
	closedir(dirp);
	if (hidden == 2 && turns == 2)
		return (1);
	return (0);
}

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
	size = file_stat.st_blocks;
	return (size);
}

void		display_total_size(t_data *directory)
{
	size_t			size;
	struct dirent	*file;
	DIR				*dirp;

	size = 0;
	if (empty_dir(directory))
		return ;
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
