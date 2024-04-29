
**MINILIBX**

void *mlx_init();
- Sets up environment for creating graphical windows.

void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
- Creates a window.

int mlx_loop(void *mlx_ptr);
- Keeps the program running when included in the last part of the program.

int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
- Major and powerfull function that handles all inputs.
- Can receive key_press, key_release, mouse click, close button click, etc based on the x_event value.

void *mlx_new_image(void *mlx_ptr, int width, int height);
char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

**RAYCASTING**

Raycasting is a rendering technique to create a 3D prespective in a 2D map. Raycasting is not the same as raytracing! Raycasting is a fast semi-3D technique that works in realtime even on 4MHz graphical calculators, while raytracing is a realistic rendering technique that supports reflections and shadows in ture 3D scenes.

The basic idea of raycasting is as follows: the map is a 2D square grid and each square can either be 0 (no wall) or 1 (a wall with a certain color or texture).

For every **x** of the screen (for every vertical stripe of the screen) send out a ray that starts at the player position and with a direction that depends on both the player’s looking direction, and the **x-coordinate** of the screen. Then, let this ray moves forward on the 2D map until it hits a map square that is a wall. If it hits a wall, calculate the distance of this hit point to the player and use this distance to calculate how high this wall has to be drawn on the screen: the further away the wall, the smaller it is on screen, and the closer, the higher it appears to be. These are all 2D calculations.

To find the first wall that a ray encounters on its way we have to let it start at the player's position, and then all the time, check wether or not the ray is inside a wall. If it's inside a wall(hit) then the loop can stop, calculate the distance and draw the wall with the correct height. if the ray position is not in a wall we have to trace it further: add a certain value to its position, in the direction of the direction of this ray and for this new position, again check if it's inside a wall or not. Keep doing this until finally a wall is hit.

It's impossible to find which square the ray hits immediatly with a single formula because a computer can only check a finite number of positions on the ray. Many raycasters add a constant value to the ray each step but then there's a chance that it may miss a wall. The more positions you check, the smaller the chance that the computer won't detect a wall but the more calculations are needed. For infinite precision with this method, an infinitely small step size is required, and thus, an infinite amount of calculations would be needed. There's a better method that requires only very few calculations and yet  will detect every wall: the idea is to check at every side of a wall the ray will pass through. We give each square width 1 so each side of a wall is an integer value and the places in between have a value after the point. Now the step size isn't constant, it depends on the distance to the next side.

The position of the player is always a **vector(an x and y coordinate)**. We want to make the direction the player is facing a vector too, so the direction is determinated by two values: the **x** and **y** coordinates of the direction. A direction vector can be seen as follows: if you draw a line in the direction the player looks then every point of the line is the sum of the **position of the player** and a **multiple of the direction vector**. The length of a direction vector doesn't really matter, only its direction. Multiplying **x** and **y** by the same value changes the length but keeps the same direction.

This method with vectors also requires an extra vector which is the camera plane vector. Our case raycasting happens in a 2D map so the camera will not really be a plane but a line, and is represented with a single vector. The camera plane should always be perpendicular in the direction vector, it represents the surface of the computer screen. The position of the player, which is a single point, is a point in front of the camera plane. A certain ray of a certain **x-coordinate** of the screen is then the ray that starts at this player position and goes through that position on the screen or this the camera plane.

If the direction vector and the camera plane vector have the same length the **Field Of Vision (FOV)** will be 90 degree's.

If the direction vector is shorter than the camera plane, the **FOV** will be larger than 90 degree's (180 is the maximum, if the direction vector is close to 0) and you will have a much wider vision.

When the player rotates, the camera has to rotate so both direction vector and the plane vector have to be rotated, then, the rays will all automaticly rotate as well. To rotate a vector, multiply it with the rotation matrix.