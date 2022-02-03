/*

N-Queen Problem
Send Feedback
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.
Constraints :
1 <= N <= 10
Time Limit: 1 second
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
Explanation:
The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other. 

*/


#include<bits/stdc++.h>
using namespace std;


// 1st Method

// int chessBoard[11][11];

// bool isPossible(int n, int row, int col)
// {
//     // Horizontal Kill
    
//     for(int i=row-1;i>=0;i--)
//     {
//         if(chessBoard[i][col] == 1)
//         {
//             return false;
//         }
//     }
    
//     // Left Diagonal Kill
    
//     for(int i=row-1, j=col-1;i>=0 && j>=0;i--, j--)
//     {
//         if(chessBoard[i][j] == 1)
//         {
//             return false;
//         }
//     }
    
//     // Right Diagonal Kill
    
//     for(int i=row-1, j=col+1;i>=0 && j<n;i--, j++)
//     {
//         if(chessBoard[i][j] == 1)
//         {
//             return false;
//         }
//     }
    
//     return true;
// }


// void nQueensHelper(int n, int row)
// {
//     if(row == n)
//     {
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout<<chessBoard[i][j]<<" ";
//             }
//         }
//         cout<<endl;
//         return;
//     }
    
//     for(int j=0;j<n;j++)
//     {
//         if(isPossible(n, row, j))
//         {
//             chessBoard[row][j] = 1;
//             nQueensHelper(n, row+1);
//             chessBoard[row][j] = 0;
//         }       
//     }
    
//     return;
// }

// void PlaceNQueens(int n)
// {
//     memset(chessBoard, 0, 11*11*sizeof(int));
//     nQueensHelper(n, 0);
// }


// 2nd Method

bool chessBoardSafe(vector<vector<int>> &boards, int row, int col)
{
    int n = boards.size();
    
    for(int i=row-1, j=col-1;i>=0 && j>=0;i--, j--)
    {
        if(boards[i][j] == 1)
        {
            return false;
        }
    }
    
    for(int i=row+1, j=col+1;i<n && j<n;i++, j++)
    {
        if(boards[i][j] == 1)
        {
            return false;
        }
    }
    
    for(int i=row-1, j=col+1;i>=0 && j<n;i--, j++)
    {
        if(boards[i][j] == 1)
        {
            return false;
        }
    }
    
    for(int i=row+1, j=col-1;i<n && j>=0;i++, j--)
    {
        if(boards[i][j] == 1)
        {
            return false;
        }
    }
    
    for(int i=row-1;i>=0;i--)
    {
        if(boards[i][col] == 1)
        {
            return false;
        }
    }
    
    for(int i=row+1;i<n;i++)
    {
        if(boards[i][col] == 1)
        {
            return false;
        }
    }
    
    return true;
}


void placeQueens(vector<vector<int>> &boards, int row, int n)
{
    if(row == n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<boards[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    
    for(int j=0;j<n;j++)
    {
        if(chessBoardSafe(boards, row, j))
        {
            boards[row][j] = 1;
            placeQueens(boards, row+1, n);
            boards[row][j] = 0;
        }
    }
}


void placeNQueens(int n)
{
    vector<vector<int>> boards(n, vector<int>(n, 0));
    placeQueens(boards, 0, n);
}


int main(){
    
    // write your code here
    
    // 1st Method
    
    // int n;
    // cin>>n;
    // PlaceNQueens(n);
    
    
    // 2nd Method
    
    int n;
    cin>>n;
    placeNQueens(n);
    
    return 0;
}
