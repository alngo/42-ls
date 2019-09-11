/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:50:42 by alngo             #+#    #+#             */
/*   Updated: 2019/06/03 09:21:07 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ctype(int c)
{
	static unsigned char tab[129] = {0,
	BB, BB, BB, BB, BB, BB, BB, BB,
	BB, CN, CN, CN, CN, CN, BB, BB,
	BB, BB, BB, BB, BB, BB, BB, BB,
	BB, BB, BB, BB, BB, BB, BB, BB,
	SP, PU, PU, PU, PU, PU, PU, PU,
	PU, PU, PU, PU, PU, PU, PU, PU,
	XI, XI, XI, XI, XI, XI, XI, XI,
	XI, XI, PU, PU, PU, PU, PU, PU,
	PU, XP, XP, XP, XP, XP, XP, UP,
	UP, UP, UP, UP, UP, UP, UP, UP,
	UP, UP, UP, UP, UP, UP, UP, UP,
	UP, UP, UP, PU, PU, PU, PU, PU,
	PU, XO, XO, XO, XO, XO, XO, LO,
	LO, LO, LO, LO, LO, LO, LO, LO,
	LO, LO, LO, LO, LO, LO, LO, LO,
	LO, LO, LO, PU, PU, PU, PU, BB,
	};

	if (c >= 0 && c <= 127)
		return (tab[c + 1]);
	return (0);
}
