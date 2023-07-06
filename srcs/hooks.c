/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:47:49 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/06 17:17:38 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    key_press(int keycode, t_glb *glb)
{
    if (keycode == XK_w)
        go_forward(glb);
    if (keycode == XK_s)
        go_backward(glb);
    if (keycode == XK_a)
        go_left(glb);
    if (keycode == XK_d)
        go_right(glb);
    if (keycode == XK_Left)
        rotate_left(glb);
    if (keycode == XK_Right)
        rotate_right(glb);
    if (keycode == XK_Escape)
        quit(glb);
    return (0);
}