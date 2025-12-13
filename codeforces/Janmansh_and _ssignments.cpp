/*
Janmansh and Assignments
Janmansh has to submit 
3
3 assignments for Chingari before 
10
10 pm and he starts to do the assignments at 
X
X pm. Each assignment takes him 
1
1 hour to complete. Can you tell whether he'll be able to complete all assignments on time or not?

Input Format
The first line will contain 
T
T - the number of test cases. Then the test cases follow.
The first and only line of each test case contains one integer 
X
X - the time when Janmansh starts doing the assignments.
Output Format
For each test case, output Yes if he can complete the assignments on time. Otherwise, output No.

You may print each character of Yes and No in uppercase or lowercase (for example, yes, yEs, YES will be considered identical).

Constraints
1
=
T
=
10
1=T=10
1
=
X
=
9
1=X=9
Sample 1:
Input
Output
2
7
9
Yes
No
Explanation:
Test case-1: He can start at 
7
7pm and finish by 
10
10 pm. Therefore he can complete the assignments.

Test case-2: He can not complete all the 
3
3 assignments if he starts at 
9
9 pm.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,X;
	cin >> t;
    
    while(t--){
        cin>>X;
        
        if(X+3<=10){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}

