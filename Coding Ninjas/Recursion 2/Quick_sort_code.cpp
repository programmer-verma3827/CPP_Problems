/*
Quick Sort Code

Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7

*/

#include<iostream>
#include "Solution.h"
using namespace std;

/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/

int partition(int input[], int start, int end)
{
    
    int l=end;
    int j=end+1;
    int pivot=input[start];
    
for(l;l>start;l--){
    if(pivot<input[l]){
        j--;
        // swap(input[l],input[j]);
        int t=input[l];
        input[l]=input[j];
        input[j]=t;
        
    }
}
    int x=input[j-1];
    input[j-1]=pivot;
    input[start]=x;
    return j-1;
    
}

void quickSortPart(int input[], int start, int end)
{
    if(start>=end)
    {
        return;
    }
    
    int index = partition(input, start, end);
    
    quickSortPart(input, start, index-1);
    quickSortPart(input, index+1, end);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    
    int start = 0;
    int end = size-1;
    
    quickSortPart(input, start, end);

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}
