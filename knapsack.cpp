#include <iostream>
using namespace std;

// A utility function that returns the maximum of two integers
int max(int a, int b) { 
    if(a>b) {
        return a;
    }
    else {
        return b;
    }
    
}

// Returns the maximum profit that can be put in a knapsack of capacity
int knapSack(int capacity, int weight[], int profit[], int size) {
    int i, j;
    int K[size + 1][capacity + 1];  // 2D array for dynamic programming

    // Build table K[][] in a bottom-up manner
    for (i = 0; i <= size; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (weight[i - 1] <= j)
                K[i][j] = max(profit[i - 1] + K[i - 1][j - weight[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }
    return K[size][capacity];
}

int main() {
    int profit[] = {10, 15, 40};
    int weight[] = {1, 2, 3};
    int capacity = 6;
    int size = sizeof(profit) / sizeof(profit[0]);

    cout << knapSack(capacity, weight, profit, size);

    return 0;
}

