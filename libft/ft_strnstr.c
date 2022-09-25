/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:39:38 by radriann          #+#    #+#             */
/*   Updated: 2021/11/10 14:54:57 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		while (haystack[i + k] && needle[k] == haystack[i + k] \
		&& needle[k] && i + k < len)
			k++;
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		if (haystack[i + k] == '\0' || i + k == len)
			return (0);
		i++;
	}
	return (0);
}
