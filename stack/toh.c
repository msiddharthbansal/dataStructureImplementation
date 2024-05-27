#include <stdio.h>

void toh (int n, char f, char t, char u)
{
    if (n == 1)
    {
        printf ("Move disc from tower %c to tower %c.\n", f, t);
        return;
    }
    toh (n-1, f, u, t);
    toh (1, f, t, u);
    toh (n-1, u, t, f);
}

int main()
{
    toh (3, 'A', 'C', 'B');
    return 0;
}
// Move from tower A to tower C
// Move from tower A to tower B
// Move from tower C to tower B
// Move from tower A to tower C
// Move from tower B to tower A
// Move from tower B to tower C
// Move from tower A to tower C