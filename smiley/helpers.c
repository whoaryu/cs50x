#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    int k,l;
    for (k = 0; k < height; k++)
    {
        for (l = 0; l < width; l++)
        {
            if (image[k][l].rgbtRed == 0x00 && image[k][l].rgbtGreen == 0x00 && image[k][l].rgbtBlue == 0x00)
            {
                image[k][l].rgbtRed = 0xff;
            }
        }
    }
}