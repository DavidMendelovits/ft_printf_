/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:58:18 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 14:53:18 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#define WOW() printf("->%s\n", __func__)

typedef struct		s_opt
{
	struct s_flags	*flags;
	int				width:1;
	int				_width;
	int				precision:1;
	int				_precision;
	char			length[3];
	char			spec;
}					t_opt;

typedef struct		s_checks
{
	int				flag_check:1;
	int				width_check:1;
	int				precision_check:1;
	int				length_check:1;
}					t_checks;

typedef struct		s_content
{
	va_list			*arg_list;
	char			*format;
	int				r_val;
}					t_content;

typedef struct		s_flags
{
	int				left_align:1;
	int				prepend_sign:1;
	int				prepend_space:1;
	int				prefix:1;
	int				prepend_zero:1;
}					t_flags;

typedef union
{
	char			character;
	char			*str;
	intmax_t		num;
	uintmax_t		u_num;
	void			*ptr;
}					t_argument;

int					ft_printf(const char *format, ...);
int					parse_format(const char *format, va_list arg_list);
void				init_content(t_content *content, char *format, va_list *args);
void				init_opt(t_opt **o);
void				free_opt(t_opt **o);
void				print_options(t_opt *o);
t_flags 			*init_flags_struct(void);
int					read_flags(t_opt **o, t_content *content, int ptr);
int					read_width(t_opt **o, t_content *content, int ptr);
int					read_precision(t_opt **o, t_content *content, int ptr);
int					read_length(t_opt **o, t_content *content, int ptr);
int					spec_check(char c);
int					flag_check(char c);
int					is_length_char(char c);