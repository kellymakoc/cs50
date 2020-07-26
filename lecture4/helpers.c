#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float k;
    for (int h = 0; h < height; h++)
    {
        // Iterare over width
        for (int w = 0; w < width; w++)
        {
            // Calculate the average of rgbt
            k = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3.0);

            // Update rgbt
            image[h][w].rgbtBlue = k;
            image[h][w].rgbtGreen = k;
            image[h][w].rgbtRed = k;
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int h = 0; h < height; h++) // for every colour in the array
    {
        for (int w = 0; w < width; w++)
        {
            // change the colour tone
            sepiaRed = (round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue));
            sepiaGreen = (round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue));
            sepiaBlue = (round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
                image[h][w].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
                image[h][w].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
                image[h][w].rgbtBlue = sepiaBlue;
            }
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporary[((width - 1) / 2) + 1]; // Making a temporary array

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // Assign the first half of the pixels to the temp array
        {
            temporary[j] = image[i][j];
        }

        for (int j = 0; j < width / 2; j++) // Move the second half of the pixels to the first half
        {
            image[i][j] = image[i][width + (-j - 1)];
        }

        for (int j = 0; j < width / 2; j++) // Move the pixels from temp to the second half
        {
            image[i][width + (-j - 1)] = temporary[j];
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE holder[height][width];
    int red;
    int green;
    int blue;
    float counter;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = 0;
            green = 0;
            blue = 0;
            counter = 0.0;
            //for the blur box
            //nested loop to check one box around
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    if ((i + a) >= 0 && (i + a) < height && (j + b) >= 0 && (j + b) < width)
                    {
                        counter++;
                        red += image[i + a][j + b].rgbtRed;
                        green += image[i + a][j + b].rgbtGreen;
                        blue += image[i + a][j + b].rgbtBlue;

                    }
                }
            }
            holder[i][j].rgbtRed = round(red / counter);
            holder[i][j].rgbtGreen = round(green / counter);
            holder[i][j].rgbtBlue = round(blue / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = holder[i][j];
        }
    }
    return;
}
