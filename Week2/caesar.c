#include <cs50.h>
#include <ctype.h>
// #include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration
void encipher(string plaintext, int key);

// Constant
const int ALPHABET_SIZE = 26;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; // Input error
    }

    // Argument contains only digit characters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1; // Input error
        }
    }
    // Convert argument to integer
    int key = atoi(argv[1]);

    // Get user plaintext
    string plaintext = get_string("plaintext: ");

    // Encipher by shifting (wrap around), preserve case
    encipher(plaintext, key);
}

// Function to encipher text by key
void encipher(string plaintext, int key)
{
    // Initialise new string to store ciphertext
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
                cipher[i] = 'A' + (alphabetical + key) % ALPHABET_SIZE;
            }

            // Lowercase
            if (islower(plaintext[i]))
            {
                int alphabetical = plaintext[i] - 'a';
                cipher[i] = 'a' + (alphabetical + key) % ALPHABET_SIZE;
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }
    cipher[n] = '\0';
    printf("ciphertext: %s\n", cipher);
}
