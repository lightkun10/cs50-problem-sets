#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate through each height/row
    for (int h = 0; h < height; h++)
    {
        // iterate through each width/column
        for (int w = 0; w < width; w++)
        {
            // get the shade of grey(average of rgb)
            int avg_color = round(
                    (
                        (float)image[h][w].rgbtRed + (float)image[h][w].rgbtGreen + (float)image[h][w].rgbtBlue)
                        / 3);

            // update the rgb
            image[h][w].rgbtRed = avg_color;
            image[h][w].rgbtGreen = avg_color;
            image[h][w].rgbtBlue = avg_color;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float ogRed = (float)image[h][w].rgbtRed;
            float ogGreen = (float)image[h][w].rgbtGreen;
            float ogBlue = (float)image[h][w].rgbtBlue;

            int sepRed = round(.393 * ogRed + .769 * ogGreen + .189 * ogBlue);
            int sepGreen = round(.349 * ogRed + .686 * ogGreen + .168 * ogBlue);
            int sepBlue = round(.272 * ogRed + .534 * ogGreen + .131 * ogBlue);

            int sepiaRed = sepRed > 255 ? 255 : sepRed;
            int sepiaGreen = sepGreen > 255 ? 255 : sepGreen;
            int sepiaBlue = sepBlue > 255 ? 255 : sepBlue;

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int middle = width / 2;

    for (int h = 0; h < height; h++)
    {
        int o = 1;

        for (int w = 0; w < middle; w++)
        {
            swap(&image[h][w], &image[h][width - o]);
            o++;
        }
    }

    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    // temp
    RGBTRIPLE temp1;
    RGBTRIPLE temp2;

    // assign to temps
    temp1 = *a;
    temp2 = *b;

    // swap
    *a = temp2;
    *b = temp1;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // make a copy of image
    RGBTRIPLE imageCopy[height][width];

    // for each row/height
    for (int h = 0; h < height; h++)
    {
        // for each column/width
        for (int w = 0; w < width; w++)
        {
            float addRed = 0.00;
            float addGreen = 0.00;
            float addBlue = 0.00;
            int counter = 0;

            // for each row/height above, middle and below
            for (int row_add = -1; row_add < 2; row_add++)
            {
                // edge case
                if (h + row_add < 0 || h + row_add > width - 1)
                {
                    continue; // go to next number
                }

                // for each column/width left, middle and right
                for (int col_add = -1; col_add < 2; col_add++)
                {
                    // edge case
                    if (w + col_add < 0 || w + col_add > width - 1)
                    {
                        continue; // go to next number
                    }

                    addRed += image[h + row_add][w + col_add].rgbtRed;
                    addGreen += image[h + row_add][w + col_add].rgbtGreen;
                    addBlue += image[h + row_add][w + col_add].rgbtBlue;
                    counter++;
                }
            }

            // add each row-col of image copy with the added rgbt color
            imageCopy[h][w].rgbtRed = round(addRed / counter);
            imageCopy[h][w].rgbtGreen = round(addGreen / counter);
            imageCopy[h][w].rgbtBlue = round(addBlue / counter);
        }
    }

    // assign the original image's rgbt with each of copies
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col].rgbtRed = imageCopy[row][col].rgbtRed;
            image[row][col].rgbtGreen = imageCopy[row][col].rgbtGreen;
            image[row][row].rgbtBlue = imageCopy[row][col].rgbtBlue;
        }
    }

    return;
}