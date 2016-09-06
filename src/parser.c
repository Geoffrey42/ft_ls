/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 10:39:12 by ggane             #+#    #+#             */
/*   Updated: 2016/09/06 12:00:33 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    **copy_av(int ac, char **av)
{
    char    **copy;
    int     i;

    i = 1;
    if (!(copy = (char **)malloc(sizeof(char *) * ac)))
        return (NULL);
    while (i < ac)
    {
        *copy[i] = ft_strdup(*av[i]);
        i++;
    }
}

t_info  initialize_info_line(int ac, char **av)
{
    t_info  info_line;

    info_line = NULL;
    info_line.av = copy_av(av, ac);
    info_line.ac = ac;
    info_line.flags = 0;
    info_line.nb_dir = 0;
    info_line.dir_pos = -1;
    return (info_line);
}

t_info  parse_prompt(int ac, char **av)
{
    t_info  info_line;

    info_line = NULL;
    info_line = initialize_info_line(ac, av);
    parse_flags(&info_line);
    parse_directories(&info_line);
    return (info_line);
}
