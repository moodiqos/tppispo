#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Функция для проверки, является ли матрица латинским квадратом
bool isLatinSquare(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        unordered_set<int> rowSet, colSet;
        for (int j = 0; j < n; j++) {
            int rowVal = matrix[i][j];
            int colVal = matrix[j][i];

            // Проверка на корректность чисел (от 1 до n)
            if (rowVal < 1 || rowVal > n || colVal < 1 || colVal > n) {
                return false;
            }
            
            // Проверка на повторение в строках
            if (rowSet.count(rowVal)) {
                return false;
            }
            rowSet.insert(rowVal);

            // Проверка на повторение в столбцах
            if (colSet.count(colVal)) {
                return false;
            }
            colSet.insert(colVal);
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Введите порядок латинского квадрата (n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Введите элементы матрицы " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    if (isLatinSquare(matrix, n)) {
        cout << "Матрица является латинским квадратом.\n";
    } else {
        cout << "Матрица не является латинским квадратом.\n";
    }

    return 0;
}
