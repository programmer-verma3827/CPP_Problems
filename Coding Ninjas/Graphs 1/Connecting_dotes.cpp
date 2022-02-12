/*

Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true

*/


#include <iostream>
#include <vector>
using namespace std;

// 1st Method


// int moveX[4] = {-1, 0, 1, 0};
// int moveY[4] = {0, -1, 0, 1};


// bool checkCycleHelper(vector<vector<char>> &board, int n, int m, int sourceX, int sourceY, int x, int y, int count, bool** visited)
// {
//     for(int i=0;i<4;i++)
//     {
//         int nextX = x + moveX[i];
//         int nextY = y + moveY[i];
        
//         if(nextX == sourceX && nextY == sourceY && count>=4)
//         {
//             return true;
//         }
//     }
    
//     for(int i=0;i<4;i++)
//     {
//         int nextX = x + moveX[i];
//         int nextY = y + moveY[i];
        
//         if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
//         {
//             if(board[nextX][nextY] == board[x][y] && !visited[nextX][nextY])
//             {
//                 visited[nextX][nextY] = true;
                
//                 if(checkCycleHelper(board, n, m, sourceX, sourceY, nextX, nextY, count+1, visited))
//                 {
//                     return true;
//                 }
                
//                 visited[nextX][nextY]= false;
//             }
//         }
//     }
    
//     return false;
// }


// int checkCycle(vector<vector<char>> &board, int n, int m)
// {
//     bool **visited = new bool*[n];
//     for(int i=0;i<n;i++)
//     {
//         visited[i] = new bool[m];
//         for(int j=0;j<m;j++)
//         {
//             visited[i][j] = false;
//         }
//     }
    
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(!visited[i][j])
//             {
//                 visited[i][j] = true;
                
//                 if(checkCycleHelper(board, n, m, i, j, i, j, 1, visited))
//                 {
//                     return 1;
//                     visited[i][j] = false;
//                 }
//             }
//         }
//     }
    
//     return 0;
// }


// 2nd Method


void checkCycleGraph(vector<vector<char>> &board, vector<vector<bool>> &output, int x, int y, int fromX, int fromY, bool &foundCycle, 
char needColor, int n, int m)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }
    
    if(board[x][y] != needColor)
    {
        return;
    }
    
    if(output[x][y])
    {
        foundCycle = true;
        return;
    }
    
    output[x][y] = true;
    int arr1[] = {-1, 0, 1, 0};
    int arr2[] = {0, -1, 0, 1};
    
    for(int i=0;i<4;i++)
    {
        int nextX = x + arr1[i];
        int nextY = y + arr2[i];
        
        if(nextX == fromX && nextY == fromY)
        {
            continue;
        }
        
        checkCycleGraph(board, output, nextX, nextY, x, y, foundCycle, needColor, n, m);
    }
    
}


bool hasCycle(vector<vector<char>> &board, int n, int m) 
{
    // Write your code here. 
    
    // 1st Method
    
    // return checkCycle(board, n, m);
    
    
    // 2nd Method
    
    bool foundCycle = false;
    vector<vector<bool>> output(n, vector<bool>(m, false));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!output[i][j])
            {
                checkCycleGraph(board, output, i, j, -1, -1, foundCycle, board[i][j], n, m);
            }
        }
    }
    
    return foundCycle;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
