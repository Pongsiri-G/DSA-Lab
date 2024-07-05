#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int a, b, n, m;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &n, &m);

    int farm[b][a];
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < a; ++j) {
            scanf("%d", &farm[i][j]);
        }
    }

    int maxArea = n / m;
    int prefixSum[b + 1][a + 1];
    for (int i = 0; i <= b; ++i) {
        for (int j = 0; j <= a; ++j) {
            prefixSum[i][j] = 0;
        }
    }

    for (int i = 1; i <= b; ++i) {
        for (int j = 1; j <= a; ++j) {
            prefixSum[i][j] = farm[i-1][j-1]
                              + prefixSum[i-1][j]
                              + prefixSum[i][j-1]
                              - prefixSum[i-1][j-1];
        }
    }

    int maxValue = INT_MIN;

    for (int height = 1; height <= b; ++height) {
        for (int width = 1; width <= a; ++width) {
            if (height * width > maxArea) {
                break;
            }
            for (int i = height; i <= b; ++i) {
                for (int j = width; j <= a; ++j) {
                    int currentValue = prefixSum[i][j]
                                       - prefixSum[i-height][j]
                                       - prefixSum[i][j-width]
                                       + prefixSum[i-height][j-width];
                    maxValue = max(maxValue, currentValue);
                }
            }
        }
    }

    printf("%d\n", maxValue);
    return 0;
}
