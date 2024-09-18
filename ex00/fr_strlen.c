/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:29:36 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/18 12:29:38 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + sizeof(char)) + 1);
}

// int	main(void)
// {
// 	printf("'hello'         : %d\n", ft_strlen("hello"));
// 	printf("'Hello, world'  : %d\n", ft_strlen("Hello, world!"));
// 	printf("'Hello\\0, world': %d\n", ft_strlen("Hello\0, world!"));
// }
