/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:00:39 by ggane             #+#    #+#             */
/*   Updated: 2016/06/07 18:52:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include "../libft/libft.h"

/* parser.c */
int		check_authorized_flags(char *to_check, int *flags);
int		*parse_flags(int ac, char **av);

/* display.c */
void	display_error_flag(char wrong_flag);
void	display_usage(void);

/* cut_parsed_flags.c */
int		check_if_directories(int ac, char **av);
char	**cut_parsed_flags(char **av);

#endif
