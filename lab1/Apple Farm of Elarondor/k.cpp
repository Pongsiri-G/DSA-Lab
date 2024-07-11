#include <iostream>
#include <vector>

using namespace std;

// Function to compute the maximum value that can be protected with the given mana
int maxProtectedValue(int a, int b, int n, int m, vector<vector<int>>& farmValues) {
    int max_value = 0;

    // Loop through all possible sub-matrix sizes
    for (int height = 1; height <= b; ++height) {
        for (int width = 1; width <= a; ++width) {
            if (height * width * m <= n) {
                // Check all top-left corners of sub-matrices of this size
                for (int i = 0; i <= b - height; ++i) {
                    for (int j = 0; j <= a - width; ++j) {
                        int current_sum = 0;
                        for (int x = i; x < i + height; ++x) {
                            for (int y = j; y < j + width; ++y) {
                                current_sum += farmValues[x][y];
                            }
                        }
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
