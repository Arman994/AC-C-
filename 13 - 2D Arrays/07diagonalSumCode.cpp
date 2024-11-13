#include <iostream>
using namespace std;

int diagonalSum(int mat[][3], int n) {
    int sum = 0;

    for(int i=0; i<n; i++) {
        sum += mat[i][i];
        if(i != n-i-1) {     //   i=j is the common element.
            sum += mat[n-i-1][i];
        }
    }
    cout << "Sum is " << sum << endl;
    return sum;
}

// int diagonalSum(int mat[][3], int n) { //   O(N^2)
//     int sum = 0;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             if(i == j) {
//                 sum += mat[i][j];
//             } else if (j == n-i-1) {    //   because of else if the common element won't be added to sum twice
//                 sum += mat[i][j]; 
//             }
//         }
//     }
//     cout << "Sum = " << sum << endl;
//     return sum;
// }

int main() {
    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    int matrix2[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    // diagonalSum(matrix, 4);

    diagonalSum(matrix2, 3);
    
    return 0;
}