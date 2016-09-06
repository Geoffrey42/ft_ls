/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:27:39 by ggane             #+#    #+#             */
/*   Updated: 2016/09/05 16:37:30 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     main(int ac, char **av)
{
    t_info  info_line;
    t_list  *directories;

    info_line = NULL;
    directories = NULL;
    info_line = parse_prompt(ac, av);
    directories = sort_directories(info_line);
    sort_content(&directories, info_line);
    erase_list(&directories);
    return (0);
}
