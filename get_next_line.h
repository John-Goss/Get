/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:24:44 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/07 18:28:05 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32;

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_struct
{
	int				read;
	char			*read_buf;
}					t_struct;

int	get_next_line(int const fd, char **line);
int	get_read_line(int fd, char *buf_tmp, char **line, t_struct *buf_res);
int	get_return_line(char *read_buf, char **line, t_struct buf_res);
size_t	get_len_stop(const char *read_buf, int start, char c_stop);

#endif
