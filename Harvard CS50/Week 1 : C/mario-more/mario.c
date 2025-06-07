#include <cs50.h>
#include <stdio.h>

int get_size(void);

int main(void)
{
    int n = get_size();
    int x = 1;
    // Pyramid on the left
    for (int i = 1; i < n + 1; i++)
   {
    if (i == x)
    {
        // Spaces
        for (int j = 1; j < (n-x) + 1; j++)
        {
            printf(" ");
        }

        // Bricks
        for (int j = 1; j < x + 1; j++)
        {
            printf("#");
        }

        // Space between pyramids
        printf("  ");

        // Pyramid on the right
        for (int j = 1; j < x + 1; j++)
        {
            printf("#");
        }

        printf("\n");

        x = x + 1;
    }
   }
}















// Do while loop
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    return n;
}
