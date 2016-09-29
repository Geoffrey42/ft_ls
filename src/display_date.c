/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 08:59:49 by ggane             #+#    #+#             */
/*   Updated: 2016/09/29 10:48:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*display_year(char *long_time)
{
	char	*shorter_time;
	char	*ptr;
	char	*year;

	shorter_time = (char *)malloc(sizeof(char) * 12);
	if (!shorter_time)
		return (NULL);
	ptr = long_time + 4;
	ptr[20] = '\0';
	year = ft_strdup(ptr + 15);
	shorter_time = strncpy(shorter_time, ptr, 7);
	shorter_time[7] = '\0';
	ptr = shorter_time;
	shorter_time = ft_strjoin(shorter_time, year);
	free(ptr);
	return (shorter_time);
}

int			check_6_months(struct stat file_stat)
{
	time_t	today;

	today = time(NULL);
	if (today - file_stat.st_mtime >= 15778800)
		return (1);
	if (today - file_stat.st_mtime <= -15778800)
		return (1);
	return (0);
}

char		*keep_necessary_timedata(char *long_time)
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

	if (check_6_months(file_stat))
		date = display_year(ctime(&file_stat.st_mtime));
	else
		date = keep_necessary_timedata(ctime(&file_stat.st_mtime));
	ft_putstr(date);
	ft_putchar(' ');
}
