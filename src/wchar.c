/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:45:04 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 23:09:59 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ASCII_MAX 0x7F
#define _6_BIT_MAX 0x3F
#define _16BIT_MASK 0xC080
#define _24BIT_MASK 0xE08080
#define _32BIT_MASK 0xF0808080

void		print_wchar(wint_t);

void		print_wstr(wchar_t);
