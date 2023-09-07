#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "get_element.h"

// void print_element_rectangular (char* data, size_t row, size_t cols)
// {
//     for (size_t i = 0; i < row; i++)
//     {
//         for (size_t j = 0; j < i + 1; j++)
//         {
//             assert (0 <= i && i < row);
//             assert (0 <= j && i < cols);
//             assert (0 <= i * cols + j && i * cols + j < 100);
//
//             printf (" %c", *(data + i * cols + j));
//         }
//         printf ("\n");
//     }
//
//     printf ("\n");
// }

void print_element_triangular (int* data, size_t row, size_t cols)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < i + 1; j++)
        {
            assert (0 <= i && i < row);
            assert (0 <= j && i < cols);
            assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < 100);

            get_element_triangular (data, row, cols, i, j);
        }
        printf ("\n");
    }
}

// void get_element_rectangular (const char* data, size_t row, size_t cols, size_t i, size_t j)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < 100);
//
//     printf ("%d ", data[i * cols + j]);
// }

void get_element_triangular (int* data, size_t row, size_t cols, size_t i, size_t j)
{
    assert (0 <= i && i < row);
    assert (0 <= j && i < cols);
    assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < 100);

    printf (" %d ", data[i * (i+1) / 2 + j]);
}

// char* set_element_rectangular (char* data, size_t row, size_t cols, size_t i, size_t j, int replace)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < 100);
//
//     data[i * cols + j] = replace;
//     return data;
// }

int* set_element_triangular (int* data, size_t row, size_t cols, int i, int j, int replace)
{
    assert (0 <= i && i < row);
    assert (0 <= j && i < cols);
    assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < 100);

    data[i * (i+1) / 2 + j] = replace;
    return data;
}

// void address_element_rectangular (const char* data, size_t row, size_t cols, size_t i, size_t j)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < 100);
//     printf("%p\n", data + i * cols + j);
// }
//
// void address_element_triangular (const char* data, size_t row, size_t cols, size_t i, size_t j)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * (i+1) / 2 + j && i * (i+1) / 2 + j < 100);
//     printf("%p\n", data + i * (i+1) / 2 + j);
// }
//
// void goal_recording (const int* data, size_t row, size_t cols, size_t i, size_t j, int goals)
// {
//     assert (0 <= i && i < row);
//     assert (0 <= j && i < cols);
//     assert (0 <= i * cols + j && i * cols + j < 100);
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

void s_validation (int *first_team, int *second_team)
{
    int verification = scanf ("%d %d", first_team, second_team);

    while (verification != 2)
    {
        printf ("Invalid value entered.\n You need to enter command numbers");
        int n = 0;

        do {
            n = getchar ();
        } while (n != '\n' && n != EOF);

        if (verification == EOF) break;

        verification = scanf ("%d %d", first_team, second_team);

    }
}
