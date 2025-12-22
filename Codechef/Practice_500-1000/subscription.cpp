/*
Subscriptions
A new TV streaming service was recently started in Chefland called the Chef-TV.

A group of 
N
N friends in Chefland want to buy Chef-TV subscriptions. We know that 
6
6 people can share one Chef-TV subscription. Also, the cost of one Chef-TV subscription is 
X
X rupees. Determine the minimum total cost that the group of 
N
N friends will incur so that everyone in the group is able to use Chef-TV.

Input Format
The first line contains a single integer 
T
T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two integers 
N
N and 
X
X — the size of the group of friends and the cost of one subscription.
Output Format
For each test case, output the minimum total cost that the group will incur so that everyone in the group is able to use Chef-TV.

Constraints
1
=
T
=
1000
1=T=1000
1
=
N
=
100
1=N=100
1
=
X
=
1000
1=X=1000
Sample 1:
Input
Output
3
1 100
12 250
16 135
100
500
405
Explanation:
Test case 1: There is only one person in the group. Therefore he will have to buy 
1
1 subscription. Therefore the total cost incurred is 
100
100.
Test case 2: There are 
12
12 people in the group. Therefore they will have to buy 
2
2 subscriptions. Therefore the total cost incurred is 
500
500.
Test case 3: There are 
16
16 people in the group. Therefore they will have to buy 
3
3 subscriptions. Therefore the total cost incurred is 
405
405.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >>t ;
    
    while(t--){
        int N,X;
        
        cin>>N>>X;
        
        int min= N/6>0? N/6:1;
        if(N/6<0){
            min=1;
        }else if(N%6==0&&N/6>0){
            min=N/6;
        }else{
            min=N/6+1;
        }
        
        
        int cost=min*X;
        cout<<cost<<endl;
    }
}

