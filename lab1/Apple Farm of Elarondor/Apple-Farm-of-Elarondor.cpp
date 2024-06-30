#include <iostream>
using namespace std;

// Function to print the 2D array in a spiral order for a given block
void cast_spell(int *area, int rows, int cols, int start_row, int start_col) {
    int top = start_row, left = start_col;
    int bottom = start_row + 1, right = start_col + 1;

    while (top <= bottom && left <= right) {
        // Go Right
        for (int i = left; i <= right && i < cols; ++i) {
            cout << *(area + top * cols + i) << " ";
        }
        top++;

        // Go Down
        for (int i = top; i <= bottom && i < rows; ++i) {
            cout << *(area + i * cols + right) << " ";
        }
        right--;

        // Go Left
        if (top <= bottom) {
            for (int i = right; i >= left && i >= 0; --i) {
                cout << *(area + bottom * cols + i) << " ";
            }
            bottom--;
        }

        // Go Up
        if (left <= right) {
            for (int i = bottom; i >= top && i >= 0; --i) {
                cout << *(area + i * cols + left) << " ";
            }
            left++;
        }
    }
}

int main() {
    int width, length;
    int mana, mana_cost;

    cin >> width >> length;
    cin >> mana >> mana_cost;
    int rows = length, cols = width;

    // Calculate cast_area (not used in this version of the code)
    int cast_area = mana / mana_cost;

    int area[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> area[i][j];
        }
    }
    cout << endl;

    // Print the input array for verification
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }

    // Splitting the array into 2x2 blocks and printing in spiral order
    for (int start_row = 0; start_row < rows; start_row += 2) {
        for (int start_col = 0; start_col < cols; start_col += 2) {
            cout << "Spiral order for block starting at (" << start_row << ", " << start_col << "): ";
            cast_spell((int *)area, rows, cols, start_row, start_col);
            cout << endl;
        }
    }

    return 0;
}
