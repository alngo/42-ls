/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:46:45 by alngo             #+#    #+#             */
/*   Updated: 2019/09/25 09:46:49 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void				format_color(void (*outc)(char),\
		const char **fmt)
{
	char	color;

	(*fmt)++;
	color = ft_upper(**fmt);
	if (color == 'R')
		buffer_out(outc, RED, COLOR_LENGTH);
	else if (color == 'G')
		buffer_out(outc, GREEN, COLOR_LENGTH);
	else if (color == 'B')
		buffer_out(outc, BLUE, COLOR_LENGTH);
	else if (color == 'Y')
		buffer_out(outc, YELLOW, COLOR_LENGTH);
	else if (color == 'M')
		buffer_out(outc, MAGENTA, COLOR_LENGTH);
	else if (color == 'C')
		buffer_out(outc, CYAN, COLOR_LENGTH);
	else if (color == 'X')
		buffer_out(outc, NOCOLOR, NOCOLOR_LENGTH);
}
