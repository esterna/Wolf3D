/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:23:02 by esterna           #+#    #+#             */
/*   Updated: 2017/10/24 16:51:55 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int map[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int				get_color(t_frame *frame)
{
	int		we;

	we = 0;
	frame->ray[0] -= frame->dy;
	frame->ray[1] -= frame->dx;
	we = (frame->ray[1] += frame->dx) ? 1 : 0;
	if (frame->dx < 0.0 && we == 1)
		return (0xD10D81);
	if (frame->dx > 0.0 && we == 1)
		return (0xFF6400);
	if (frame->dy > 0.0 && we == 0)
		return (0xB40505);
	if (frame->dy < 0.0 && we == 0)
		return (0xFFDC00);
	return (0xFFFFFF);
}

void			draw_wall(t_frame *frame, int x, int angle)
{	
	double		wall_h;
	int			y0;
	int			i;

	i = 0;
	frame->distance = sqrt(pow(frame->ray[1] - frame->curr_pos[1], 2.0) + pow(frame->ray[0] - frame->curr_pos[0], 2.0)
							* cos((90.0 - angle) * (M_PI / 180.0)));
	wall_h = ceil((64.0 / frame->distance) * frame->dis_to_pr);
	wall_h = (wall_h > WIN_Y) ? WIN_Y : wall_h;
	y0 = (WIN_Y / 2.0) - (wall_h / 2.0);
	y0 = y0 < 0.0 ? 0.0 : y0;
	while (wall_h > 0.0)
	{
		frame->data[x + y0 * WIN_X + i * WIN_X] = get_color(frame);
		i++;
		wall_h--;
	}
}

int				ray_caster(t_frame *frame)
{
	int			i;
	double		angle;
	double		rot_ang;

	if (frame->redraw == 0)
		return (0);
	frame->redraw = 0;
	i = 0;
	angle = 60.0;
	rot_ang = 60.0 / (double)WIN_X;
	while (i < 1280)
	{
		if (frame->view_point[0] >= 0.0)
			frame->ray[0] = floor(frame->curr_pos[0] / 64.0) * 64.0 + 64.0;
		else
			frame->ray[0] = floor(frame->curr_pos[0] / 64.0) * 64.0 - 1.0;
		frame->ray[1] = frame->curr_pos[1] + (frame->curr_pos[0] - frame->ray[0]) / tan(angle * (M_PI / 180.0));
		frame->dy = (frame->view_point[0] >= 0.0) ? 64.0 : -64.0;
		frame->dx = 64.0 / tan(angle * (M_PI / 180.0));
		while (map[(int)floor(frame->ray[0] / 64.0)][(int)floor(frame->ray[1] / 64.0)] == 0)
		{
			frame->ray[0] += frame->dy;
			frame->ray[1] += frame->dx;
		}
		draw_wall(frame, i, angle);
		angle += rot_ang;
		i++;
	}
	mlx_put_image_to_window(frame->mlx, frame->window, frame->image, 0, 0);
	return (0);
}

int				main(void)
{
	t_frame		*frame;
	int		bpp;
	int		size_line;
	int		endian;

	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->redraw = 1;
	frame->curr_pos[0] = 64.0;
	frame->curr_pos[1] = 64.0;
	frame->view_point[0] = 0.0;
	frame->view_point[1] = 1.0;
	frame->dis_to_pr = (WIN_X / 2.0) / tan(30.0 * (M_PI / 180.0));
	frame->mlx = mlx_init();
	frame->window = mlx_new_window(frame->mlx, WIN_X, WIN_Y, "Wolf3D");
	frame->image = (int *)mlx_new_image(frame->mlx, WIN_X, WIN_Y);
	frame->data = (int *)mlx_get_data_addr(frame->image,
			&bpp, &size_line, &endian);
	mlx_hook(frame->window, 6, 0, ray_caster, frame);
	mlx_loop_hook(frame->mlx, ray_caster, frame);
	mlx_loop(frame->mlx);
//	ray_caster(frame);
	return (0);
}
/*
		for(int x = 0; x < w; x++)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
			double rayPosX = posX;
			double rayPosY = posY;
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
			//which box of the map we're in
			int mapX = int(rayPosX);
			int mapY = int(rayPosY);

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (rayPosX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (rayPosY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (worldMap[mapX][mapY] > 0) hit = 1;
			}
			//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
			if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
			else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
			int lineHeight = (int)(h / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + h / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)drawEnd = h - 1;

			//choose wall color
			ColorRGB color;
			switch(worldMap[mapX][mapY])
			{
				case 1:  color = RGB_Red;  break; //red
				case 2:  color = RGB_Green;  break; //green
				case 3:  color = RGB_Blue;   break; //blue
				case 4:  color = RGB_White;  break; //white
				default: color = RGB_Yellow; break; //yellow
			}

			//give x and y sides different brightness
			if (side == 1) {color = color / 2;}

			//draw the pixels of the stripe as a vertical line
			verLine(x, drawStart, drawEnd, color);
		}
		//timing for input and FPS counter
		oldTime = time;
		time = getTicks();
		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		print(1.0 / frameTime); //FPS counter
		redraw();
		cls();

		//speed modifiers
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
		readKeys();
		//move forward if no wall in front of you
		if (keyDown(SDLK_UP))
		{
			if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
			if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
		}
		//move backwards if no wall behind you
		if (keyDown(SDLK_DOWN))
		{
			if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
			if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
		}
		//rotate to the right
		if (keyDown(SDLK_RIGHT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = dirX;
			dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
			dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
		}
		//rotate to the left
		if (keyDown(SDLK_LEFT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = dirX;
			dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
			dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
		}
	wolf3d_exit(frame);
	return (0);
}
*/
