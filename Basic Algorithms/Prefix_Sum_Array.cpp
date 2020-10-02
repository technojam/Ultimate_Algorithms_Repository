// C++ code to solve the Range Sum Queries
// Given an array of N integers, this algorithm processes Q queries of the form: what is the sum of values in range [A,B]?

// Time complexity for each query: O(1)
// Time complexity for the reading: O(N)
// Time complexity for all the queries: O(Q)

// Works for the following Constraints:
// 1≤N,Q≤2⋅1e5
// 1≤X≤1e9
// 1≤A≤B≤N

// You can find an example of question to use this algorithm here: https://cses.fi/problemset/task/1646

/* How to do that */

// While getting the elements of the array, the algorithm sums it with the previous value (the first value is 0). The resultant array is called the Prefix Sum Array (PSA).
// To get any sum of a given interval [A,B], you just need to subtract the value in B position of the value in A position. 
// By doing that, you are subtracting the sum of all the elements until A from the sum of the elements until B, resulting on the sum of the elements in the interval [A,B].

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define i64 long long
#define vi vector<i64>

using namespace std;

i64 n, q, x, a, b;
vi psa;

int main() {_
    cin >> n >> q; // Get the size of the array and the number of queries
    psa = vi(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> x; // get the current value
        psa[i] = psa[i-1] + x; // sums it with the previous value from the PSA array and puts in the current position
    }

    for(int i = 0; i < q; i++) {
        cin >> a >> b; // get the wanted range
        cout << psa[b] - psa[a-1] << endl; // shows the sum of the given range by subtracting the sum of all the elements until A from the sum of the elements until B
    }
    

    return 0;
}
