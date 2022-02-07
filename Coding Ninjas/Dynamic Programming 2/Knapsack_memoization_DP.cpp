/*

Code: Knapsack (Memoization and DP)
Send Feedback
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13

*/


#include <cstring>
#include <iostream>
using namespace std;

#include <vector>


// Memoization


int knapsack_memo(int* weight, int* value, int n, int maxWeight, int **output)
{
        
    if(n == 0 || maxWeight == 0)
    {
        return 0;
    }
    
    if(output[n][maxWeight] != -1)
    {
        return output[n][maxWeight];
    }
    
    int ans;
    
    if(weight[0] > maxWeight)
    {
        ans = knapsack_memo(weight+1, value+1, n-1, maxWeight, output);
    }
    
    else
    {
        int a = knapsack_memo(weight+1, value+1, n-1, maxWeight-weight[0], output) + value[0];
        int b = knapsack_memo(weight+1, value+1, n-1, maxWeight, output);
        
        ans = max(a, b);
    }
    
    output[n][maxWeight] = ans;
    return output[n][maxWeight];
}


// Dynamic Programming


int knapsack(int* weight, int* value, int n, int maxWeight) {
    
	// Write your code here
    
//     vector<vector<int>> output(2, vector<int>(maxWeight+1, 0));
    
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=1;j<=maxWeight;j++)
//         {
//             if(weight[i] <= j)
//             {
//                 output[i%2][j] = max((value[i] + output[(i+1)%2][j-weight[i]]), output[(i+1)%2][j]);
//             }
            
//             else
//             {
//                 output[i%2][j] = (output[(i+1)%2][j]);
//             }
//         }
//     }
    
//     return output[(n+1)%2][maxWeight];
    
    
    int **output = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        output[i] = new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++)
        {
            output[i][j] = -1;
        }
    }
    
    return knapsack_memo(weight, value, n, maxWeight, output);
}


int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
