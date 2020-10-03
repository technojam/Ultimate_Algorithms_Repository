
using namespace std;
#include<iostream>

    #define loopi 
    #define loopj 
    #define n 8
    
    int isSafe(int x , int y , int sol[n][n]) {

            return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);

    }
    int solution(int sol[n][n] , int x , int y , int no_move , int xMove[] , int yMove[]) {

            if(no_move == n*n)
                return 1;
            
            for(int k = 0 ; k < 8 ; k++) {

                int newX = x + xMove[k];
                int newY = y + yMove[k];

                if(isSafe(newX , newY , sol)) {

                    sol[newX][newY] = no_move;
                    
                    if(solution(sol , newX , newY , no_move+1 , xMove , yMove))
                        return 1;
                    else
                        sol[newX][newY] = -1;
                }
            }
             return 0;
    }
    int main() {

        

        int sol[n][n];
        
        for(int i = 0 ; i < n ; i++) 
			for(int j = 0 ; j < n ; j++)
				sol[i][j] = -1; 

        int xMove[8] = { 2 , 1 , -1 , -2 , -2 , -1 , 1, 2};
        int yMove[8] = { 1 , 2 , 2 , 1 , -1 , -2 , -2, -1};

        sol[0][0] = 0; // knight pos

        if(solution(sol , 0 , 0 , 1 , xMove , yMove) == 0)
            cout<<"\nSolution doest not exists";
        else
            for(int i = 0 ; i < n ; i++) { 
            
            for(int j = 0 ; j < n ; j++) 
				printf(" %2d ",sol[i][j]);
            cout<<endl;

            }
        return 0; 
    }
