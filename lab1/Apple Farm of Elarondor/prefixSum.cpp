#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute the prefix sum of the farm values
void computePrefixSum(const vector<vector<int>>& farmValues, vector<vector<int>>& prefixSum) {
    int rows = farmValues.size();
    int cols = farmValues[0].size();
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            prefixSum[i][j] = farmValues[i][j];
            if (i > 0) prefixSum[i][j] += prefixSum[i-1][j];
            if (j > 0) prefixSum[i][j] += prefixSum[i][j-1];
            if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
        }
    }
}

// Function to get the sum of a sub-matrix using the prefix sum array
int getSubMatrixSum(const vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
    int sum = prefixSum[x2][y2];
    if (x1 > 0) sum -= prefixSum[x1-1][y2];
    if (y1 > 0) sum -= prefixSum[x2][y1-1];
    if (x1 > 0 && y1 > 0) sum += prefixSum[x1-1][y1-1];
    return sum;
}

// Function to compute the maximum value that can be protected with the given mana
int maxProtectedValue(int a, int b, int n, int m, const vector<vector<int>>& farmValues) {
    int max_value = 0;
    
    vector<vector<int>> prefixSum(b, vector<int>(a, 0));
    computePrefixSum(farmValues, prefixSum);

    // Loop through all possible sub-matrix sizes
    for (int height = 1; height <= b; ++height) {
        for (int width = 1; width <= a; ++width) {
            if (height * width * m <= n) {
                // Check all top-left corners of sub-matrices of this size
                for (int i = 0; i <= b - height; ++i) {
                    for (int j = 0; j <= a - width; ++j) {
                        int x1 = i, y1 = j;
                        int x2 = i + height - 1, y2 = j + width - 1;
                        int current_sum = getSubMatrixSum(prefixSum, x1, y1, x2, y2);
                        max_value = max(max_value, current_sum);
                    }
                }
            }
        }
    }
    return max_value;
}

int main() {
    int a, b, n, m;
    cin >> a >> b;
    cin >> n >> m;

    vector<vector<int>> farmValues(b, vector<int>(a));
    
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < a; ++j) {
            cin >> farmValues[i][j];
        }
    }

    int result = maxProtectedValue(a, b, n, m, farmValues);
    cout << result << endl;

    return 0;
}
