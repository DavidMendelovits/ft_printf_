/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:39:04 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/22 18:56:49 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int			front;
	int			back;
	char		tmp;

	front = 0;
	back = ft_strlen(str) - 1;
	while (front < back)
	{
		tmp = str[front];
		str[front] = str[back];
		str[back] = tmp;
		front += 1;
		back -= 1;
	}
	return (str);
}
