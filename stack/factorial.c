#include <stdio.h>

int factorial (int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return n;
    else
        return n * factorial(n-1);
}

int main()
{
    int num = 6;
    int fact = factorial(num); // 6*5*4*3*2*1 = 720
    printf ("Factorial of %d is: %d\n", num, fact); //Factorial of 6 is: 720
    return 0;
}
 