/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_directories.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:57:21 by ggane             #+#    #+#             */
/*   Updated: 2016/09/08 19:01:20 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    print_av(char **av_test)
{
    int     i;

    i = 0;
    while (av_test[i] != NULL)
    {
        //ft_putnbr(ft_strlen(av_test[i]));
        //ft_putchar(' ');
        ft_putstr(av_test[i]);
        if (av_test[i] != NULL)
            ft_putchar(' ');
            i++;
    }
}

void    print_info_line(t_info *info_line)
{
    ft_putstr("av : ");
    print_av(info_line->av);
    ft_putstr("\nac : ");
    ft_putnbr(info_line->ac);
    ft_putchar('\n');
    ft_putstr("nb_dir : ");
    ft_putnbr(info_line->nb_dir);
    ft_putchar('\n');
    ft_putstr("dir_pos : ");
    ft_putnbr(info_line->dir_pos);
    ft_putchar('\n');
}

int     main(int ac, char **av)
{
    t_info  *info_line;

    info_line = NULL;
    info_line = initialize_info_line(ac, av);
    parse_directories(info_line);
    print_info_line(info_line);
    return (0);
}
