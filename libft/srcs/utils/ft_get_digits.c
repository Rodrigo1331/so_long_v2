/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:03:34 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/08/03 11:58:41 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_digits(long long int nb)
{
	int	digits;

	digits = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		digits = 1;
	}
	while (nb > 0)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}
