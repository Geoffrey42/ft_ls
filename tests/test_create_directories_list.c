/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_directories_list.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 18:12:48 by ggane             #+#    #+#             */
/*   Updated: 2016/09/14 16:27:22 by ggane            ###   ########.fr       */
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
	ft_putendl("BEFORE MERGE SORT\n");
    print_list(directories);
	merge_sort(&directories); 
	ft_putendl("AFTER MERGE SORT\n");
    print_list(directories);
    return (0);
}
