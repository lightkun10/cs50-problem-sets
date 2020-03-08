#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check usage
    if (argc != 2)
    {
        printf("Handing out a file would be nice...\n");
        return 1;
    }

    // open memory card
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Can't open file: %s\n", argv[1]);
        return 2;
    }

    // store files read
    BYTE buffer[512];
    // keep track of image
    int image_count = 0;
    // char to store filename of JPEG
    char filename[10];
    // flag for found jpeg or not
    bool already_found_jpeg = false;
    // create outfile for jpeg image
    FILE *img = NULL;

    // repeat until end of card
    while (!feof(raw_file) && fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) != 0)
    {
        // condition for jpeg header
        bool jpeg_header = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        /* start of a new jpeg? */

        // found new jpeg header and currently writing jpeg file?
        if (jpeg_header && already_found_jpeg)
        {
            // initialize start of a new image
            already_found_jpeg = false;
            // close previous file
            fclose(img);
            // increment each new jpeg file
            image_count++;
        }

        // new jpeg header?
        if (jpeg_header && !already_found_jpeg)
        {
            // start a new file
            sprintf(filename, "%03i.jpg", image_count);
            // open a new file, include writing permission
            img = fopen(filename, "w");
            // jpeg already found
            already_found_jpeg = true;
        }

        // still in the same jpeg header
        if (already_found_jpeg)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    return 0;
}
