/*


844. Backspace String Compare
Solved
Easy
Topics
premium lock icon
Companies
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?

*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ps=s.length()-1;
        int pt=t.length()-1;


        while(ps>=0 || pt>=0){
            ps=get_valid_ind(s,ps);
            pt=get_valid_ind(t,pt);

            if(ps<0 && pt<0){
                return true;
            }

            if(ps<0 || pt<0){
                return false;
            }else if(s[ps]!=t[pt]){
                return false;
            }

            pt--;
            ps--;
        }

        return true;
    }

    int get_valid_ind(string str,int end){
        int backspace_count=0;

        while(end>=0){
            if(str[end]=='#'){
                backspace_count++;
            }else if(backspace_count>0){
                backspace_count--;
            }else{
                break;
            }

            end--;
        }

        return end;
    }
};


