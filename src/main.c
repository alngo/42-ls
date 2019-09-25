/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:14:29 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 11:24:58 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("%c - %c - %c - %c - %c\n", 'a', 'b', 'c', 'd', 'e');
	ft_printf("%C - %C - %C - %C - %C\n", 044, 0242, 004471, 020254, 0201510);
	ft_printf("%s\n", "coucou");
	ft_printf("%-10.3s\n", "coucou");
	ft_printf("%S\n", "指事字");
	ft_printf("%ls\n", "指事字");
	ft_printf("%.10d\n", 10);
	ft_printf("%10o\n", 10);
	ft_printf("%x\n", 10);
	ft_printf("%X\n", 10);
	ft_printf("%#x\n", 10);
	ft_printf("%#X\n", 10);
	ft_printf("%#o\n", 10);
	ft_printf("%#.10X\n", 10);
	ft_printf("%#.10o\n", 10);
	ft_printf("%p\n", &ac);
	ft_printf("%/RC%/Go%/Bu%/Yc%/Mo%/Cu \n", &ac);

	ft_printf("\n----------------------------------------\n");

	printf("%c - %c - %c - %c - %c\n", 'a', 'b', 'c', 'd', 'e');
	printf("%C - %C - %C - %C - %C\n", 044, 0242, 004471, 020254, 0201510);
	printf("%s\n", "coucou");
	printf("%-10.3s\n", "coucou");
	printf("%S\n", (wchar_t *)"指事字");
	printf("%ls\n", (wchar_t *)"指事字");
	printf("%.10d\n", 10);
	printf("%10o\n", 10);
	printf("%x\n", 10);
	printf("%X\n", 10);
	printf("%#x\n", 10);
	printf("%#X\n", 10);
	printf("%#o\n", 10);
	printf("%#.10X\n", 10);
	printf("%#.10o\n", 10);
	printf("%p\n", &ac);
	return (1);
}
