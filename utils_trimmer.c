/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trimmer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:28:56 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/16 19:29:51 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *) s + i);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	while (len >= 0)
	{		
		if (s[len] == (char)c)
			return ((char *)s + len);
	len--;
	}
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen((char *)s1);
	while (len && ft_strrchr(set, s1[len]))
		len--;
	return (ft_substr(s1, 0, len + 1));
}
