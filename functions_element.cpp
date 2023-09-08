#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "functions_element.h"

// void print_element_rectangular (char* data, size_t row, size_t cols)
// {
//     for (size_t i = 0; i < row; i++)
//     {
//         for (size_t j = 0; j < i + 1; j++)
//         {
//             assert (0 <= i && i < row);
//             assert (0 <= j && i < cols);
//             assert (0 <= i * cols + j && i * cols + j < MAX_SIZE);
//
//             printf (" %c", *(data + i * cols + j));
//         }
//         printf ("\n");
//     }
//
//     printf ("\n");
// }

void print_element_triangular (const int* data, const size_t row, const size_t cols)
{
    assert (data != nullptr);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < i + 1; j++)
        {
            assert (0 <= i && i < row);
            assert (0 <= j && i < cols);
            assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < MAX_SIZE);

            printf (" %d ", get_element_triangular (data, row, cols, i, j));
        }
        printf ("\n");
    }
}

// void get_element_rectangular (const char* data, size_t row, size_t cols, size_t i, size_t j)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < MAX_SIZE);
//
//     printf ("%d ", data[i * cols + j]);
// }

int get_element_triangular (const int const* data, const size_t row, const size_t cols, const size_t i, const size_t j)
{
    assert (0 <= i && i < row);
    assert (0 <= j && i < cols);
    assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < MAX_SIZE);
    assert (data != nullptr);

    return data[i * (i+1) / 2 + j];
}

// char* set_element_rectangular (char* data, size_t row, size_t cols, size_t i, size_t j, int replace)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < MAX_SIZE);
//
//     data[i * cols + j] = replace;
//     return data;
// }

int* set_element_triangular (int* data, const size_t row, const size_t cols, int &i, int &j, const int replace)
{
    assert (0 <= i && i < row);
    assert (0 <= j && i < cols);
    assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < MAX_SIZE);
    assert (data != nullptr);

    if (j > i)
    {
        int replacement = i;
        i = j;
        j = i;
    }
    data[i * (i+1) / 2 + j] = replace;

}

// void address_element_rectangular (const char* data, size_t row, size_t cols, size_t i, size_t j)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < MAX_SIZE);
//     printf("%p\n", data + i * cols + j);
// }
//
// void address_element_triangular (const char* data, size_t row, size_t cols, size_t i, size_t j)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < MAX_SIZE);
//     printf("%p\n", data + i * (i+1) / 2 + j);
// }
//
// void goal_recording (const int* data, size_t row, size_t cols, size_t i, size_t j, int goals)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < MAX_SIZE);
//
//     if (data[i * cols + j] > 0)
//     {
//         printf ("Team number %d won\n", i + 1);
//     }
//     else if (data[i * cols + j] == 0)
//     {
//         printf ("Teams tied\n");
//     }
//     else
//     {
//         printf ("Team number %d won\n", j + 1);
//     }
// }


void input_validation (int& first_team, int& second_team, int& goals)
{
    int verification = scanf ("%d %d %d", &first_team, &second_team, &goals);

    while (verification != 3)
    {
        printf ("Invalid value entered\n");
        int input = 0;

        do {
            input = getchar ();
        } while (input != '\n' && input != EOF);

        if (verification == EOF) break;

        verification = scanf ("%d %d %d", &first_team, &second_team, &goals);

    }
}

void input_user (int* data, const size_t row, const size_t cols)
{
    int input = 0;
    int first_team = 0, second_team = 0, goals = 0;

    while (true)
    {
        printf ("Input teams and goals\n");

        input_validation (first_team, second_team, goals);

        getchar();

        first_team--;
        second_team--;

        set_element_triangular (data, row, cols, first_team, second_team, goals);

        printf ("Want to enter commands? If yes, write 1, otherwise 0\n");

        input = getchar();
        if (input == '0')
        {
            break;
        }
    }
    print_element_triangular (data, row, cols);
}


