/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:58:23 by ggane             #+#    #+#             */
/*   Updated: 2016/09/14 13:49:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int     main(int ac, char **av)
{
    t_info  *info_line;

    info_line = NULL;
    info_line = initialize_info_line(ac, av);
    parse_flags(info_line);
    print_flags(info_line->flags);
    return (0);
}
