/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_directories_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:22:30 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 14:00:59 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list	*insert_data_in_list(t_list *directories, char *name, t_data *info_line)
{
	t_data	*data;

	data = NULL;
	data = initialize_data_dir_first_call(name, "", info_line);
	ft_lstadd(&directories, ft_lstnew(data, sizeof(t_data)));
	return (directories);
}

t_list	*insert_current_directory(t_data *info_line)
{
	t_list	*directory;

	directory = NULL;
	directory = insert_data_in_list(directory, ".", info_line);
	return (directory);
}

t_list	*insert_several_directories(t_data *info_line)
{
	t_list	*directories;
	int		i;

	directories = NULL;
	i = info_line->dir_pos;
	while (i <= info_line->ac - 1)
		directories = insert_data_in_list(directories, info_line->av[i++],
		info_line);
	return (directories);
}

t_list	*create_directories_list(t_data *info_line)
{
	t_list	*directories;

	directories = NULL;
	if (info_line->nb_dir > 0)
		directories = insert_several_directories(info_line);
	else
		directories = insert_current_directory(info_line);
	return (directories);
}
