/*
Q1. Minimum Number of Operations to Have Distinct Elements
Solved
Medium
4 pt.
You are given an integer array nums.

In one operation, you remove the first three elements of the current array. If there are fewer than three elements remaining, all remaining elements are removed.

Repeat this operation until the array is empty or contains no duplicate values.

Return an integer denoting the number of operations required.

 

Example 1:

Input: nums = [3,8,3,6,5,8]

Output: 1

Explanation:

In the first operation, we remove the first three elements. The remaining elements [6, 5, 8] are all distinct, so we stop. Only one operation is needed.

Example 2:

Input: nums = [2,2]

Output: 1

Explanation:

After one operation, the array becomes empty, which meets the stopping condition.

Example 3:

Input: nums = [4,3,5,1,2]

Output: 0

Explanation:

All elements in the array are distinct, therefore no operations are needed.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105©leetcode

*/

//more time complexity
#include<vector>

bool areDistinct(vector<int>& nums) {
    unordered_set<int> s;
    for (int x : nums) {
        if (s.count(x)) return false;
        s.insert(x);
    }
    return true;
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c = 0;

        // Repeat until array is empty or all elements are distinct
        while (!nums.empty() && !areDistinct(nums)) {
            c++;

            // Remove first 3 elements, or all if fewer than 3
            if (nums.size() <= 3) {
                nums.clear();
            } else {
                nums.erase(nums.begin(), nums.begin() + 3);

            }
        }

        return c;
    }
};



//less timecomplexity
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        int idx = 0; 

        // Traverse from the back
        for (int i = n - 1; i >= 0; i--) {
            if (seen.count(nums[i])) {
                idx = i + 1;
                break;
            }
            seen.insert(nums[i]);
        }

        // Elements to remove from front
        int toRemove = idx;

        // Each operation removes 3 elements
        return (toRemove + 2) / 3;
    }
};
©leetcode
