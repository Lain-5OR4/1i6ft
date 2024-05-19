/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:39:29 by sebiko            #+#    #+#             */
/*   Updated: 2024/05/19 19:08:54 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	if (!dst && !dstsize)
		return (len);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*
#include <string.h>
#include <stdio.h>
int main(){
    char str1[50] = "Hello";
    char str2[50] = "World!!";
    char str3[50] = "Hello";
    char str4[50] = "World!!";
    size_t n = 3;
    // printf("%lu\n", strlcat(str1, str2, n)); // OK
    // printf("%lu\n", strlcat(NULL, str2, n)); // segfault
    // printf("%lu\n", strlcat(str1, NULL, n)); // segfault
    // printf("%lu\n", strlcat(str1, NULL, 0)); // segfault
    printf("%lu\n", strlcat(NULL, str2, 0)); // OK
    printf("%s\n", str1);
    printf("%s\n", str3);
    return 0;
}
*/
