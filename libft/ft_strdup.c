/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:51:05 by radriann          #+#    #+#             */
/*   Updated: 2021/12/28 17:52:28 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	l;

	l = ft_strlen(s1);
	ptr = (char *)malloc((l + 1) * sizeof(char));
	if (ptr == NULL)
		return (ptr);
	return (ft_memcpy(ptr, s1, (l + 1)));
}
