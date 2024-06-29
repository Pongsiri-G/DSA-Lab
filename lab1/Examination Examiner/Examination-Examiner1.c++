#include <iostream>
using namespace std;

int main() {
    int num_student, num_exam;
    cin >> num_student >> num_exam;

    // Get the Correct answer
    int correct_ans[num_exam];
    for (int i=0; i < num_exam; i++){
        cin >> correct_ans[i];
    }

    // Get answer from each student
    int students_ans[num_student][num_exam];
    for (int i=0; i < num_student; i++){
      for (int j=0; j < num_exam; j++){
        cin >> students_ans[i][j];
      }

    }

    // Check the answer and collect score of each student
    int students_scores[num_student];
    for (int i=0; i < num_student; i++){
      int score = 0;
      for (int j=0; j < num_exam; j++){
        if (students_ans[i][j] == correct_ans[j]){
          score += 1;
        }
      }
      students_scores[i] = score;
    }

    // Print score
    for (int i=0; i < num_student; i++){
      cout << students_scores[i] << " ";
    }

  return 0;
}