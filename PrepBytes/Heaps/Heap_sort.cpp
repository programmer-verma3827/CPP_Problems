/*

Heap Sort
Given an array containing 
N
 integers, your task is to create a min-heap using the elements of the given array and sort the array in descending order using heap sort.

Note: Use heap concepts to solve the problem.

Input Format :
First line contains integer 
T
 denoting the number of test cases.
For each test case :
The first line contains an integer 
N
 denoting the number of elements in the array.
The second line contains 
N
 space-separated integers.

Output Format:
For each test case print the min-heap array after the required sorting.

Constraints:
1
<=
T
<=
10

1
<=
N
<=
10
6

1
<=
A
[
i
]
<=
10
6

Time Limit
1
 second

Example
Sample Input :
2
5
3 2 4 1 5
4
4 2 3 4

Sample Output :
5 4 3 2 1 
4 4 3 2

*/

#include <bits/stdc++.h>
using namespace std;

void heapSort(int input[], int n)
{
  // Building heap
    
    for(int i=1;i<n;i++)
    {
        int childIndex = i;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if(input[childIndex] < input[parentIndex])
            {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    // Sorting
    
    int size = n;
    while(size > 1)
    {
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;
        
        size--;
        
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        
        while(leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if(input[minIndex] > input[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            
            if(rightChildIndex < size && input[rightChildIndex] < input[minIndex])
            {
                minIndex = rightChildIndex;
            }
            
            if(minIndex == parentIndex)
            {
                break;
            }
            
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;
            
            parentIndex=minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
        
    }
}

int main()
{
  //write your code here
  
  int t;
  cin>>t;
  while(t--)
  {
    int size;
    cin>>size;
    int *input = new int[size];
    for(int i=0;i<size;i++)
    {
      cin>>input[i];
    }
    
    heapSort(input, size);
    for(int i=0;i<size;i++)
    {
      cout<<input[i]<<" ";
    }
    cout<<endl;
  }
  
  return 0;
}
