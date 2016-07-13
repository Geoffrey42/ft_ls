/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 16:21:31 by ggane             #+#    #+#             */
/*   Updated: 2016/06/04 16:17:17 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int		display_content(DIR *dirp)
{
	struct stat		file_stat;
	struct dirent	*nom;

	while ((nom = readdir(dirp)))
		if (nom->d_name[0] != '.')
			printf("%s\n", nom->d_name);
	return (0);
}

int		list_dir(char *name_dir)
{
	DIR		*dirp;
	int		ret;

	dirp = opendir(name_dir);
	if (dirp == NULL)
		return (1);
	ret = display_content(dirp);
	closedir(dirp);
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		ret;

	i = 1;
	while (ac > 1 && i < ac)
	{
		ret = list_dir(av[i]);
		i++;
	}
	if (ac == 1)
		list_dir(".");
	return (0);
}
