/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:48:02 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/07 18:23:59 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_read_line(char *buff_tmp)
{
	int	i;

	i = 0;
	while (buff_tmp[i] && buff_tmp[i] != '\n')
	{
		if (buff_tmp[i] == '\n')
			return(0);
		i++;
	}
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char		*buff = NULL;
	char			buff_tmp[BUFF_SIZE + 1];
	int				i;
	int				ret;

	while (ret > 0 && fd)
	{
		ret = read(fd, buff_tmp, BUFF_SIZE);
		buff_tmp[BUFF_SIZE] = '\0';
		if (!(get_read_line(buff_tmp))
			return (0);
	}
	return (0);
}
