/*

Running Median
Send Feedback
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3

*/

#include <iostream>
using namespace std;

#include <cmath>
#include <queue>

void findMedian(int *arr, int n)
{
    // Write your code here
    
  // 1st Method
  
    if(n == 0)
    {
        return;
    }
    
    priority_queue<int> p;
    priority_queue<int, vector<int>, greater<int>> q;
    
    int median = arr[0];
    p.push(arr[0]);
    cout<<median<<" ";
    
    for(int i=1;i<n;i++)
    {
        int x = arr[i];
        if(x <= p.top())
        {
            p.push(x);
        }
        else
        {
            q.push(x);
        }
        
        if(p.size() == q.size())
        {
            median = (p.top() + q.top()) / 2;
            cout<<median<<" ";
        }
        
        else
        {
            if(p.size() > q.size() && (p.size() - q.size()) > 1)
            {
                q.push(p.top());
                p.pop();
                median = (p.top() + q.top()) / 2;
                cout<<median<<" ";
            }
            
            else if(q.size() > p.size() && (q.size() - p.size()) > 1)
            {
                p.push(q.top());
                q.pop();
                median = (p.top() + q.top()) / 2;
                cout<<median<<" ";
            }
            
            else
            {
                median = (p.size() > q.size()) ? p.top() : q.top();
                cout<<median<<" ";
            }
        }
        
    }
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
