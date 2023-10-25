#include <iostream>
#include <iomanip>
using namespace std;

void getMatrix(int **arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ask;
            cout << "Enter coin status at position (" << i+1 << ", " << j+1 << "): ";
            cin >> ask;
            arr[i][j] = ask;
        }
    }
}

void displayMatrix(int **arr, int n, int m) {
    cout << "Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// prints the path with arrows
void printpath(int **arr, int n, int m) {
    int i = n - 1, j = m - 1;
    while (i != 0 || j != 0) {
        cout << "(" << i + 1 << ", " << j + 1 << ") ";
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else {
            if (arr[i - 1][j] > arr[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    cout << "(1, 1)";
}

int coinCollection(int **arr, int n, int m) {
    int F[n][m];
    F[0][0] = arr[0][0];
    for (int i = 1; i < n; ++i) {
        F[i][0] = F[i - 1][0] + arr[i][0];
    }
    for (int j = 1; j < m; ++j) {
        F[0][j] = F[0][j - 1] + arr[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            F[i][j] = arr[i][j] + max(F[i - 1][j], F[i][j - 1]);
        }
    }
    cout << "\nDynamic Programming Array:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << F[i][j] << " ";
        }
        cout << endl;
    }
    return F[n - 1][m - 1];
}

int main() {
    int n, m;
    cout << "Enter the size of the matrix: ";
    cin >> n >> m;

    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    getMatrix(matrix, n, m);
    displayMatrix(matrix, n, m);
    int result = coinCollection(matrix, n, m);
    cout << "\nMaximum coins collected: " << result<< endl;
    cout << "Path: ";
    printpath(matrix, n, m);


    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
