#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration
void encipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // Key validation
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1; // Input error
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1; // Input error
    }
    // Argument contains only digit characters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must contain only alphabetical characters.\n");
            return 1; // Input error
        }
    }
    // One more condition where case insensitive, key must not contain repeated characters.
    int checker[26] = {0};
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        int index = toupper(argv[1][i]) - 'A';
        if (checker[index] == 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else
        {
            checker[index] = 1;
        }
    }

    // Get plaintext
    string plaintext = get_string("plaintext: ");

    // Encipher and print
    encipher(plaintext, argv[1]);
}

// Function to encipher text by key
void encipher(string plaintext, string key)
{
    // For each alphabetic character, determine which letter it maps to, preserve case
    int n = strlen(plaintext);
    char cipher[n + 1];
    for (int i = 0; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Uppercase
            if (isupper(plaintext[i]))
            {
                int alphabetical = plaintext[i] - 'A';
                cipher[i] = toupper(key[alphabetical]);
            }

            // Lowercase
            if (islower(plaintext[i]))
            {
                int alphabetical = plaintext[i] - 'a';
                cipher[i] = tolower(key[alphabetical]);
            }
        }

        // Leave non-alphabetic as it is
        else
        {
            cipher[i] = plaintext[i];
        }
    }
    cipher[n] = '\0';
    printf("ciphertext: %s\n", cipher);
}
