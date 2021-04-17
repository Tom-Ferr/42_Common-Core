#include <stdio.h>

int main() {
	// Image

    const int image_width = 256;
    const int image_height = 256;
	int r;
	int g = image_height;
	int b = (255.999 * 0.25);

    // Render

	printf("P3\n%i %i\n255\n", image_width, image_height);
	while (--g >= 0)
	{
		r = 0;
		while (r < image_width)
		{
			printf("%i %i %i\n", r, g, b);
			r++;
		}
	}
	return 0;
}
