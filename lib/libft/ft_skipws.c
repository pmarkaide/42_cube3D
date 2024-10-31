/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:55:32 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/10/31 13:50:09 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h" 

char	*ft_skipws(char *str)
{
    while (*str && (*str == ' ' || *str == '\t'))
        str++;
    return (str);
}