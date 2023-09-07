#include <stdio.h>

void test()
{
    FILE *TestFile = fopen ("test.txt", "r");
    if (! (TestFile))
    {
        printf ("File not found");
        return;
    }

    int n = 0;
    fscanf (TestFile, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        int amount = 0;
        fscanf (TestFile, "%d", amount);
        for (int j = 0; j < n; j++)
        {

        }

    }
    fclose (TestFile);
}
