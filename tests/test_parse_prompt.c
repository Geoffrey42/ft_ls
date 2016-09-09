/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 19:26:00 by ggane             #+#    #+#             */
/*   Updated: 2016/09/09 11:28:42 by ggane            ###   ########.fr       */
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
            ft_putendl(" activated");
        else
            ft_putendl(" not activated");
}

int     main(int ac, char **av)
{
    t_info  *info_line;

    info_line = NULL;
    info_line = parse_prompt(ac, av);
    ft_putstr("After parsing\n");
    print_info_line(info_line);
    print_flags(info_line->flags);
    return (0);
}
