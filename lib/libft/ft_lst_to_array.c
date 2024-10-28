/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:06:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/08/27 11:52:47 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_array(t_list **lst)
{
	t_list	*tmp;
	char	**array;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*lst)
	{
		array[i] = ft_strdup((*lst)->content);
		lst = &(*lst)->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
