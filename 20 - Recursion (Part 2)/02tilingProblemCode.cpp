// Count total ways to tile a floor (2xn) with tiles (2x1).

#include <iostream>
using namespace std;

int tilingProblem(int n) { //2xn
    if(n == 0 || n == 1) { //most important : in n=0 we cannot place a tile but that is way so return 1 
        return 1;
    }

    return tilingProblem(n-1) + tilingProblem(n-2);

    // //vertical
    // int ans1 = tilingProblem(n-1); //2x(n-1)

    // //horizontal
    // int ans2 = tilingProblem(n-2); //2x(n-2)

    // return ans1 + ans2;
}

int main() {
    int n = 4;

    cout << tilingProblem(n) << endl;


    return 0;
}