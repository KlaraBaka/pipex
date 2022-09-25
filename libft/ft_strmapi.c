/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:31:12 by radriann          #+#    #+#             */
/*   Updated: 2021/10/26 21:12:35 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*m;

	i = 0;
	if (!s || !f)
		return (NULL);
	m = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (m == NULL)
		return (0);
	while (s[i] && i < ft_strlen(s))
	{
		m[i] = f(i, s[i]);
		++i;
	}
	m[i] = '\0';
	return (m);
}
