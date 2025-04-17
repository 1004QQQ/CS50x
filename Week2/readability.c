#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function declarations
int count_letter(string text);
int count_word(string text);
int count_sentence(string text);

// Program that calculates the approximate grade level needed to comprehend some text
int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Count number of letters, words and sentences in the text
    int letters = count_letter(text);
    int words = count_word(text);
    int sentences = count_sentence(text);

    // Coleman-Liau index, where L is the average number of letters per 100 words in the text, and S
    // is the average number of sentences per 100 words in the text.
    float letters_l = (float) letters / words * 100;
    float sentences_s = (float) sentences / words * 100;

    float index = 0.0588 * letters_l - 0.296 * sentences_s - 15.8;

    // Print grade level
    // Round score to nearest whole number
    int level = round(index);

    // Grade levels: Before Grade 1, Grade X (X = 1 to 15 inclusive, rounded to nearest integer),
    // Grade 16+ (16 or higher)
    if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", level);
    }
}

// Counting letters
int count_letter(string text)
{
    int letter_count = 0;
    // Loop to iterate over each array element and check if it's a letter with ctype.h
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

// Counting words
int count_word(string text)
{
    // Find the number of spaces in the text and add 1
    int word_count = 0;
    // Loop to iterate over each array element and check if it's a word with ctype.h
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            word_count++;
        }
    }
    return word_count + 1;
}

// Counting sentences
int count_sentence(string text)
{
    int sentence_count = 0;
    // Period, exclamation or question mark all indicate the end of sentence.
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
