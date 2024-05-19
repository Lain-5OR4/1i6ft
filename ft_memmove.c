/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:41:07 by sebiko            #+#    #+#             */
/*   Updated: 2024/05/03 17:35:10 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char src[] = "0987654321";
    char dst[] = "1234567890";
    char src1[] = "0987654321";
    char dst2[] = "1234567890";
    //printf("src: %s\n", src);
    //printf("dst: %s\n", dst);
    //ft_memmove(dst, src, 5);
    //memmove(dst2, src1, 5);
    //printf("dst: %s\n", dst);
    //printf("dst2: %s\n", dst2);
    //memmove(NULL, src1, 5); // segfault
    // memmove(dst, NULL, 5); // segfault
    // memmove(NULL, NULL, 5); // OK
    printf("NULL NULL -> %p\n", memmove(NULL, NULL, 5)); // OK
    return (0);
}
*/
