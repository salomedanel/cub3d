/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:48:18 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/05 13:52:16 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float   get_deltadist(float raydir)
{
    float   deltadist;

    if (!raydir)
        return (deltadist = 2147483647.0);
    else
        return (deltadist = fabs(1 / raydir));
}