#include <stdio.h>
#include <cs50.h>

// Function Prototype
int get_size(void);
int print_space(void);
int print_bricks(void);

int main(void)
{
    // Ask User for row height (do while loop)

    int n = get_size();
    int x = 1;

    // print the pyramid with that row height
   for (int i = 1; i < n + 1; i++)
   {
    if (i == x)
    {
        for (int j = 1; j < (n-x) + 1; j++)
        {
            printf(" ");
        }

        for (int j = 1; j < x + 1; j++)
        {
            printf("#");
        }

        printf("\n");
        x = x + 1;
    }
   }

    // row height = n = number of # in the bottom row
    // x = number of spaces

    // Row formula: (n-x) times "spaces", n-(n-x) times "#"

    // looping this for n times
}


// Do while loop:

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





// Mock code
// if (i == 0)
    // )
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 0; j < 1; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // else if (i == 1)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 0; j < 2; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // else if (i == 2)
    // {
    //     for (int j = 0; j < 1; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // else if (i == 3)
    // {
    //     for (int j = 0; j < 0; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }