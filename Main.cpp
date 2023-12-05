// Пошук максміну
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <time.h> 
#define n 6 
#define m 7 
const int N = 100;

int main(void)
{
    // Прототип функції
    int MaxMin(int A[][m], int nn, int mm, int* imax, int* jmax, int* iterations);

    int i, j, A[n][m], max, imax, jmax, iterations = 0;
    time_t t;
    srand((unsigned)time(&t));

    // Заповнення матриці цілими випадковими числами з [-N; N-1] 
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            A[i][j] = (rand() % N) - N;

    // Роздруковка матриці
    printf("\n\t The original matrix A(%d*%d):\n\n", n, m);
    for (i = 0; i < n; ++i)
    {
        printf("\t");
        for (j = 0; j < m; ++j)
            printf("%4d", A[i][j]);
        printf("\n");
    }

    // Виклик функції MaxMin для пошуку максміну та підрахунку ітерацій
    max = MaxMin(A, n, m, &imax, &jmax, &iterations);
    printf("\n\t Result: MaxMin = A[%d][%d] = %d\n", imax + 1, jmax + 1, max);
    printf("\n\t Number of iterations: %d\n", iterations);

    printf("\n Press any key: ");
    _getch();
    return 0;
}

// Функція пошуку максміну
int MaxMin(int A[][m], int nn, int mm, int* imax, int* jmax, int* iterations)
{
    int i, j, min, max, imin, jmin;
    max = A[0][0];
    *imax = 0; *jmax = 0;

    for (j = 1; j < mm; ++j, ++(*iterations))
        if (A[0][j] < max)
        {
            max = A[0][j];
            *imax = 0;
            *jmax = j;
        }

    for (i = 1; i < nn; ++i)
    {
        min = A[i][0];
        imin = i;
        jmin = 0;

        for (j = 1; j < mm; ++j, ++(*iterations))
            if (A[i][j] < min)
            {
                min = A[i][j];
                imin = i;
                jmin = j;
            }

        if (max < min)
        {
            max = min;
            *imax = imin;
            *jmax = jmin;
        }
    }

    return max;
}
