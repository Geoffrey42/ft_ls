/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 14:00:05 by ggane             #+#    #+#             */
/*   Updated: 2016/09/11 15:31:00 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list  *check_and_insert_data(t_list *directories, char *name)
{
    t_data  *data;

    data = NULL;
    data = initialize_data_dir(name);
    ft_lstadd(&directories, ft_lstnew(data, sizeof(t_data)));
    return (directories);
}

t_list  *insert_current_directory(void)
{
    t_list  *directory;

    directory = NULL;
    directory = check_and_insert_data(directory, ".");
    return (directory);
}

t_list  *insert_several_directories(t_info *info_line)
{
    t_list  *directories;
    int     i;

    directories = NULL;
    i = info_line->dir_pos;
    while (i <= info_line->ac - 1)
        directories = check_and_insert_data(directories, info_line->av[i++]);
    return (directories);
}

t_list  *create_directories_list(t_info *info_line)
{
    t_list  *directories;

    directories = NULL;
    if (info_line->nb_dir > 0)
        directories = insert_several_directories(info_line);
    else
        directories = insert_current_directory();
    return (directories);
}

t_list  *sort_directories(t_info *info_line)
{
    t_list  *directories;

    directories = create_directories_list(info_line);
    //directories = merge_sort_directories(info_line);
    return (directories);
}
