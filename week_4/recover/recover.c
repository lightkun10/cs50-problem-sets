#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure user ran program with two words at prompt
    if (argc != 2)
    {
        printf("Usage: make sure to give a file as argument\n");
        return 1;
    }

    // open file(presumably, a memory card)
    // pointer to inputed data
    FILE *filesrc = fopen(argv[1], "r");
    if (filesrc == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 2;
    }

    // place to store file to be read
    BYTE buffer[512] = {0};
    // use to be a filename, incremented each file read
    int image_count = 0;
    // char to store filename of JPEG
    char filename[10];

    // create outfile for jpeg image
    FILE *img = NULL;

    //boolean for start of new jpeg or not
    bool startjpeg = false;

    // read memory card until end of the card
    while (true)
    {
        // read files
        size_t bytes_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, filesrc);

        // if end of file and no bytes being read anymore
        if (feof(filesrc) && bytes_read == 0)
        {
            break;
        }

        // boolean for jpeg header
        bool jpeg_header = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // put this at top, so at next iteration, this check first
        // if start of another jpeg file
        if (jpeg_header && img != NULL)
        {
            fclose(img);
            image_count++;
        }

        // if start of jpeg
        if (jpeg_header)
        {
            sprintf(filename, "%03i.jpg", image_count);
            img = fopen(filename, "w");
        }

        // continue write file
        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    // success
    return 0;
}
