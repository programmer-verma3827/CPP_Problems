/*

Sudoku Solver
Send Feedback
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true

*/


#include<bits/stdc++.h>
using namespace std;


// 1st Method

// bool findEmptyCells(int board[][9], int &row, int &col)
// {
//     for(int i=0;i<9;i++)
//     {
//         for(int j=0;j<9;j++)
//         {
//             if(board[i][j] == 0)
//             {
//                 row = i;
//                 col = j;
//                 return true;
//             }
//         }
//     }
    
//     return false;
// }


// bool isSafeInsert(int board[][9], int row, int col, int val)
// {
//     // Checking for row
    
//     for(int i=0;i<9;i++)
//     {
//         if(board[row][i] == val)
//         {
//             return false;
//         }
//     }
    
//     // Checking for column
    
//     for(int j=0;j<9;j++)
//     {
//         if(board[j][col] == val)
//         {
//             return false;
//         }
//     }
    
//     // Checking for grid
    
//     row = row - (row%3);
//     col = col - (col%3);
    
//     for(int i=0;i<3;i++)
//     {
//         for(int j=0;j<3;j++)
//         {
//             if(board[i+row][j+col] == val)
//             {
//                 return false;
//             }
//         }
//     }
    
//     return true;
// }


// bool solveSudoku(int board[9][9])
// {
//     int row = 0, col = 0;
//     bool emptyCell = findEmptyCells(board, row, col);
//     if(!emptyCell)
//     {
//         return true;
//     }
    
//     for(int i=1;i<=9;i++)
//     {
//         if(isSafeInsert(board, row, col, i))
//         {
//             board[row][col] = i;
//             bool result = solveSudoku(board);
//             if(result)
//             {
//                 return true;
//             }
//             else
//             {
//                 board[row][col] = 0;
//             }
            
//         }
//     }
    
//     return false;
// }


// 2nd Method


bool isSafeInsert(int board[][9], int row, int col, int num)
{
    for(int k=0;k<9;k++)
    {
        if(board[row][k] == num)
        {
            return false;
        }
        
        if(board[k][col] == num)
        {
            return false;
        }
        
        int rowFactor = row - (row % 3);
        int colFactor = col - (col % 3);
        
        for(int c = rowFactor;c<rowFactor+3;c++)
        {
            for(int d = colFactor;d<colFactor+3;d++)
            {
                if(board[c][d] == num)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}


bool solveSudoku(int board[][9], int row, int col)
{
    if(row == 9)
    {
        return true;
    }
    
    if(col == 9)
    {
        return solveSudoku(board, row+1, 0);
    }
    
    if(board[row][col] != 0)
    {
        return solveSudoku(board, row, col+1);
    }
    
    for(int k=1;k<=9;k++)
    {
        if(isSafeInsert(board, row, col, k))
        {
            board[row][col] = k;
            if(solveSudoku(board, row, col+1))
            {
                return true;
            }
        }
        
        board[row][col] = 0;
    }
    
    return false;
}


int main()
{
    // write your code here
    
    
    // 1st Method
    
//     int board[9][9];
//     for(int i=0;i<9;i++)
//     {
//         for(int j=0;j<9;j++)
//         {
//             cin>>board[i][j];
//         }
//     }
    
//     solveSudoku(board) ? cout<<"true" : cout<<"false";
    
    
    // 2nd Method
    
    int board[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>board[i][j];
        }
    }
    
    if(solveSudoku(board, 0, 0))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    
    
    return 0;
}


