#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);
    for (int row = 0; row < height; row++)
    {
        for (int space = height - row - 1; space > 0; space--)
        {
            printf(" ");
        }
        for (int hashtag = 0; hashtag < row + 1; hashtag++)
        {
            printf("#");
        }
        printf("\n");
    }
}