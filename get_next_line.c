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

size_t	get_len_stop(const char *read_buf, int start, char c_stop)
{
	size_t	cpt;

	if (!read_buf)
		return (0);
	cpt = 0;
	while (read_buf[start] && read_buf[start] != c_stop)
	{
		start++;
		cpt++;
	}
	return (cpt);
}

int	get_return_line(char *read_buf, char **line, t_struct buf_res)
{
	int		len;
	char	*tmp;
	char	*line_tmp;

	len = 0;
	if (ft_strchr(read_buf, '\n') == 0)
	{
		line_tmp = *line;
		*line = ft_strjoin(line_tmp, read_buf);
		free(line_tmp);
	}
	else
	{
		len = get_len_stop(read_buf, 0, '\n');
		tmp = ft_strsub(read_buf, 0, len);
		line_tmp = *line;
		*line = ft_strjoin(line_tmp, tmp);
		free(line_tmp);
		free(tmp);
		tmp = ft_strsub(read_buf, len + 1, (ft_strlen(read_buf) - len));
		free(buf_res->read_buf);
		buf_res->read_buf = tmp;
		return (1);
	}
	return (0);
}

int	get_read_line(int fd, char *buf_tmp, char **line, t_struct *buf_res)
{
	int	i;

	i = 0;
	if (!(buf_res->read_buf))
		buf_res->read_buf = ft_strdup("");
	if (get_return_line(buf_res->read_buf, line, buf_res) == 1)
		return (buf_res->read = 1);
	free(buf_res->read_buf);
	buf_res->read_buf = ft_strdup("");
	while (i = read(fd, buf_tmp, BUFF_SIZE))
	{
		buf_tmp[i] = 0;
		if (get_return_line(buf_tmp, line, buf_res) == 1)
			return (1);
		buf_res->read = 1;
	}
	if (i == -1)
		return (-1);
	if (buf_res->read == 1)
	{
		buf_res->read = 0;
		if (ft_strcmp("", *line) != 0)
			return (1);
	}
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	static t_struct	*buf_res;
	char			*buf_tmp;
	int				res;

	if (!line)
		return (-1);
	if ((buf_res = (t_struct*)malloc(sizeof(t_struct))) == NULL)
		return (-1);
	if (!(buf_tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	buf_tmp[0] = 0;
	*line = ft_strdup("");
	res = get_read_line(fd, buf_tmp, line, buf_res);
	if ((res == 0) || (res == -1))
	{
		free(buf_res->read_buf);
		free(buf_res);
	}
	free(buf_tmp);
	return (res);
}
