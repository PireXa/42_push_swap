/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:55:40 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/31 12:51:58 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strndup(const char *s1, int start, int end, char *str)
{
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	while (s1[start] && start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

int	strcount(char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{	
			i++;
			flag = 1;
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			flag = 0;
		}
		count++;
	}
	if (flag == 1)
		count--;
	return (count);
}

static char	**make_arrays(char **strarray, char *s, char c, int i)
{
	int	start;
	int	end;
	int	a;

	start = 0;
	end = 0;
	a = 0;
	while (i < strcount((char *)s, c))
	{
		while (s[a] == c && s[a++])
		{
			end++;
			start++;
		}
		while (s[a] != c && s[a++])
			end++;
		strarray[i] = ft_strndup(s, start, end, strarray[i]);
		a++;
		start = a;
		i++;
		end++;
	}
	strarray[i] = NULL;
	return (strarray);
}

char	**ft_split(const char *s, char c, char **strarray)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!strarray)
		return (0);
	strarray = make_arrays(strarray, (char *)s, c, i);
	return (strarray);
}
