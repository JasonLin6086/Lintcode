/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/sort-colors-ii
@Language: C++
@Datetime: 15-11-17 17:48
*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int size = colors.size();
        if (size<=1) return;
        int i, end=size-1;
        for (i=0; i<k; i++) {
            end = helper(colors,end,k-i);
        }
    }
private:
    int helper(vector<int> &colors, int end, int pivot) {
        int l=0, r=end;
        while (l<=r) {
            while (l<r && colors[l]<=pivot) l++;
            while (r>0 && colors[r]>pivot) r--;
            if (l<=r) {
                swap(colors[l],colors[r]);
                l++; r--;
            }
        }
        return l-1;
    }
};
