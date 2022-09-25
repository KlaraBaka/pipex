/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:38:26 by radriann          #+#    #+#             */
/*   Updated: 2021/10/27 15:23:31 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	r;

	r = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (*s1 != '\0')
		str[r++] = *s1++;
	while (*s2 != '\0')
		str[r++] = *s2++;
	str[r] = '\0';
	return (str);
}
