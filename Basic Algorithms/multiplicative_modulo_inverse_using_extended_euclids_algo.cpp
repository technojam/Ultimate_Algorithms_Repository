#include <iostream>
using namespace std;

int x, y;
int GCD;

void extendedEuclidsAlgo(int A, int B) {
    if (B == 0) {
        x = 1;
        y = 0;
        GCD = A;
        return;
    }
    extendedEuclidsAlgo(B, A % B);

    int c_x, c_y;
    c_x = y;
    c_y = x - (A / B) * y;
    x = c_x;
    y = c_y;
}

int multiplicativeModuloInverse(int A, int m) {

    // It is possible to find the inverse only if GCD(A,m) == 1; You can put a check here
    extendedEuclidsAlgo(A, m);

    // %m if x is negative
    return (x + m) % m;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int A, m;

    cin >> A >> m;

    // Multiplicative modulo inverse of A w.r.t m
    cout << multiplicativeModuloInverse(A, m) << endl;

    return 0;
}
