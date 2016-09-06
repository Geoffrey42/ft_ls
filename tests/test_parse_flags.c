/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:58:23 by ggane             #+#    #+#             */
/*   Updated: 2016/09/06 20:13:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    print_flags(int flags)
{
    ft_putstr("flag ");
    if (flags & LOW_A_FLAG)
        ft_putstr("-a ");
    if (flags & LOW_T_FLAG)
        ft_putstr("-t");
    if (flags & LOW_L_FLAG)
        ft_putstr("-l ");
    if (flags & LOW_R_FLAG)
        ft_putstr("-r ");
    if (flags & UPP_R_FLAG)
        ft_putstr("-R ");
    ft_putendl("activated");
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
