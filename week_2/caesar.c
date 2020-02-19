#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_digit(string arg);

int main(int argc, string argv[])
{
    if (argc == 2 && check_digit(argv[1]))
    {
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        // convert the plaintext ASCII into normal integer
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // if it is a lowercase
            if (islower(plaintext[i]))
            {
                // convert ASCII to alphabet index
                // shift the index using formula
                // get it back to ASCII
                printf("%c", (((plaintext[i] - 97) +key) %26) + 97);
            }
            // if it is a uppercase
            else if (isupper(plaintext[i]))
            {
                // convert ASCII to alphabet index
                // shift the index using formula
                // get it back to ASCII
                printf("%c", (((plaintext[i] - 65) +key) %26) + 65);
            }
            // if it is not an alphabet
            else
            {
                printf("%c", plaintext[i]);
            }

        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

// check if each character argument is all digit
bool check_digit(string arg)
{
    for (int i = 0, n = strlen(arg); i < n; i++)
    {
        int length = 0;
        if (isdigit(arg[i]))
        {
            length++;
        }
        else
        {
            return false;
        }
    }

    return true;
}