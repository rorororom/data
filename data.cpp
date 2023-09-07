#include <assert.h>
#include <stdio.h>

#include "functions_element.h"

int main()
{
    int data[100] = {0,
                     0,0,
                     0,0,0,
                     0,0,0,0,
                     0,0,0,0,0};



    size_t row = 5;
    size_t cols = 5;

    int first_team = 0, second_team = 0;
    int goals = 0;
    int input = 0;

    while (true)
    {
        //s_validation (&first_team, &second_team);
        printf ("Input teams and goals\n");

        int verification = scanf ("%d %d %d", &first_team, &second_team, &goals);
        while (verification != 3)
        {
            verification = scanf ("%d %d %d", &first_team, &second_team, &goals);
        }

        checking_order (first_team, second_team);

        getchar();

        first_team--;
        second_team--;
        set_element_triangular (data, row, cols, first_team, second_team, goals);

        printf ("Want to enter commands? If yes, write 1, otherwise 0\n");
        int input = getchar();
        if (input == '0')
        {
            break;
        }
    }
    print_element_triangular (data, row, cols);

}
