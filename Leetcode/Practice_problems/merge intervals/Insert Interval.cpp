/*

57. Insert Interval
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

*/


class Solution {
    vector<vector<int>> merge_intervals(vector<vector<int>> a){
        vector<vector<int>> ans;

        int start1=a[0][0];
        int end1=a[0][1];

        for(int i=1;i<a.size();i++){
            int start2=a[i][0];
            int end2=a[i][1];

            if(end1>=start2){
                start1=start1;
                end1=max(end1,end2);
                continue;
            }

            ans.push_back({start1,end1});
            start1=start2;
            end1=end2;
        }

        ans.push_back({start1,end1});
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool insert=false;
        for(int i=0;i<intervals.size();i++){
            if(insert==false && intervals[i][0]>newInterval[0]){
                res.push_back(newInterval);
            }

            res.push_back(intervals[i]);
        }

        if(insert==false){
            res.push_back(newInterval);
        }

        vector<vector<int>>ans;
        ans=merge_intervals(res);

        return ans;
    }
};
