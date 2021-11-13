/*
Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 

*/

#include <iostream>
#include "solution.h"
using namespace std;

void merge(int input[],int si,int mid,int ed)
{
   int size1=(mid+1)-si;
   int size2=ed-mid;
   int l[size1],m[size2];
    
    for(int i=0;i<size1;i++)
        l[i]=input[si+i];
    
    for(int j=0;j<size2;j++)
        m[j]=input[mid+1+j];
    
    int i=0,j=0,k=si;
   while(i<size1 && j<size2)
   {
       if(l[i]<=m[j]){
           input[k]=l[i];
           k++;
           i++;
       }
       else
       {
           input[k]=m[j];
            k++;
            j++;
       }           
   }
    while(i<size1)
    {
        input[k]=l[i];
        k++;
        i++;
    }
    while(j<size2)
    {
        input[k]=m[j];
        k++;
        j++;
    }    
}


void mergeR(int input[],int si,int ed){
    if(si>=ed)
        return;
    
    int mid=(si+ed)/2;
    mergeR(input,si,mid);
    mergeR(input,mid+1,ed);
    
    merge(input,si,mid,ed);
}

void mergeSort(int input[], int size){
	int si=0;
    int ed=size-1;    
     mergeR(input,si,ed);    
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
