/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:00:21 by radriann          #+#    #+#             */
/*   Updated: 2021/10/26 22:22:10 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd ('-', fd);
		}
		if (n < 10)
			ft_putchar_fd ((n + '0'), fd);
		else
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
	}
}
