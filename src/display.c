/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:41:36 by ggane             #+#    #+#             */
/*   Updated: 2016/06/30 14:16:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_type_file(struct stat file_stat)
{
	if (S_ISDIR(file_stat.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(file_stat.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(file_stat.st_mode))
		ft_putchar('b');
	else if (S_ISLNK(file_stat.st_mode))
		ft_putchar('l');
	else if (S_ISFIFO(file_stat.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(file_stat.st_mode))
		ft_putchar('s');
	else if (S_ISREG(file_stat.st_mode))
		ft_putchar('-');
}

void		display_rights(struct stat file_stat)
{
	ft_putstr((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXOTH) ? "x" : "-");
}

void		display_links(struct stat file_stat)
{
	ft_putnbr(file_stat.st_nlink);
	ft_putchar(' ');
}

void		display_id(struct stat file_stat)
{
	struct passwd	*usr_id;
	struct group	*grp_id;

	usr_id = getpwuid(file_stat.st_uid);
	ft_putstr(usr_id->pw_name);
	ft_putstr("  ");
	grp_id = getgrgid(file_stat.st_gid);
	ft_putstr(grp_id->gr_name);
	ft_putstr("  ");
}

void		display_file_mode(struct stat file_stat)
{
	display_type_file(file_stat);
	display_rights(file_stat);
	ft_putstr("  ");
}
void		display_size(struct stat file_stat)
{
	ft_putnbr(file_stat.st_size);
	ft_putchar(' ');
}

char	*keep_necessary_timedata(char *long_time)
{
	char	*shorter_time;
	char	*ptr;

	shorter_time = (char *)malloc(sizeof(char) * 13);
	if (!shorter_time)
		return (NULL);
	ptr = long_time + 4;
	shorter_time = strncpy(shorter_time, ptr, 12);
	shorter_time[12] = '\0';
	return (shorter_time);
}

void		display_date(struct stat file_stat)
{
	char	*date;

	date = keep_necessary_timedata(ctime(&file_stat.st_mtime));
	ft_putstr(date);
	ft_putchar(' ');
}

void		display_long_format(char *file)
{
	struct stat		file_stat;

	if (lstat(file, &file_stat) < 0)
		return ;
	display_file_mode(file_stat);
	display_links(file_stat);
	display_id(file_stat);
	display_size(file_stat);
	display_date(file_stat);
	display_short_format(file);
}

void		display_short_format(char *file)
{
	ft_putendl(file);
}

void		choose_format_to_display(t_data *data)
{
	if (data->flags & LOW_L_FLAG)
		display_long_format(data->file_name);
	else
		display_short_format(data->file_name);
}

void		display_flags_error_msg(char bad_option)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(bad_option, 2);
	ft_putendl_fd("\nusage: ls [-Raltr] [file ...]", 2);
}

void		display_total_size(long long int size)
{
	long long int	total;

	total = size / 512;
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

int			check_r_flag(void *item, int type)
{
	t_info	*info;
	t_data	*data;

	info = NULL;
	data = NULL;
	if (type)
	{
		info = (t_info *)item;
		return (info->flags & LOW_R_FLAG);
	}
	else
	{
		data = (t_data *)item;
		return (data->flags & LOW_R_FLAG);
	}
}

void		choose_infix_traversal
			(void *item, int type, t_btree *tree, void (*applyf)(void *))	
{
	if (check_r_flag(item, type))
		btree_apply_rev_infix(tree, applyf);
	else
		btree_apply_infix(tree, applyf);
}

void		display_repo_names(t_data *data, t_btree *tree)
{
	if ((data->flags & LOW_R_FLAG) == 0 && tree->left != NULL && tree->right != NULL)
		ft_putchar('\n');
	if (data->file_name[0] != '.' && tree != NULL)
	{
		ft_putstr(data->file_name);
		ft_putendl(":");
	}
}

void		display_content(t_btree *tree, t_data *data)
{
	void	(*applyf)(void *);

	if (data->flags & LOW_L_FLAG)
		display_total_size(data->total_size);
	if (data->nb_directories > 0)
		display_repo_names(data, tree);
	applyf = &cb_display_format;
	choose_infix_traversal(data, 0, tree, applyf);
	if (data->flags & LOW_R_FLAG && tree->left != NULL && tree->right != NULL)
		ft_putchar('\n');
}
