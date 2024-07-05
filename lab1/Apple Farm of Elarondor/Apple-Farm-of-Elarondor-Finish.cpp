#include <iostream>
using namespace std;

// Function to Callculate score of area 2D array in a spiral order for a given block
int cast_spell(int *area, int rows, int cols, int start_row, int start_col, int range_x, int range_y) {
    int top = start_row, left = start_col;
    int bottom = start_row + range_y - 1, right = start_col + range_x - 1;
    int score = 0;

    while (top <= bottom && left <= right) {
        // Go Right
        for (int i = left; i <= right && i < cols; ++i) {
            //cout << *(area + top * cols + i) << " ";
            score += *(area + top * cols + i);
        }
        top++;

        // Go Down
        for (int i = top; i <= bottom && i < rows; ++i) {
            //cout << *(area + i * cols + right) << " ";
            score += *(area + i * cols + right);
        }
        right--;

        // Go Left
        if (top <= bottom) {
            for (int i = right; i >= left && i >= 0; --i) {
                //cout << *(area + bottom * cols + i) << " ";
                score += *(area + bottom * cols + i);
            }
            bottom--;
        }

        // Go Up
        if (left <= right) {
            for (int i = bottom; i >= top && i >= 0; --i) {
                //cout << *(area + i * cols + left) << " ";
                score += *(area + i * cols + left) ;
            }
            left++;
        }
        //cout << endl;
    }
    return score;
}

int main() {
    int width, length;
    int mana, mana_cost;

    cin >> width >> length;
    cin >> mana >> mana_cost;
    int rows = length, cols = width;
    if (width == 1 && length == 1){
        int k;
        cin >> k;
        if (k > 0 && mana / mana_cost > 0){
            cout << k;
        }
        else {
            cout << 0;
        }
    }
    else{
        int area[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> area[i][j];
            }
        }

        // Calculate range of cast area (m*n and n*m) test for use the most value
        int cast_area = mana / mana_cost;
        int max_score = 0;
        


        while (cast_area > 0)
        {
            for (int range_x = 1; range_x <= cast_area; ++range_x) {
                if (cast_area % range_x == 0) {
                    int range_y = cast_area / range_x;
                    ///cout << range_x << " * " << range_y << endl;
                    if ((range_x == 1 && range_y != 1) || (range_x != 1 && range_y == 1)) continue;
                    // Splitting the area for calculate score
                    for (int start_row = 0; start_row <= rows - range_y; ++start_row) {
                        for (int start_col = 0; start_col <= cols - range_x; ++start_col) {
                            int score = cast_spell((int *)area, rows, cols, start_row, start_col, range_x, range_y);
                            //int k = max_score;
                            max_score = max(max_score, score);
                            //if (max_score > k) cout << range_x << " * " << range_y << endl;
                        }
                    }
                }
            }

            cast_area -= 2;
        }
        
        cout << max_score ;
    }
    return 0;
}
