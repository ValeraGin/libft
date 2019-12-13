/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:03:10 by hmathew           #+#    #+#             */
/*   Updated: 2019/12/13 20:17:03 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H

#include <stddef.h>

#define BASE_POINTER(ptr) (ptr - (2 * sizeof(size_t)))
#define ARRAY_POINTER(ptr) (ptr + (2 * sizeof(size_t)))

#define WHERE_LENGTH      (-1)
#define WHERE_MEMBER_SIZE (-2)

void *array_new(size_t length, size_t member_size);
void array_free(void *arr);
void *array_resize(void *arr, size_t length);
void *array_resize_with_member_size(void *arr, size_t length, size_t member_size);

#endif
