#include <iostream>
using namespace std;

int x, y, GCD;

void extendedEuclidsAlgo(int A, int B) {
    // base case
    if (B == 0) {
        x = 1;
        y = 0;
        GCD = A;
    }
    // recursive case
    extendedEuclidsAlgo(B, A % B);
    int c_x, c_y;
    c_x = y;
    c_y = x - (A / B) * y;

    x = c_x;
    y = c_y;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int A, B;
    cin >> A >> B;

    extendedEuclidsAlgo(A, B);

    // Integer Coefficients
    cout << x << " " << y << endl;

    return 0;
}
