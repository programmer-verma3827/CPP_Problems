/*

Largest Piece
Send Feedback
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3

*/


#include <iostream>
#include <vector>
using namespace std;

#include <climits>


// 1st Method

// int getBiggestPieceSizeHelper(vector<vector<int>> &cake, int n, int i, int j, bool **visited)
// {
//     visited[i][j] = true;
//     int result = 0;
    
//     if(i+1 < n && cake[i+1][j] == 1 && visited[i+1][j] == false)
//     {
//         result = result + getBiggestPieceSizeHelper(cake, n, i+1, j, visited);
//     }
    
//     if(i-1 >= 0 && cake[i-1][j] == 1 && visited[i-1][j] == false)
//     {
//         result = result + getBiggestPieceSizeHelper(cake, n, i-1, j, visited);
//     }
    
//     if(j+1 < n && cake[i][j+1] == 1 && visited[i][j+1] == false)
//     {
//         result = result + getBiggestPieceSizeHelper(cake, n, i, j+1, visited);
//     }
    
//     if(j-1 >= 0 && cake[i][j-1] == 1 && visited[i][j-1] == false)
//     {
//         result = result + getBiggestPieceSizeHelper(cake, n, i, j-1, visited);
//     }
    
//     return result + 1;
// }


// 2nd Method


int getBiggestPieceSizeHelper(vector<vector<int>> &cake, int n, int x, int y, vector<vector<bool>> &visited)
{
    if(visited[x][y])
    {
        return 0;
    }
    
    visited[x][y] = true;
    int count = 1;
    
    int arr1[] = {0, 0, -1, 1};
    int arr2[] = {1, -1, 0, 0};
    
    for(int i=0;i<4;i++)
    {
        int nextX = x + arr1[i];
        int nextY = y + arr2[i];
        
        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && cake[nextX][nextY] == 1)
        {
            count = count + getBiggestPieceSizeHelper(cake, n, nextX, nextY, visited);
        }
    }
    
    return count;
}


int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    
    // Write your code here
    
    
    // 1st Method
    
//     bool **visited = new bool*[n];
//     for(int i=0;i<n;i++)
//     {
//         visited[i] = new bool[n];
//         for(int j=0;j<n;j++)
//         {
//             visited[i][j] = false;
//         }
//     }
    
//     int count = INT_MIN;
    
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(cake[i][j] == 1)
//             {
//                 int k = getBiggestPieceSizeHelper(cake, n, i, j, visited);
//                 if(count < k)
//                 {
//                     count = k;
//                 }
//             }
//         }
//     }
    
//     return count;
    
    
    // 2nd Method
    
    
    int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j] == 1 && !visited[i][j])
            {
                count = max(count, getBiggestPieceSizeHelper(cake, n, i, j, visited));
            }
        }
    }
    
    return count;
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}
