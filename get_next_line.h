/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:24:44 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/12 12:46:07 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_struct
{
	int				fd;
	char			buf[BUFF_SIZE + 1];
	char			*save_buf;
	struct s_struct	*next;
}					t_struct;

int					get_next_line(int const fd, char **line);
int					get_read_line(int const fd, char **line, t_struct *struc);
int					get_return_line(char **line, t_struct *struc);
void				get_create_line(int const fd, t_struct *struc);
t_struct			*get_new_struct(int const fd, t_struct *next);

#endif
