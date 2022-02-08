/*

Ways To Make Coin Change
Send Feedback
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903

*/


#include <iostream>
using namespace std;

#include<bits/stdc++.h>

// Brute Force


int countWaysToMakeChange_brute(int denominations[], int numDenominations, int value)
{
    if(value == 0)
    {
        return 1;
    }
    
    if(value < 0)
    {
        return 0;
    }
    
    if(numDenominations <= 0 && value >= 1)
    {
        return 0;
    }
    
    return countWaysToMakeChange_brute(denominations, numDenominations-1, value) + countWaysToMakeChange_brute(denominations, 
    numDenominations, value - denominations[numDenominations - 1]);
}


// Memoization


// int countWaysToMakeChange_memo(int i, int denominations[], int numDenominations, int value, vector<vector<int>> &output)
// {
//     if(i >= numDenominations)
//     {
//         return 0;
//     }
    
//     if(value == 0)
//     {
//         return 1;
//     }
    
//     if(value < 1)
//     {
//         return 0;
//     }
    
//     if(output[i][value] != -1)
//     {
//         return output[i][value];
//     }
    
//     int answer = countWaysToMakeChange_memo(i+1, denominations, numDenominations, value, output) + countWaysToMakeChange_memo
//     (i, denominations, numDenominations, value - denominations[i], output);
    
//     output[i][value] = answer;
//     return output[i][value];
// }


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    
	//Write your code here
    
    
    // Dynamic Programming
    
//     if(value == 0)
//     {
//         return 1;
//     }
    
//     if(numDenominations <= 1 && value >= 1)
//     {
//         return 0;
//     }
    
//     if(value < 0)
//     {
//         return 0;
//     }
    
//     int output[value+1][numDenominations];
//     int x, y;
    
//     for(int i=0;i<numDenominations;i++)
//     {
//         output[0][i] = 1;
//     }
    
//     for(int i=1;i<value+1;i++)
//     {
//         for(int j=0;j<numDenominations;j++)
//         {
//             x = (i-denominations[j] >= 0) ? output[i-denominations[j]][j] : 0;
//             y = (j >= 1) ? output[i][j-1] : 0;
            
//             output[i][j] = x + y;
//         }
//     }
    
//     return output[value][numDenominations-1];
    
    
    // Memoization
    
//     vector<vector<int>>output(numDenominations + 1,vector<int>(value+1,-1));
    
//     return countWaysToMakeChange_memo(0, denominations, numDenominations, value, output);
    
    
    // Brute Force
    
    return countWaysToMakeChange_brute(denominations, numDenominations, value);
    
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}
