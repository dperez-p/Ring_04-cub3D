/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:15:59 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/16 10:21:54 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t len;
	char *copy;

	len = 0;
	while (len < n && s[len] != '\0')
	{
		len++;
	}
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return NULL;
	ft_memcpy(copy, s, len);
	copy[len] = '\0';
	return copy;
}