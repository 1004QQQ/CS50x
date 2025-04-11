#include <cs50.h>
#include <stdio.h>

void printrow(int bricks, int height);

int main(void)
{
    int height;
    do
    {
        // prompt user for height
        height = get_int("Height: ");
    }
    while (1 > height || height > 8);

    for (int i = 0; i < height; i++)
        printrow(i + 1, height);
}

// function that prints a row
void printrow(int bricks, int height)
{
    for (int i = 0; i < height - bricks; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    for (int i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
