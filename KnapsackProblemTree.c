/**
 * 
 * @file KnapsackProblemTree.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Knapsack Problem Implementation In C Using Tree Structure
 * @version 0.1
 * @date 2022-12-12
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
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
    weights[2] = 2;
    weights[3] = 1;

    int capacity = 5;
    int n = 4;

    int **dp = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (capacity + 1));
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (weights[i - 1] <= j)
            {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return 0;
}

