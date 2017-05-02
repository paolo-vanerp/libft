/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:04:21 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/05/02 00:20:54 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	use_base(const char *str)
{
	if (ft_tolower(str[1]) == 'x')
		return (ft_atoi_base(&str[2], 16));
	else
		return (ft_atoi_base(&str[1], 8));
}

int			ft_atoi(const char *str)
{
	int nb;
	int i;
	int sign;

	nb = 0;
	sign = 1;
	if (str)
	{
		i = 0;
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '0')
			return (use_base(&str[i]));
		else
		{
			if (str[i] == '-')
				sign = -1;
			if (str[i] == '+' || str[i] == '-')
				i++;
			nb = ft_atoi_base(&str[i], 10);
		}
	}
	return (nb * sign);
}
