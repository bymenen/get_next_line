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

char    *get_next_line(int fd)
{
    static  char    *full_str;
    char            *line;

    if  (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    full_str = read_file(fd, full_str);
    if (!full_str)
        return (NULL);
    
}

/* with read function 
we read the full file and we locate 
all the content in the variable full_str */

char    *read_file(int fd, char *full_str)
{
    int     byte;
    char    *temporal;

    temporal = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if  (!temporal)
        return (NULL);
    byte = 1;
    while (!ft_strchr_gnl(str, '\n') && (byte != 0))
    {
        byte = read(fd, temporal, BUFFER_SIZE);
        if (byte == -1)
        {
            free(temporal);
            return (NULL);
        }
        temporal[byte] = '\0';
        str = ft_strjoin_gnl(str, temporal);
    }
    free(temporal);
    return (full_str);
}