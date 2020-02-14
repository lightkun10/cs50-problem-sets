#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int row;
    int column;
    int hash;
  do
  {
    height = get_int("Enter size: ");
  } while (height < 1 || height > 8);

  for (row = 0; row < height; row++)
  { // for row
    for (column = height - 1; column > row; column--)
    {
        // printf("%i", column);
        printf(" ");
    }

    for(hash = -1; hash < row; hash++)
    {
        // printf("%i", hash);
        printf("#");
    }

    // printf("%i", row);
    printf("\n");
  }
}
