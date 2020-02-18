#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// function declaration
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // getting user input
    string text = get_string("Text: ");

    // counting letters
    printf("%i letter(s)\n", count_letters(text));

    // counting words
    printf("%i word(s)\n", count_words(text));

    // counting sentences
    printf("%i sentence(s)\n", count_sentences(text));
}



int count_letters(string text)
{
    // set counter
    int letters = 0;

    // loop through each text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // increment counter if it is alphanumeric
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}



int count_words(string text)
{
    // set counter
    int words = 0;

    // increment at start if it's a letter
    if (isalnum(text[0]))
    {
        words++;
    }

    // loop through each text
    for (int i = 1, n = strlen(text); i < n; i++)
    {

        if (isspace(text[i]) && isalpha(text[i+1]))
        {
            words++;
        }
    }

    return words;
}



int count_sentences(string text)
{
    // set counter
    int sentences = 0;

    // loop through each text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63)
        {
            sentences++;
        }
    }

    return sentences;
}