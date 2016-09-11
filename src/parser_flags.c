/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:58:38 by ggane             #+#    #+#             */
/*   Updated: 2016/09/11 17:07:09 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	check_binary_mask(t_info *info_line, char *to_check, int j)
{
	if (to_check[0] == '-')
	{
		if (to_check[j] == 'a')
			info_line->flags |= LOW_A_FLAG;
		else if (to_check[j] == 't')
			info_line->flags |= LOW_T_FLAG;
		else if (to_check[j] == 'l')
			info_line->flags |= LOW_L_FLAG;
		else if (to_check[j] == 'r')
			info_line->flags |= LOW_R_FLAG;
		else if (to_check[j] == 'R')
			info_line->flags |= UPP_R_FLAG;
		else
		{
			display_flag_error_msg(to_check[j]);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_authorized_flags(t_info *info_line, char *to_check)
{
	int		j;

	j = 1;
	while (to_check[j])
		check_binary_mask(info_line, to_check, j++);
}

void	parse_flags(t_info *info_line)
{
	int		i;

	i = 0;
	if (info_line->ac <= 1)
		return ;
	while (i < info_line->ac - 1 && ft_strcmp(info_line->av[i], "--"))
		check_authorized_flags(info_line, info_line->av[i++]);
}
