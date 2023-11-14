/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmenende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:04:23 by vmenende          #+#    #+#             */
/*   Updated: 2023/11/14 16:04:25 by vmenende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *get_next_line(int fd)
{
    static  char    *full_str;
    char            *line;

    if  (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    full_str = read_function(fd, full_str);

}

/* with read function 
we read the full file and we locate 
all the content in the variable full_str */

char *read_function(int fd, char *full_str)
{
    int     i;
    char    *temporal;

    temporal = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if  (!temporal)
        return (NULL);
    bytes
    i = 0;
    while (fd)
    {
        full_str[i] = fd;
        i++;
    }
    return (full_str);
}