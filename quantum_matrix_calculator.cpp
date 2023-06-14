#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiply_matrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    if (cols1 != rows2) {
        cout << "Error: Incompatible matrix dimensions." << endl;
        return {};
    }

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> matrix2 = {{7, 8}, {9, 10}, {11, 12}};

    cout << "Matrix 1:" << endl;
    for (const auto& row : matrix1) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Matrix 2:" << endl;
    for (const auto& row : matrix2) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = multiply_matrices(matrix1, matrix2);

    cout << "Resultant Matrix:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
