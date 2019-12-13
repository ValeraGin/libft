/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:03:30 by hmathew           #+#    #+#             */
/*   Updated: 2019/12/13 23:16:38 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

#include <stdlib.h>

#define GET_LENGTH(ptr) ((size_t *)(ptr))[WHERE_LENGTH]
#define GET_MEMBER_SIZE(ptr) ((size_t *)(ptr))[WHERE_MEMBER_SIZE]

void *array_new(size_t length, size_t member_size)
{
    void *ptr = malloc((length * member_size) + 2 * sizeof(size_t));
    ptr = ARRAY_POINTER(ptr);
    size_t *n_ptr = ptr;
    GET_LENGTH(n_ptr)      = length;
    GET_MEMBER_SIZE(n_ptr) = member_size;
    return ptr;
}

void array_free(void *arr)
{
    free(BASE_POINTER(arr));
}

void *array_resize(void *arr, size_t length)
{
    size_t member_size = ((size_t *)arr)[WHERE_MEMBER_SIZE];
    void *ptr = BASE_POINTER(arr);
    ptr = realloc(ptr, (length * member_size) + (2 * sizeof(size_t)));
    ptr = ARRAY_POINTER(ptr);
    ((size_t *)ptr)[WHERE_LENGTH] = length;
    return ptr;
}

void *array_resize_with_member_size(void *arr, size_t length, size_t member_size)
{
    void *ptr = BASE_POINTER(arr);
    ptr = realloc(ptr, (length * member_size) + (2 * sizeof(size_t)));
    arr = ARRAY_POINTER(ptr);
    ((size_t *)arr)[WHERE_LENGTH]      = length;
    ((size_t *)arr)[WHERE_MEMBER_SIZE] = member_size;
    return arr;
}



