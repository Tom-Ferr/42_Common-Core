#include "mlx.h"
#include <unistd.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

void	ft_putchar_fd(char c, int fd)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	// if (n == -2147483648)
	// 	ft_putstr_fd("-2147483648", fd);
	//else
	//{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	//}
}

int draw_square(t_vars *vars)
{
	int px = 125;
	int py = 125;
	while (px <= 375) {
		mlx_pixel_put (vars->mlx, vars->win, px, 125, 0xFF0000);
		px++;
	}
	while (py <= 375) {
		mlx_pixel_put (vars->mlx, vars->win, 375, py, 0xFF0000);
		py++;
	}
	while (px >= 125) {
		mlx_pixel_put (vars->mlx, vars->win, px, 375, 0xFF0000);
		px--;
	}
	while (py >= 125) {
		mlx_pixel_put (vars->mlx, vars->win, 125, py, 0xFF0000);
		py--;
	}
	return (0);
}

int key_pressed(int keycode, t_vars *vars)
{
	static int px;
	static int py;
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	else
	{
		mlx_pixel_put (vars->mlx, vars->win, px, 250, 0xFF0000);
		mlx_pixel_put (vars->mlx, vars->win, 250, py, 0x0000FF);
		px++;
		py++;
		//ft_putnbr_fd(keycode, 1);
	}
	return 0;
}
int main()
{
	t_vars      vars;

   vars.mlx = mlx_init();
   vars.win = mlx_new_window(vars.mlx, 500, 500, "mlx_test");
   mlx_key_hook(vars.win, key_pressed, &vars);
   draw_square(&vars);
   mlx_loop(vars.mlx);
	return 0;
}
