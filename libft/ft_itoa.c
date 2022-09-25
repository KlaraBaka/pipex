/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:39:10 by radriann          #+#    #+#             */
/*   Updated: 2021/11/11 20:52:29 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int nb)
{
	long	len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*zero(int num, char *str)
{
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	i;

	i = len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (str);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	zero(n, str);
	while (n > 0)
	{
		str[--i] = (char)(n % 10) + 48;
		n = n / 10;
	}
	i--;
	return (str);
}
