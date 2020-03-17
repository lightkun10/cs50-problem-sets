#!/usr/bin/env python3

def main():
    text = input("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    
    grades = 0.0588 * (100 * float(letters) / float(words)) - 0.296 * (100 * float(sentences) / float(words)) - 15.8

    grade = round(grades)    
    
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


def count_letters(text):
    count_let = 0

    for letter in text:
        if letter.isalpha():
            count_let += 1
    
    return count_let

def count_words(text):
    # set counter
    count_wrds = 0

    # increment at start if it's a letter
    if text[0].isalnum():
        count_wrds += 1
    
    # loop through each text
    for i in range( (len(text) - len(text)) + 1, len(text)):
        if text[i].isspace() and text[i + 1]:
            count_wrds += 1
    return count_wrds

def count_sentences(text):
    # set counter
    count_sent = 0

    # loop through each text
    for i in range(len(text) - len(text), len(text)):
        # convert char to ascii using ord()
        if ord(text[i]) == 33 or ord(text[i]) == 46 or ord(text[i]) == 63:
            count_sent += 1
    return count_sent


if __name__ == "__main__":
    main()