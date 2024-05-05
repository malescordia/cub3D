
**STUFF**

*Vector*
- A vector typically refers to a one-dimensional array, it is often used to store a collection of elements of the same data type. It's called a vector because, conceptually, it represents a quantity with both magnitude and direction, similar to how a mathematical vector behaves. However, in the context of programming languages like C, the term "vector" is often used more loosely to refer to an array, without necessarily implying any geometric interpretation. It's essentially a sequential collection of indexes. So while the name "vector" might imply a sense of direction and magnitude, in C programming, it's more about organizing and accessing data in a linear manner.

*Fisheye*
- In the context of raycasting, fisheye refers to a distortion effect that occurs when calculating the distance between the player and a wall. Without correcting for fisheye, the walls appear curved or distorted, which is not the desired effect. To fix fisheye, the calculated distance is multiplied by the cosine of the angle difference between the ray angle and the player's view angle. This correction ensures that the walls are rendered with the correct height and perspective.

*Cosine*
- In a right triangle, the cosine of an angle is the ratio of the length of he adjacent side to the length of the hyotenuse.

       /|
      / | adjacent
     /  |
    /___|
  hypotenuse

cos(angle) = adjacent / hypotenuse

*Sine*
- In a right triangle, the sine of an angle is the ratio of the length of the opposite side to the length of th hypotenuse.

       /|
      / | opposite
     /  |
    /___|
  hypotenuse

sin(angle) = opposite / hypotenuse

*Hypotenuse*
- In a right triangle, the hypotenuse is the longest side, which is directly opposite to the right angle.


**MATH LIBRARY FUNCTIONS**

*Trigonometric functions*
- sin() Computes the sine of an angle.
- cos() Computes the cosine of an angle.
- tan() Computes the tangent of an angle.

*Square root function*
- sqrt() Calculates the square root of a number.

*Absolute value function*
- fabs() Returns the absolute value of a floating-point number.

*Power function*
- pow() Raises a number to a specified power.

*Rounding functions*
- ceil() Rounds a number up to the nearest integer.
- floor() Rounds a number down to the nearest integer.

*Degree to radian conversion*
- deg2rad() Converts degrees to radians.

*Radian to degree conversion*
- rag2deg() Converts radians to degrees.


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
- Creates a new image object in memory. This is image object can be thought of as a canvas or buffer where graphical data can be stored.

char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
- It is used to access the pixel data of a previously created image, or in other words, obtain a pointer to the pixel data of an image.

int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
- Renders images onto windows. By specifying x and y we control where the image will be placed within the window.

void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
- Loads an XPM file from disk into memory. It returns a pointer to the loaded image object. This project can then be used to render the image.
- If the function fails to load the image it returns **NULL**.


**RAYCASTING**

Raycasting is a rendering technique to create a 3D prespective in a 2D map.

The basic idea of raycasting is as follows: the map is a 2D square grid and each square can either be 0 (no wall) or 1 (a wall with a certain color or texture).

For every **x** of the screen (for every vertical stripe of the screen) send out a ray that starts at the player position and with a direction that depends on both the player’s looking direction, and the **x-coordinate** of the screen. Then, let this ray move forward on the 2D map until it hits a map square that is a wall. If it hits a wall, calculate the distance of this hit point to the player and use this distance to calculate how high this wall has to be drawn on the screen: the further away the wall, the smaller it is on screen, and the closer, the higher it appears to be. These are all 2D calculations.

To find the first wall that a ray encounters on its way we have to let it start at the player's position, and then all the time, check wether or not the ray has touched a wall, then the loop can stop, calculate the distance and draw the wall with the correct height. If the ray has not hit a wall yet we have to trace it further: add a certain value to its position in the direction the ray is going and for this new position, again, check if a wall has been hit or not. Keep doing this until finally a wall is hit.

**PROBLEM** It's impossible to find which square the ray hits immediately with a single formula because a computer can only check a finite number of positions on the ray. Many raycasters add a constant value to the ray each step but then there's a chance that it may miss a wall. The more positions we check, the smaller the chance that the computer won't detect a wall but the more calculations are needed. For infinite precision with this method, an infinitely small step size is required, and thus, an infinite amount of calculations would be needed. **SOLUTION** There's a better method that requires only very few calculations and yet will detect every wall: the idea is to check at every side of a wall the ray will pass through.

The position of the player is always a vector **(an x and y coordinate)**. We want to make the direction the player is facing a vector too, so the direction is determinated by two values: the **x** and **y** coordinates of the direction. A direction vector can be seen as follows: if you draw a line in the direction the player looks then every point of the line is the sum of the **position of the player** and a **multiple of the direction vector**. The length of a direction vector doesn't really matter, only its direction. Multiplying **x** and **y** by the same value changes the length but keeps the same direction.

This method with vectors also requires an extra vector which is the camera plane vector. In our case raycasting happens in a 2D map so the camera will not really be a plane but a line, and is represented with a single vector. The camera plane should always be perpendicular in the direction vector, it represents the surface of the computer screen. The position of the player, which is a single point, is a point in front of the camera plane. A certain ray of a certain **x-coordinate** of the screen is then the ray that starts at this player position and goes through that position on the screen or this the camera plane.

If the direction vector and the camera plane vector have the same length the **Field Of Vision (FOV)** will be 90 degree's.

If the direction vector is shorter than the camera plane, the **FOV** will be larger than 90 degree's (180 is the maximum, if the direction vector is close to 0) and you will have a much wider vision.

When the player rotates, the camera has to rotate so both direction vector and the plane vector have to be rotated, then, the rays will all automaticaly rotate as well. To rotate a vector, multiply it with the rotation matrix.

To calculate the **distance between the player and the nearest wall**, we can use the following algorithm:

1. Define and initialize some basic attributes needed for the projection:

|---------------------------------------------------------------------------------------------------------|
| *Attribute*  | |          *Description*                   | |             *Value*                       |
|---------------------------------------------------------------------------------------------------------|
|    FOV        |     The field of view of the player        |                60                          |
|---------------|--------------------------------------------|--------------------------------------------|
|   HFOV        |        Half of the player's FOV            |                30                          |
|---------------|--------------------------------------------|--------------------------------------------|
|  Ray angle    |    Angle of the player view's direction    |  N (270º), S (90º), W (180º), E (0º)       |
|---------------|--------------------------------------------|--------------------------------------------|
| Ray increment |     Angle difference between one ray       |        2 * HFOV / window_width             |
|    angle      |           and the next one.                |                                            |
|---------------|--------------------------------------------|--------------------------------------------|
|  Precision    |  Size of 'steps' taken every iteration     |                50                          |
|---------------|--------------------------------------------|--------------------------------------------|
|   Limit       | Limit of the distance the player can view  |                11                          |
|---------------|--------------------------------------------|--------------------------------------------|
| Player's pos  | Center of the square where the player is   | (int)(player_x + 0.5),(int)(player_y + 0.5)|
|---------------|--------------------------------------------|--------------------------------------------|

2. From the player's position, we move the ray foward incrementing the x's and y's coordinates of the ray.

    ray.x += ray_cos;
    ray.y += ray_sin;

    where ray_cos and ray_sin arer the following:

    ray_cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
    ray_sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;

3. Repeat step 2 until we reach the limit or we hit a wall.

4. Calculate the distance between the player's and the ray's position using the euclidean distance:

    distance = sqrt(powf(x - pl.x - 0.5, 2.) + powf(y - pl.y - 0.5, 2.));

5. Fix **fisheye**

    distance = distance * cos(degree_to_radians(ray_angle - g->ray.angle))

This algorithm is repeated **window_width** times, in example, in every iteration we increment the angle until we have been through all the field of view. This distance is really helpful to calculate the height of the wall height: wall_height = (window_height / (1.5 * distance));