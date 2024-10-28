/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_extra_spaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:48:45 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/08/20 14:05:19 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_extra_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]) || (i > 0 && !ft_isspace(str[i - 1])))
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}
