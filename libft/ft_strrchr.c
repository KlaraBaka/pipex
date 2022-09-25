/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:02:45 by radriann          #+#    #+#             */
/*   Updated: 2021/10/22 22:39:04 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			str = ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		str = ((char *)&s[i]);
	return (str);
}
