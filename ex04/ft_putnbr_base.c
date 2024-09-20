/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:37:33 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/18 13:37:34 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + sizeof(char)) + 1);
}

// Checks the base for bad chars and compares it
// to its old self for duplicates.
int	bad_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = 0;
		while (base[j] != '\0')
		{
			if (j == i && base[j + 1] != '\0')
				j++;
			else if (base[j] == base[i] && base[j + 1] != '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (bad_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
		return ;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
	}
	write(1, &(base[nbr % base_len]), 1);
}

// int	main(void)
// {
// 	write(1, "### Tests des radixes\n", 23);
// 	ft_putnbr_base(-69420, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-69420, "poneyvif");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-69420, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-69420, "0123456789abcdef");
// 	write (1, "\n### Tests des edge-cases\n", 26);
// 	ft_putnbr_base(-69420, "");
// 	ft_putnbr_base(-69420, "a");
// 	ft_putnbr_base(-69420, "012345678+");
// 	ft_putnbr_base(-69420, "012345678-");
// 	ft_putnbr_base(-69420, "0012345678");
// 	ft_putnbr_base(-69420, "0123456780");
// }
