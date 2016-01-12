/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:28:28 by jle-quer          #+#    #+#             */
/*   Updated: 2015/12/03 15:39:18 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = ft_strnew((size_t)ft_strlen(s1) + (size_t)ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
