#include <iostream>
#include <vector>
#include <algorithm> // for std::max
using namespace std;

// Function to calculate the score of a 2D array in a spiral order for a given block
int cast_spell(const vector<vector<int>>& area, int start_row, int start_col, int range_x, int range_y) {
    int top = start_row, left = start_col;
    int bottom = start_row + range_y - 1, right = start_col + range_x - 1;
    int score = 0;
    int rows = area.size();
    int cols = area[0].size();

    while (top <= bottom && left <= right) {
        // Go Right
        for (int i = left; i <= right && i < cols; ++i) {
            score += area[top][i];
        }
        top++;

        // Go Down
        for (int i = top; i <= bottom && i < rows; ++i) {
            score += area[i][right];
        }
        right--;

        // Go Left
        if (top <= bottom) {
            for (int i = right; i >= left && i >= 0; --i) {
                score += area[bottom][i];
            }
            bottom--;
        }

        // Go Up
        if (left <= right) {
            for (int i = bottom; i >= top && i >= 0; --i) {
                score += area[i][left];
            }
            left++;
        }
    }
    return score;
}

int main() {
    int width, length;
    int mana, mana_cost;

    cin >> width >> length;
    cin >> mana >> mana_cost;

    vector<vector<int>> area(length, vector<int>(width));
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> area[i][j];
        }
    }

    int cast_area = mana / mana_cost;
    int max_score = INT_MIN;

    for (int range_x = 1; range_x <= cast_area; ++range_x) {
        if (cast_area % range_x == 0) {
            int range_y = cast_area / range_x;

            // Splitting the area to calculate score
            for (int start_row = 0; start_row <= length - range_y; ++start_row) {
                for (int start_col = 0; start_col <= width - range_x; ++start_col) {
                    int score = cast_spell(area, start_row, start_col, range_x, range_y);
                    max_score = max(max_score, score);
                }
            }
        }
    }

    cout << max_score << endl;
    return 0;
}
