/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 14:00:05 by ggane             #+#    #+#             */
/*   Updated: 2016/09/10 14:06:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list  *insert_directories_list(t_info *info_line)
{
    t_list  *directories;

    directories = NULL;
    return (directories);
}

t_list  *sort_directories(t_info *info_line)
{
    t_list  *directories;

    directories = insert_directories_list(info_line);
    directories = merge_sort_directories();
    return (directories);
}
