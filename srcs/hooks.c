/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:47:49 by tmichel-          #+#    #+#             */
/*   Updated: 2023/07/12 18:06:35 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_glb *glb)
{
	if (keycode == XK_Escape)
		quit(glb);
	if (keycode == XK_w)
		glb->rc->cmds[0] = 1;
	if (keycode == XK_s)
		glb->rc->cmds[1] = 1;
	if (keycode == XK_a)
		glb->rc->cmds[2] = 1;
	if (keycode == XK_d)
		glb->rc->cmds[3] = 1;
	if (keycode == XK_Left)
		glb->rc->cmds[4] = 1;
	if (keycode == XK_Right)
		glb->rc->cmds[5] = 1;
	return (0);
}

void	key_release_norm(int keycode, t_glb *glb)
{
	if (keycode == XK_d)
	{
		if(glb->rc->cmds[3])
			glb->rc->cmds[3] = 0;
	}
	if (keycode == XK_Left)
	{
		if(glb->rc->cmds[4])
			glb->rc->cmds[4] = 0;
	}
	if (keycode == XK_Right)
	{
		if(glb->rc->cmds[5])
			glb->rc->cmds[5] = 0;
	}	
}

int	key_release(int keycode, t_glb *glb)
{
	if (keycode == XK_w)
	{
		if(glb->rc->cmds[0])
			glb->rc->cmds[0] = 0;
	}
	if (keycode == XK_s)
	{
		if(glb->rc->cmds[1])
			glb->rc->cmds[1] = 0;
	}
	if (keycode == XK_a)
	{
		if(glb->rc->cmds[2])
			glb->rc->cmds[2] = 0;
	}
	key_release_norm(keycode, glb);
	return (0);
}

void	hooks(t_glb *glb)
{
	mlx_loop_hook(glb->mlx, display, glb);
	mlx_hook(glb->window, KeyPress, 1L << 0, key_press, glb);
	mlx_hook(glb->window, KeyRelease, 1L << 1, key_release, glb);
	mlx_hook(glb->window, 17, 1L << 0, quit, glb);
}