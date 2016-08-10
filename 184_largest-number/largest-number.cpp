/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/largest-number
@Language: C++
@Datetime: 15-09-08 06:52
*/

bool myfunction(int i, int j) {
	return to_string(i)+to_string(j) > to_string(j)+to_string(i);
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // sort numbers
        sort(num.begin(), num.end(), myfunction);

        // combine the numbers
        string max_num;
        for (auto& i : num) {
            max_num.append(to_string(i));
        }

        // special case: start with zero (e.g. [0, 0])
        if (max_num[0] == '0')  {
            return "0";
        }

        return max_num;
    }
};
