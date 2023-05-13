/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:21:49 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/13 17:18:31 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

int	ft_counter(char *av)
{
	int	i;
	int	elements;

	elements = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == ' ' && av[i + 1] != ' ' && av[i + 1] != '\0')
			i++;
		if (av[i] != ' ' && av[i + 1] == ' ')
			elements++;
		i++;
	}
	return (elements);
}

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
void max_handler(char **str)
{
	int a = 0;
	while(str[a])
	{
		if(ft_strlen(str[a]) > ft_strlen("+2147483647"))
		{
			write(1, "Error\n", 7);
			exit(0);
		}
		else if(ft_atoi(str[a]) > INT_MAX || ft_atoi(str[a]) < INT_MIN)
		{
			write(1, "Error\n", 7);
			exit(0);
		}
		a++;
	}
}

char	**ft_splitter(t_plist *content, int ac, char **av)
{
	int			x;
	char		*str;
	char		**splt;
	char		*ss;

	str = NULL;
	x = 1;
	while (x != ac)
	{
		ss = ft_strtrim(av[x], " ");
		// printf("-----[%s]  [%p]\n", ss, ss);
		str = ft_strjoin(str, ss);
		free(ss);
		if (!*str)
			ft_error();
		str = ft_strjoin(str, " ");
		x++;
	}
	content->elements = ft_counter(str);
	splt = ft_split(str, ' ');
	free (str);
	max_handler(splt);
	if (!ft_checker(splt, content->elements))
		ft_error();
	ft_isequal(splt, content->elements);
	return (splt);
}
