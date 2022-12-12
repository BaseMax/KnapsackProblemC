/**
 * 
 * @file KnapsackProblem.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Knapsack Problem Implementation In C
 * @version 0.1
 * @date 2022-12-12
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int **Knapsack(int *values, int *weights, int capacity)
{
    int **table = (int **)malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++) {
        table[i] = (int *)malloc(sizeof(int) * 5);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            table[i][j] = 0;
        }
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            if (weights[i - 1] <= j) {
                table[i][j] = values[i - 1] + table[i - 1][j - weights[i - 1]];
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    return table;
}

int main(int argc, char **argv)
{
    int *values = (int *)malloc(sizeof(int) * 4);
    values[0] = 1;
    values[1] = 2;
    values[2] = 3;
    values[3] = 4;

    int *weights = (int *)malloc(sizeof(int) * 4);
    weights[0] = 1;
    weights[1] = 2;
    weights[2] = 3;
    weights[3] = 4;

    int capacity = 5;


    int **table = Knapsack(values, weights, capacity);

    printf("Table: \r\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\r\n");
    }

    printf("Max value: %d\r\n", table[4][4]);

    return 0;
}
