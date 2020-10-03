#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<string>



void modify(vector<vector<int>>& result, int n, vector<vector<string>>& ans) // modifing the result array according to the dirsed output
{

    for (int i = 0; i < result.size(); i++)                                 // for eg [. . . Q . . .] for n=7 ans so on
    {
        vector<string> c(n);
        for (int j = 0; j < n; j++)
        {
            string s = "";
            for (int k = 0; k < n; k++)
            {
                if (k == result[i][j])
                    s += 'Q';
                else
                    s += '.';
            }
            c[j] = s;
        }
        ans.push_back(c);
    }                                                                       // as array is passed by reference so no return statement needed.
}

bool isvalid(vector<int> colplacement)                  //validating the newly placed queen(simple maths)
{
    int currrow = colplacement.size() - 1;
    for (int i = 0; i < currrow; i++)
    {
        int diff = abs(colplacement[i] - colplacement[currrow] );
        if (diff == 0 || diff == (currrow - i))
            return false;
    }
    return true;
}

void  solve(int n, int row, vector<int>& colplacement, vector<vector<int>>& result)
{
    if (row == n)                               //If curr row is equal to n the we have found the correct answer so push it back to the result array
    {

        result.push_back(colplacement);
    }
    else
    {
        for (int col = 0; col < n; col++)       //iterating over all possible the columns
        {
            colplacement.push_back(col);
            if (isvalid(colplacement))          //checking if the new added queen satifies the rule of not killing other queens present
            {
                solve(n, row + 1, colplacement, result);    //if true the further incrementing the coloumn
            }
            colplacement.pop_back();                        // if false the backtracking the answer and checking for different possiblities on the board
        }
    }
    return ;
}




vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;         //output vector
    vector<vector<int>> result;
    vector<int> colplacement;
    solve(n, 0, colplacement, result);  //Backtracking Algorithm which calcualte all possible position on the chessboard

    modify(result, n, ans);             //modifing the array according to the desired output
    return ans;                         //return statement
}

int main()
{
    int n;
    cin >> n;                           //Input Size of ChessBoard
    if (n <= 0) {cout << "Invalid input\n"; return 1}
    if (n <= 3) {cout << "No possible arrangement\n"; return 1;}
    vector<vector<string>> x;           //Ouput Vector
    x = solveNQueens(n);
    cout << "---------------------------\n";
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << x[i][j] << "\n";
        }
        cout << "---------------------------\n";
    }

}
