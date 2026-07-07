/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:51:52 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/06 20:33:03 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_matrix(char **list)
{
    int i;

    i = 0;
    while (list[i] != NULL)
    {
        free(list[i]);
        i++;
    }
    free(list);
}

