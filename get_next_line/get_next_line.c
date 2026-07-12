/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:47:06 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/18 00:03:36 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*return_line(char *remainder)
{
	char	*res;
	int		i;

	i = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	res = (char *)malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		res[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		res[i] = remainder[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	int		i;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
		return (free(remainder), NULL);
	new_remainder = ft_strdup(&remainder[i + 1]);
	if (!new_remainder)
		return (free(remainder), NULL);
	free(remainder);
	return (new_remainder);
}

static char	*read_and_join(int fd, char *remainder)
{
	char	*buf;
	char	*tmp;
	ssize_t	bytes_read;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(remainder), NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), free(remainder), NULL);
		if (bytes_read > 0)
		{
			tmp = remainder;
			buf[bytes_read] = 0;
			remainder = ft_strjoin(tmp, buf);
			free (tmp);
			if (!remainder)
				return (free(buf), NULL);
		}
	}
	free (buf);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*returned_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	if (!remainder)
		remainder = ft_strdup("");
	remainder = read_and_join(fd, remainder);
	if (!remainder || !remainder[0])
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	returned_line = return_line(remainder);
	remainder = update_remainder(remainder);
	return (returned_line);
}
