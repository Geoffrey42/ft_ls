/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:00:39 by ggane             #+#    #+#             */
/*   Updated: 2016/07/13 18:27:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "headers.h"
# include "typedef.h"
# include "defines.h"

/* info_line.c */
t_info				*set_directories_info(t_info *info_line, int ac, char **av);
t_info				*initialize_info_line(t_info *info_line);

/* parser.c */
int					add_flags(char *to_check, t_info *info_line, int i);
int					check_authorized_flags(char *to_check, t_info *info_line);
int					walkthrough_command_line
					(int ac, char **av, t_info *info_line);
int					parse_flags(int ac, char **av, t_info *info_line);

/* display.c */
void				display_type_file(struct stat file_stat);
void				display_rights(struct stat file_stat);
void				display_links(struct stat file_stat);
void				display_id(struct stat file_stat);
void				display_file_mode(struct stat file_stat);
void				display_size(struct stat file_stat);
char				*keep_necessary_timedata(char *long_time);
void				display_date(struct stat file_stat);
void				display_long_format(char *file);
void				display_short_format(char *file);
void				choose_format_to_display(t_data *data);
void				display_flags_error_msg(char bad_option);
void				display_total_size(long long int size);
int					check_r_flag(void *item, int type);
void				choose_infix_traversal
					(void *item, int type, t_btree *tree, 
					void (*applyf)(void *));
void				display_newline(t_data *data, t_btree *tree, int nb);
void				display_repo_names(t_data *data, t_btree *tree);
void				display_content(t_btree *tree, t_data *data);

/* sort_directories.c */
t_data				*init_meta_data(int flag, char *dir_name);
t_btree				*add_data
					(t_info *info, int (*cmpf)(void *, void *), char *dir_name,
					t_btree *sorted_dir);
t_btree				*insert_directories
					(t_info *info_line, int (*cmpf)(void *, void *), char **av);
int					check_t_flag(void *item, int type);
t_cmpf				choose_compare_function(void *item, int type);
t_btree				*put_directories_in_a_tree
					(t_info *info_line, t_btree *sorted_dir, char **av);
t_btree				*put_current_directory_in_a_tree
					(t_btree *root, t_info *info);
t_btree				*sort_directories
					(t_info *info_line, char **av, t_btree *sorted_dir);

/* call_back_functions.c */
void				cb_non_recursive_applyf(void *item);
void				cb_recursive_applyf(void *item);
void				cb_display_format(void *item);
void				cb_ft_putendl(void *str);
int					check_nanosec(void *item1, void *item2);
int					cb_ft_timecmp(void *item1, void *item2);
int					cb_ft_strcmp(void *s1, void *s2);

/* sort_content.c */
long long int		add_size(char *file, long long int size);
int					check_if_dir(char *file);
char				*create_pathname(char *parent, char *son);
t_btree				*add_content_tree
					(t_data *parent, t_btree *tree, char *file_name,
					int (*cmpf)(void *, void *));
t_btree				*put_content_in_a_tree
					(t_data *meta_data, DIR *dirp, t_btree *tree,
					int (*cmpf)(void *, void *));
t_btree				*insert_files
					(t_data *meta_data, int (*cmpf)(void *, void *));
t_btree				*sort_files(t_data *meta_data, t_btree *tree);
t_applyf			choose_apply_function(t_info *info_line);
void				sort_content(t_info *info_line, t_btree *directories);

#endif
