#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// function declaration
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // getting user input
    string text = get_string("Text: ");

    // counting letters
    // printf("%i letter(s)\n", count_letters(text));

    // counting words
    // printf("%i word(s)\n", count_words(text));

    // counting sentences
    // printf("%i sentence(s)\n", count_sentences(text));

    // count the grade
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float grades = 0.0588 * (100 * (float)letters / (float)words) - 0.296 * (100 * (float)sentences / (float)words) - 15.8;

    int grade = round(grades);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
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

        if (isspace(text[i]) && isgraph(text[i + 1]))
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
        if ((int)text[i] == 33 || (int)text[i] == 46 || (int)text[i] == 63)
        {
            sentences++;
        }
    }

    return sentences;
}