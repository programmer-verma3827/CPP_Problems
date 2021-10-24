/*
Sum or Product

Write a program that asks the user for a number N and a choice C. And then give them the possibility to choose between computing the sum and computing the product of all integers in the range 1 to N (both inclusive).
If C is equal to -
 1, then print the sum
 2, then print the product
 Any other number, then print '-1' (without the quotes)
Input format :
Line 1 : Integer N
Line 2 : Choice C
Output Format :
 Sum or product according to user's choice
Constraints :
1 <= N <= 12
Sample Input 1 :
10
1
Sample Output 1 :
55
Sample Input 2 :
10
2
Sample Output 2 :
3628800
Sample Input 3 :
10
4
Sample Output 3 :
-1


*/

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	
     // int n, sum=0, mul=0;
    // cin>>n;
    // for(int i=1;i<=n;i++)
    // {
    //     sum = sum + i;
    // }
    
    // cout<<sum<<endl;
    
//     int n, j, mul=1;
//     cin>>n;
//     for(j=1;j<=n;j++)
//     {
//         mul = mul*j;
//     }
    
//     cout<<mul<<endl;
    
//     return 0;
    
    
    int n, c;
    cin>>n>>c;
    int sum = 0, product = 1;
    for(int i = 1; i<=n; i++){
        sum += i;
        product *= i;
    }
    // if(c==1){
    //     cout<<sum<<endl;
    // }else if(c==2){
    //     cout<<product<<endl;
    // }else{
    //     cout<<-1<<endl;
    // }
    switch(c){
        case 1:
            cout<<sum<<endl;
            break;
        case 2:
            cout<<product<<endl;
            break;
        default:
            cout<<-1<<endl;
            break;
    }
    return 0;
}
