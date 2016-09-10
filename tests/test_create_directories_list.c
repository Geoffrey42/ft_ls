/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_directories_list.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 18:12:48 by ggane             #+#    #+#             */
/*   Updated: 2016/09/10 20:21:55 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int     main(int ac, char **av)
{
    t_info  *info_line;
    t_list  *directories;

    directories = NULL;
    ft_putendl("start test_create_directories_list");
    info_line = parse_prompt(ac, av);
    ft_putendl("parse_prompt ok");
    directories = create_directories_list(info_line);
    ft_putendl("create_directories_list ok");
    print_list(directories);
    ft_putendl("end test_create_directories_list");
    return (0);
}
