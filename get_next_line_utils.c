/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmenende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:04:45 by vmenende          #+#    #+#             */
/*   Updated: 2023/11/14 16:04:47 by vmenende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char		*pointer;
	size_t		i;
	size_t		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	pointer = (char *)malloc(i + j + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		pointer[i + j] = s2[j];
		j++;
	}
	pointer[i + j] = '\0';
	return (pointer);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while ((s[i] != '\0') || !s)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}


