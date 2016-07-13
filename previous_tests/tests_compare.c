/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 13:31:17 by ggane             #+#    #+#             */
/*   Updated: 2016/07/11 16:15:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"
#include <fcntl.h>
#define BUF_SIZE 1

char	*fill_ft_ls(char *ft_ls, char *ft_ls_buf)
{
	int		fd;
	int		i;
	char	buf[BUF_SIZE + 1];
	int		ret;

	i = 0;
	fd = open(ft_ls, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		i++;
	}
	ft_ls_buf = (char *)malloc(sizeof(char) * i);
	if (ft_ls_buf == NULL)
		return (NULL);
	close(fd);
	fd = open(ft_ls, O_RDONLY);
	read(fd, ft_ls_buf, i);
	close(fd);
	return (ft_ls_buf);
}
char	*fill_ls(char *ls, char *ls_buf)
{
	int		fd;
	int		i;
	char	buf[BUF_SIZE + 1];
	int		ret;

	i = 0;
	fd = open(ls, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		i++;
	}
	ls_buf = (char *)malloc(sizeof(char) * i);
	if (ls_buf == NULL)
		return (NULL);
	close(fd);
	fd = open(ls, O_RDONLY);
	read(fd, ls_buf, i);
	close(fd);
	return (ls_buf);
}

int		compare_ls(char *ls, char *ft_ls)
{
	char	*ls_buf = NULL;
	char	*ft_ls_buf = NULL;

	ls_buf = fill_ls(ls, ls_buf);
	ft_ls_buf = fill_ft_ls(ft_ls, ft_ls_buf);
	if (ft_strcmp(ls_buf, ft_ls_buf))
		printf("FAUX !!!\n\n-->ls :\n%s\n-->ft_ls :\n%s\n", ls_buf, ft_ls_buf);
	else
		printf("OK !\n");
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		compare_ls(av[1], av[2]);
	return (0);
}
