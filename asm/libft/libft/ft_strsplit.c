/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:15:21 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:53:02 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *d, char c)
{
	const char	*s;
	int			count;
	int			flag;

	flag = 0;
	count = 0;
	s = d;
	while (*s != '\0')
	{
		while (*s != c && *s != '\0')
		{
			flag = 1;
			s++;
		}
		if (flag == 1)
		{
			count++;
			flag = 0;
		}
		if (*s != '\0')
			s++;
	}
	return (count);
}

static int	count_let(const char *s, char c)
{
	int count;

	count = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = ft_strsub(s, 0, count_let(s, c));
		if (arr[i] == NULL)
			return (NULL);
		s = s + count_let(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
