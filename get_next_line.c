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
    line = ft_getline(full_str);
    full_str = ft_getrest(full_str);
    return (line);
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

/*tras sacar la line a leer, conseguimos el primer
salto de linea */

char    *ft_getline(char *full_str)
{
    int     i;
    char    *line;

    i = 0;
    if (!full_str[i])
        return (NULL);
    while (full_str[i] && full_str[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
    i = 0;
    while (full_str[i] && full_str[i] != '\n')
    {
        line[i] = full_str[i];
        i++;
    }
    if (full_str[i] == '\n')
    {
        line[i] = full_str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}


char    *ft_getrest(char *full_str)
{
    int     i;
    int     j;
    char    *restof;

    i = 0;
    while (full_str[i] && full_str[i] != '\n')
        i++;
    if (!full_str[i])
    {
        free(full_str);
        return (NULL);
    }
    restof = (char *)malloc(sizeof(char) * (ft_strlen_gnl(full_str) - i + 1));
    if (!restof)
        return (NULL);
    restof[j] = '\0';
    free(full_str);
    return (restof);
}
