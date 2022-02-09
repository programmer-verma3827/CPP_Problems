/*

Coin Tower
Send Feedback
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus

*/


#include <iostream>
#include <string>
using namespace std;

#include <bits/stdc++.h>
#include <vector>


// bool findWinner_brute(int n, int x, int y)
// {
//     if(n == 1)
//     {
//         return true;
//     }
    
//     if(n <= 0)
//     {
//         return false;
//     }
    
//     int first = findWinner_brute(n-x, x, y);
//     int second = findWinner_brute(n-y, x, y);
//     int third = findWinner_brute(n-1, x, y);
    
//     if(first == false || second == false || third == false)
//     {
//         return true;
//     }
    
//     else
//     {
//         return false;
//     }
// }


// bool findWinner_memo(int n, int x, int y, int *output)
// {
//     if(n == 1)
//     {
//         return true;
//     }
    
//     if(n <= 0)
//     {
//         return false;
//     }
    
//     if(output[n] != -1)
//     {
//         return output[n];
//     }
    
//     int first = findWinner_memo(n-x, x, y, output);
//     int second = findWinner_memo(n-y, x, y, output);
//     int third = findWinner_memo(n-1, x, y, output);
    
//     bool ans = false;
//     if(first == false || second == false || third == false)
//     {
//         ans = true;
//     }
    
//     else
//     {
//         ans = false;
//     }
    
//     output[n] = ans;
//     return ans;
// }


string findWinner(int n, int x, int y)
{
	// Write your code here 
    
    
    // Dynamic Programming
    
    // 1st Method
    
    if(x > y)
    {
        swap(x, y);
    }
    
    bool *output = new bool[n+1];
    for(int i=1;i<=n;i++)
    {
        if(i == 1 || i == x || i == y)
        {
            output[i] = true;
        }
        
        if(i < x)
        {
            output[i] = !output[i-1];
        }
        
        else if(i < y)
        {
            output[i] = !(output[i-x] && output[i-1]);
        }
        
        else
        {
            output[i] = !(output[i-y] && output[i-x] && output[i-1]);
        }
    }
    
    bool result = output[n];
    delete [] output;
    
    if(result)
    {
        return "Beerus";
    }
    
    else
    {
        return "Whis";
    }
    
    
    // 2nd Method
    
//     vector<string> output(n+1);
//     output[0] = "Whis";
//     output[1] = "Beerus";
    
//     for(int i=2;i<n+1;i++)
//     {
//         if(i-1>=0 && output[i-1] == "Whis")
//         {
//             output[i] = "Beerus";
//         }
        
//         else if(i-x>=0 && output[i-x] == "Whis")
//         {
//             output[i] = "Beerus";
//         }
        
//         else if(i-y>=0 && output[i-y] == "Whis")
//         {
//             output[i] = "Beerus";
//         }
        
//         else
//         {
//             output[i] = "Whis";
//         }
//     }
    
//     return output[n];
    
    
    // Brute Force
    
//     if(findWinner_brute(n, x, y))
//     {
//         return "Beerus";
//     }
    
//     else
//     {
//         return "Whis";
//     }
    
    
    // Memoization
    
//     int *output = new int[n+1];
//     for(int i=0;i<=n;i++)
//     {
//         output[i] = -1;
//     }
    
//     if(findWinner_memo(n, x, y, output))
//     {
//         return "Beerus";
//     }
    
//     else
//     {
//         return "Whis";
//     }
    
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}
