/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_formatted_field_out.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:30 by alngo             #+#    #+#             */
/*   Updated: 2019/10/22 10:20:39 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			number_of_byte_out(struct stat fileStat)
{
	ft_printf("%ld", (long)fileStat.st_size);
}

void			month_day_last_modified_out(struct stat fileStat)
{
	(void)fileStat;
}

void			hour_minute_last_modified_out(struct stat fileStat)
{
	(void)fileStat;
}

