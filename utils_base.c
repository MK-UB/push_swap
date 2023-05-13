/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:39:50 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/13 15:51:28 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		if ((str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		else
			ft_error();
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (*src != '\0')
		new[i++] = *src++;
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*str;

	if (!str1 && str2)
		return (ft_strdup(str2));
	if (!str2 || !str1 || !*str2)
		ft_error();
	len_s1 = ft_strlen(str1);
	len_s2 = ft_strlen(str2);
	i = 0;
	j = 0;
	str = malloc((sizeof(char)) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (str1[j])
		str[i++] = str1[j++];
	while (*str2)
		str[i++] = *str2++;
	str[i] = '\0';
	free(str1);
	return (str);
}
