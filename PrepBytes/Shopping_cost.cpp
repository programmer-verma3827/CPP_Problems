/*
Shopping Cost
Tina is preparing a shopping list containing 
N
 items. She knows the quantity and price of each item on the list. The shop is offering a 
20
%
 discount on the items with a quantity of more than 
100
 units. Given the quantity and price of each of the 
N
 items, your task is to calculate how much each item will cost.

Input format
The first line of the input contains an integer 
N
 denoting the number of items
Each of the next 
N
 lines contains two space-separated integers denoting the quantity and price of the item.

Output format
Print the final cost that Tina has to bear for each item. Print till a single digit after the decimal point.

Constraints
1
<=
N
<=
10

1
<=
q
u
a
n
t
i
t
y
,
p
r
i
c
e
<=
10
3

Time Limit
1
 second

Example
Input
3

100
 
120

200
 
100

50
 
50

Output
12000.0

16000.0

2500.0

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  
  float n, quantity, price;
  float revprice, priceless, orprice, totalprice, totalprice2;
  cin>>n;
  while(n>=1)
  {
    cin>>quantity>>price;
    if(quantity>100)
    {
       revprice = 0.2*price;
       priceless = price-revprice;
       totalprice = quantity*priceless;
    }
    else
    {
       orprice = price;
       totalprice2 = quantity*orprice;
    }
    
    n--;
    
  if(quantity>100)
  {
  cout<<setprecision(1)<<fixed<<totalprice*1.0<<endl;
  }
  else
  {
  cout<<setprecision(1)<<fixed<<totalprice2*1.0<<endl;
  }
    
  }
    

  return 0;
}
