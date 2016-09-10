/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:28:09 by ggane             #+#    #+#             */
/*   Updated: 2016/09/10 14:07:33 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include "../libft/libft.h"

# define LOW_A_FLAG 1
# define LOW_T_FLAG 2
# define LOW_L_FLAG 4
# define LOW_R_FLAG 8
# define UPP_R_FLAG 16

typedef struct  s_info
{
    char        **av;
    int         ac;
    int         flags;
    int         nb_dir;
    int         dir_pos;
}               t_info;

typedef struct  s_data
{
    char        *name;
    char        *pathname;
    int         flags;
    int         error;
}

//merge_sort.c

t_list  *merge_sort_directories(void);

//sort_directories.c

t_list  *insert_directories_list(t_info *info_line);
t_list  *sort_directories(t_info *info_line);

//parser_flags.c

void            check_binary_mask(t_info *info_line, char *to_check, int j);
void            check_authorized_flags(t_info *info_line, char *to_check);
void            parse_flags(t_info *info_line);

//parser_directories.c

void            check_dir_position(t_info *info_line);
void            check_nb_directories(t_info *info_line);
void            parse_directories(t_info *info_line);

//parser.c

char            **copy_av(int ac, char **av);
t_info          *initialize_info_line(int ac, char **av);
t_info          *parse_prompt(int ac, char **av);

//display_errors.c

void            display_flag_error_msg(char bad_option);

#endif
