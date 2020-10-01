#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int gcd(int x, int y){
    int r = 0, a, b;
    a = (x > y) ? x : y; // a is greater number
    b = (x < y) ? x : y; // b is smaller number
    r = b;
    while (a % b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

int lcm(int x, int y){
    int a;
    a = (x > y) ? x : y; // a is greater number
    while (true){
        if (a % x == 0 && a % y == 0)
            return a;
        ++a;
    }
}

int main(int argc, char **argv){
    cout << "Enter the two numbers: ";
    int x, y;
    cin >> x >> y;
    cout << "The GCD of two numbers is: " << gcd(x, y) << endl;
    cout << "The LCM of two numbers is: " << lcm(x, y) << endl;
    return 0;
}
