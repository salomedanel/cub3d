/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:12:28 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/13 16:23:06 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	launcher_events(t_glb *glb)
{
	if (glb->rc->cmds[0])
		go_forward(glb);
	if (glb->rc->cmds[1])
		go_backward(glb);
	if (glb->rc->cmds[2])
		go_left(glb);
	if (glb->rc->cmds[3])
		go_right(glb);
	if (glb->rc->cmds[4])
		rotate_left(glb);
	if (glb->rc->cmds[5])
		rotate_right(glb);
}

int	display(t_glb *glb)
{
	raycasting_loop(glb);
	launcher_events(glb);
	return (0);
}
