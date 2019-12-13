/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:11:59 by hmathew           #+#    #+#             */
/*   Updated: 2019/12/13 17:12:14 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*˙
**		DESCRIPTION
**	The realloc() function allocate memory.  The allocated memory is aligned
**	such that it can be used for any data type, including AltiVec- and
**	SSE-related types.
**	-------------------------------------------------------------------------
**	The realloc() function tries to change the size of the allocation pointed
**	to by ptr to size, and returns ptr.  If there is not enough room to enlarge
**	the memory allocation pointed to by ptr, realloc() creates a new allocation,
**	copies as much of the old data pointed to by ptr as will fit to the new
**	allocation, frees the old allocation, and returns a pointer to the allocated
**	memory.  If ptr is NULL, realloc() is identical to a call to malloc() for
**	size bytes.  If size is zero and ptr is not NULL, a new, minimum sized
**	object is allocated and the original object is freed.  When extending a
**	region allocated with calloc(3), realloc(3) does not guarantee that the
**	additional memory is also zero-filled.
**		RETURN VALUES
**	If successful, realloc() function return a pointer to allocated memory.
**	If there is an error, they return a NULL pointer and set errno to ENOMEM.
**	For realloc(), the input pointer is still valid if reallocation failed.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}
