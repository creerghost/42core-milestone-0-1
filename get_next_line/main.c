/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:49:08 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/18 00:02:58 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*filename;
	int		lines_count;
	char	*line;

	filename = argv[1];
	lines_count = 0;
	if (argc == 1)
    fd = 0;
  else if (argc != 2)
		return (printf("Enter ONE input\n"), 0);
  else
    fd = open(filename, O_RDONLY);
	printf("file descriptor: %i\n", fd);
	while (lines_count++ < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
