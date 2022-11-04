/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorgiordani01 <victorgiordani01@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:09:00 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/03 17:50:56 by victorgiord      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formats(const char format, va_list args)
{
	if (format == 's')
		ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		ft_putchar(va_arg(args, int));
	else if (format == 'd')
		ft_putnbr(va_arg(args, int));
	else if (format == 'x')
		ft_printhexa(va_arg(args, size_t), BASEHEXAMIN);
	else if (format == 'X')
		ft_printhexa(va_arg(args, size_t), "0123456789ABCDEF");
	else if (format == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'i')
		ft_putnbr(va_arg(args, int));
	else if (format == '%')
		ft_putchar('%');
	else
		ft_putchar(format);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			formats(*(++s), args);
		else
			ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (0);
}

/*int	main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	printf("Me : \n");
	ft_printf("%s%x%s%%%i %d\n", "Victor", 2000, "Giordani", 075, 030);
	printf("Expected : \n");
	printf("%s%x%s%%%i %d\n", "Victor", 2000, "Giordani", 075, 030);
	return (0);
}*/