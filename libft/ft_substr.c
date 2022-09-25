/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:01:47 by radriann          #+#    #+#             */
/*   Updated: 2022/03/22 20:30:41 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t len)
{
	char	*sd;
	size_t	i;

	i = 0;
	while (s1[i] && i < len)
		i++;
	sd = malloc(sizeof(char) * i + 1);
	if (sd == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		sd[i] = s1[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (0);
	if (start > ft_strlen(s))
	{
		str = malloc (sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = ft_strndup(&s[start], len);
	if (str == NULL)
		return (NULL);
	return (str);
}
