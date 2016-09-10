/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 14:00:05 by ggane             #+#    #+#             */
/*   Updated: 2016/09/10 15:41:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list  *check_and_insert_data(t_list *directories, char *name)
{
    t_data  *data_dir;

    data_dir = NULL;
    data_dir = initialize_data_dir(name);
    ft_lstadd(&directories, ft_lstnew(data_dir, sizeof(data_dir)));
    return (directories);
}

t_list  *create_directories_list(t_info *info_line)
{
    t_list  *directories;
    int     i;

    directories = NULL;
    i = info_line->dir_pos;
    while (i <= info_line->nb_dir)
        directories = check_and_insert_data(directories, info_line->av[i++]);
    return (directories);
}

t_list  *sort_directories(t_info *info_line)
{
    t_list  *directories;

    directories = create_directories_list(info_line);
    directories = merge_sort_directories();
    return (directories);
}
