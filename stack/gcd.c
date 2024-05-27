#include <stdio.h>

int gcd (int a, int b)
{
    if (b != 0)
        return gcd (b, a%b);
    else
        return a;
}

int main()
{
    int x = 4, y = 6;
    int hcf = gcd(x, y); // 2
    printf ("GCD of %d and %d is: %d\n", x, y, hcf); // GCD of 4 and 6 is: 2
    return 0;
}   