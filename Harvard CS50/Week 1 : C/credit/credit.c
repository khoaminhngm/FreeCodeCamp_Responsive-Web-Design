#include <cs50.h>
#include <stdio.h>
#include <math.h>

long credit_number(void);
bool length_check(void);
int number_length(void);
int timed_two(void);
int the_rest(void);

long n; // store credit card input
int digit_length; // store length of digits
int a; // sum of all the digits that were times 2
int b; // sum of all the digits that were left

int main(void)
{
    // Ask for Credit Card Number & store result
    n = credit_number();

    // Calculate total # of digits using log(10) (research source, but not copied: ChatGPT 4o)
    digit_length = number_length();

    // Multiply every second number from (second-last digit) by 2 and add them together
    a = timed_two();

    // Every number that's left added together
    b = the_rest();

    if ((a+b) % 10 == 0)
    {
        if ((digit_length == 13 || digit_length == 16) && ((n / (long)pow(10, digit_length - 1)) == 4))
        {
            printf("VISA\n");
        }

        else if (((n / (long)pow(10, digit_length - 2)) == 34 || (n / (long)pow(10, digit_length - 2)) == 37) && digit_length == 15)
        {
            printf("AMEX\n");
        }
        else if (((n / (long)pow(10, digit_length - 2)) >= 51 && (n / (long)pow(10, digit_length - 2)) <= 55) && digit_length == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}





// Function to get credit card number
long credit_number(void)
{
    // Get credit card number & return n
    return get_long("Number: ");
}

// Calculate total number of digits (length of numbers)
int number_length(void)
{
    return log10(n) + 1;
}

// Check for valid length
bool length_check(void)
{
    if (digit_length == 13 || digit_length == 15 || digit_length == 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// How to target specific digits
// a % 10 = b --> 12345 % 10 = 5 --> last digit
// 12345 % 100 = 45 then take 45 / 10 = 4.5 (take int) = 4

// Building a (all numbers that were multiplied by 2 and added together)
int timed_two(void)
{
    int result = 0;

    for (int x = 2; x <= digit_length; x ++)
    {

        //When x is even -- get every second number
        if (x % 2 == 0)
        {
            int digit = (n / (long)pow(10, (x - 1))) % 10;
            int doubled = digit * 2;

            // For numbers with 2 digits or more
            if (doubled > 9)
            {
                result += (doubled % 10) + (doubled / 10);
            }
            else //one digit numbers
            {
                result += doubled;
            }
        }
    }
    return result;
}

// Building b (all the numbers that are left added together)
int the_rest(void)
{
    int result = 0;
    for (int x = 1; x <= digit_length; x += 2)
    {
        int digit = (n / (long)pow(10, (x - 1))) % 10;
        result += digit;
    }
    return result;
}