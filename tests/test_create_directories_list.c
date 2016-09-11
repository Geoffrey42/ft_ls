/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_directories_list.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 18:12:48 by ggane             #+#    #+#             */
/*   Updated: 2016/09/11 19:36:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int     main(int ac, char **av)
{
    t_info  *info_line;
    t_list  *directories;

    directories = NULL;
    info_line = parse_prompt(ac, av);
    directories = create_directories_list(info_line);
	ft_putendl("BEFORE MERGE SORT");
    print_list(directories);
	directories = sort_directories(info_line, directories); 
	ft_putendl("AFTER MERGE SORT");
    print_list(directories);
    return (0);
}
