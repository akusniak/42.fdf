/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:47:46 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:37 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	print_and_return(char c, va_list args)
{
	size_t	r;

	r = 0;
	if (c == 'c')
		r = ft_putchar(va_arg(args, int));
	else if (c == 's')
		r = ft_putstr_printf(va_arg(args, const char *));
	else if (c == 'p')
		r = ft_print_p(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		r = ft_print_id(va_arg(args, int));
	else if (c == 'u')
		r = ft_print_u(va_arg(args, unsigned int));
	else if (c == 'x')
		r = ft_print_x(va_arg(args, unsigned int));
	else if (c == 'X')
		r = ft_print_xx(va_arg(args, unsigned int));
	else if (c == '%')
		r = ft_putchar('%');
	return (r);
}

static int	is_arg(char c2)
{
	if ((c2 == 'c') || (c2 == 's') || (c2 == 'p')
		|| (c2 == 'd') || (c2 == 'i') || (c2 == 'u')
		|| (c2 == 'x') || (c2 == 'X') || (c2 == '%'))
		return (1);
	else
		return (0);
}

static int	ft_check(char c1, char c2)
{
	if (c1 == '%' && is_arg(c2))
		return (1);
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		r;
	int		i;

	if (!s)
		return (-1);
	i = -1;
	r = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		else if (ft_check(s[i], s[i + 1]))
			r += print_and_return(s[++i], args);
		else
			r += ft_putchar(s[i]);
	}
	va_end(args);
	return (r);
}
