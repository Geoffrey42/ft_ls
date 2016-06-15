/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 09:26:05 by ggane             #+#    #+#             */
/*   Updated: 2016/06/15 09:27:34 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		check_authorized_flags(char *to_check, int *flags)
{
	char	*authorized_flags;
	int		i;

	i = 1;
	authorized_flags = "alRtr";
	while (to_check[i])
	{
		if (to_check[0] == '-' && ft_strchr(authorized_flags, to_check[i]))
			flags[to_check[i]] = 1;
		else
		{
			display_flags_error_msg(to_check[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int		*parse_flags(int ac, char **av)
{
	int		*flags;
	int		i;

	i = 1;
	if (!(flags = (int *)ft_memalloc(FLAGS_SIZE)))
		return (NULL);
	while (i <= ac - 1 && ft_strcmp(av[i], "--"))
	{
		if (check_authorized_flags(av[i], flags))
			return (NULL);
		i++;
	}
	return (flags);
}
