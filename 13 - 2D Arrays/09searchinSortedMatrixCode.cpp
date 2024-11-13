#include <iostream>
using namespace std;

bool search(int mat[][4], int n, int m, int key) {
    int i=0, j=m-1;

    while(i < n && j >= 0) {
        if(mat[i][j] == key) {
            return true;
            cout << "The element is at " << i << " " << j << " cell \n";
            break;
        }else if( mat[i][j] > key) {
            j--;
        }else {
            i++;
        }
    }
    cout << "The " << key << "is not found" << endl;
    return false;
}

int main() {
    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    int matrix2[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    search(matrix, 4, 4, 16);

    return 0;
}