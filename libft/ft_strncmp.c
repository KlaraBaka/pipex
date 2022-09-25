/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:21:02 by radriann          #+#    #+#             */
/*   Updated: 2022/03/25 21:51:18 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i] && --n)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

// int main()
// {
// 	int i;
// 	char *s1;
// 	char *s2;
// 	int	k;

// 	i = 0;
// 	s1 = "PATH"
// 	s2 = "doedjvwoejvwoeirjvPATH=/pol/pol/dfg:/lop/pol/lkj:/usr/pol"
// 	k = ft_strncmp(s2, s1, 4);
// 	printf("%d", k);
// }