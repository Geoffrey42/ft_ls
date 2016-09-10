/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:58:23 by ggane             #+#    #+#             */
/*   Updated: 2016/09/09 14:55:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    print_flags(int flags)
{
    int     switcher;

    switcher = 0;
    ft_putstr("flags ");
    if (flags & LOW_A_FLAG)
    {
        ft_putstr("-a ");
        switcher = 1;
    }
    if (flags & LOW_T_FLAG)
    {
        ft_putstr("-t ");
        switcher = 1;
    }
    if (flags & LOW_L_FLAG)
    {
        ft_putstr("-l ");
        switcher = 1;
    }
    if (flags & LOW_R_FLAG)
    {
        ft_putstr("-r ");
        switcher = 1;
    }
    if (flags & UPP_R_FLAG)
    {
        ft_putstr("-R ");
        switcher = 1;
    }
    if (switcher)
        ft_putendl(" activated\n");
    else
        ft_putendl(" not activated\n");
}

int     main(int ac, char **av)
{
    t_info  *info_line;

    info_line = NULL;
    info_line = initialize_info_line(ac, av);
    parse_flags(info_line);
    print_flags(info_line->flags);
    return (0);
}
