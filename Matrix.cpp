#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void fill_matrix(vector<vector<int>>& matrix, int N, int M) {
   srand(time(0));
   for (int i = 0; i < N; ++i) {
      vector<int> row;
      for (int j = 0; j < M; ++j) {
         int num = rand() % 90 + 10;
         row.push_back(num);
      }
      matrix.push_back(row);
   }
}
void print_matrix(const vector<vector<int>>& matrix) {
   for (const auto& row : matrix) {
      for (int num : row) {
         cout << num << ' ';
      }
      cout << endl;
   }
}
int sum_row(const vector<vector<int>>& matrix, int row_num) {
   int sum = 0;
   for (int num : matrix[row_num]) {
      sum += num;
   }
   return sum;
}
int sum_column(const vector<vector<int>>& matrix, int col_num) {
   int sum = 0;
   for (int i = 0; i < matrix.size(); ++i) {
      sum += matrix[i][col_num];
   }
   return sum;
}

int main() {
   int N, M;
   cout << "Enter the number of rows and columns of the matrix: ";
   
   while (true) {
      cin >> N >> M;
      if (cin.fail()) {
         
          cout << "Error: Please enter a number value." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
       
      }
      break;
   }
   cout << endl;

   vector<vector<int>> matrix;
   fill_matrix(matrix, N, M);

   cout << "Matrix:" << endl << endl;
   print_matrix(matrix);
   cout << endl;

   int sum;
   int row_num;
   int col_num;
   char row_or_col_num;
   cout << "Press 'n' for row or 'm' for column: ";
   cin >> row_or_col_num;
   if (row_or_col_num == 'n') {
      cout << "Enter row number: ";
      cin >> row_num;
      if (row_num > 0 && row_num <= N) {
         sum = sum_row(matrix, row_num - 1);
         cout << "Sum of numbers in a row " << row_num << ": " << sum << endl;
      }
      else
         cout << "Error! You entered an incorrect row number!";
   }
   else if (row_or_col_num == 'm') {
      cout << "Enter column number: ";
      cin >> col_num;
      if (col_num > 0 && col_num <= M) {
         sum = sum_column(matrix, col_num - 1);
         cout << "Sum of numbers in a column " << col_num << ": " << sum << endl;
      }
      else
         cout << "Error! You entered an incorrect column number!";
   }
   else
      cout << "Error! You didn't press 'n' or 'm'!";
}
