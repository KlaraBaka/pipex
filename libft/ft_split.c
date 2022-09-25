/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:40 by radriann          #+#    #+#             */
/*   Updated: 2021/11/11 20:53:55 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_w(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (n);
}

static char	*get_w(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (str);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		str;
	int		i;

	if (!s)
		return (0);
	str = len_w(s, c);
	i = 0;
	ptr = malloc(sizeof(char *) * (str + 1));
	if (ptr == NULL)
		return (ptr);
	while (str > i)
	{
		while (*s && *s == c)
			s++;
		ptr[i] = get_w(s, c);
		if (ptr[i] == NULL)
			ft_free(i, ptr);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
