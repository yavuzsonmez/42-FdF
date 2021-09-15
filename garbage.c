
/* bresenham not formatted */
void plot_line (t_data *img, t_matrix *matrix, t_parse *data, t_screen *screen, size_t i)
{

	(void)screen;
	size_t row;

	row = 0;
	if (i == data->col - 1)
	{
		row++;
		i++;
	}
	while (i < data->row * data->col)
	{
		//

		int x1 = matrix[i+1].x;
		int x0 = matrix[i].x;
		int y1 = matrix[i+1].y;
		int y0 = matrix[i].y;
		//

		int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
		int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
		int err = dx + dy, e2; /* error value e_xy */

		for (;;){  /* loop */
		my_mlx_pixel_put(img, x0, y0, matrix[i].color);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	  }
	i++;
	}
}



/* old one */

void drawline(t_data *img, t_matrix *matrix, t_parse *data, t_screen *screen, size_t i)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;
	int fade;
	while (i < data->row * data->col)
	{
		dx = abs(matrix[i + 1].x) - abs(matrix[i].x);
		dy = abs(matrix[i + 1].y) - abs(matrix[i].y);
		x = matrix[i].x;
		y = matrix[i].y;
		p = 2 * dy - dx;
		fade = 0;
		while (x < matrix[i + 1].x)
		{
			if (p >= 0)
			{
				if (x >= 0 && x < screen->SCREEN_W && y >= 0 && y < screen->SCREEN_H)
					my_mlx_pixel_put(img, x, y, matrix[i].color - fade);
				y++;
				p = p + 2 * dy - 2 * dx;
			}
			else
			{
				if (x >= 0 && x < screen->SCREEN_W && y >= 0 && y < screen->SCREEN_H)
					my_mlx_pixel_put(img, x, y, matrix[i].color - fade);
				p = p + 2 * dy;
			}
			//fade += 3;
			x++;
		}
		i++;
	}
	i = 0;
	while (i < data->row * data->col - data->col)
	{
		dx = matrix[i + 1].x - matrix[i].x;
		dy = matrix[i + data->col].y - matrix[i].y;
		x = matrix[i].x;
		y = matrix[i].y;
		p = 2 * dx - dy;
		fade = 0;
		while (y < matrix[i + data->col].y)
		{
			if (p >= 0)
			{
				if (x >= 0 && x < screen->SCREEN_W && y >= 0 && y < screen->SCREEN_H)
					my_mlx_pixel_put(img, x, y, matrix[i].color - fade);
				x++;
				p = p + 2 * dx - 2 * dy;
			}
			else
			{
				if (x >= 0 && x < screen->SCREEN_W && y >= 0 && y < screen->SCREEN_H)
					my_mlx_pixel_put(img, x, y, matrix[i].color - fade);
				p = p + 2 * dx;
			}
			//fade += 3;
			y++;
		}
		i++;
	}

}

/* old one */

void
plot_line (int x0, int y0, int x1, int y1)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2; /* error value e_xy */

  for (;;){  /* loop */
    setPixel (x0,y0);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}


/* Display points only from isometric projection */


/*
	int x;
	int y;
	while (i < (data.row * data.col))
	{

		x = (matrix[i].x - matrix[i].y) * cos(0.3) * screen.SCALE + 960;
		y = ((matrix[i].x + matrix[i].y) * sin(0.3) - matrix[i].z) * screen.SCALE + 540;
		if (x >= 0 && x < screen.SCREEN_W && y >= 0 && y < screen.SCREEN_H)
			my_mlx_pixel_put(&img, x, y, matrix[i].color);
		i++;
	}
*/