/*
Column Wise Sum

Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.
Input Format :
First and only line of input contains M and N, followed by M * N space separated integers representing the elements in the 2D array.
Output Format :
Sum of every ith column elements (separated by space)
Constraints :
1 <= M, N <= 10^3
Sample Input :
4 2 1 2 3 4 5 6 7 8
Sample Output :
16 20

*/

#include<iostream>
using namespace std;

void calc_csum(int arr[10000][10000], int m, int n) {
   int i,j,sum = 0;
    for(int j = 0;j<n;j++){
        for(int i=0;i<m;i++)
            sum = sum + arr[i][j];
      cout << sum <<" ";
      sum = 0;
   }
}

int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    
    int i,j;
    int m, n;
    cin >> m >> n;
   int arr[10000][10000];
   int x = 1;
   for (i = 0; i < m; i++)
   		for (j = 0; j < n; j++)
   			cin >> arr[i][j];
    
   calc_csum(arr, m, n);
   return 0;  
  
}
