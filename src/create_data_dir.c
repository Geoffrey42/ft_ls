/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:40:44 by ggane             #+#    #+#             */
/*   Updated: 2016/09/14 11:44:32 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		check_if_error_dir(char *name)
{
	DIR		*dirp;
	int		res;

	res = 0;
	errno = 0;
	if ((dirp = opendir(name)) == NULL)
		return (res = errno);
	closedir(dirp);
	return (res);
}

char	*create_pathname(char *parent, char *son)
{
	parent = ft_strjoin(parent, "/");
	son = ft_strjoin(parent, son);
	return (son);
}

t_data	*initialize_data_dir(char *name, int flags)
{
	t_data	*data_dir;

	data_dir = NULL;
	if (!(data_dir = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data_dir->name = ft_strdup(name);
	data_dir->pathname = create_pathname("", name);
	data_dir->error = check_if_error_dir(name);
	data_dir->flags = flags;
	return (data_dir);
}
