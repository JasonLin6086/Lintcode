/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: C++
@Datetime: 15-09-08 16:07
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        const auto len = A.size();

        // Handle boundary case
        if (len == k) {
            return "0";
        }

        // If a digit is greater than next one, delete it.
        stack<char> s;
        for (auto i = 0; i < len; ++i) {
            while (k > 0 && !s.empty() && s.top() > A[i]) {
                s.pop();
                --k;
            }
            s.push(A[i]);
        }

        // If all digits are increasingly sorted, delete last.
        while (k > 0) {
            s.pop();
            --k;
        }

        // Assemble the answer in reverse order
        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        // Strip all leading '0'
        auto i = 0;
        for (; i < ans.length() && ans[i] == '0'; ++i);
        ans = ans.substr(i);

        // Handle boundary case
        if (ans.length() == 0) {
            return "0";
        }

        return ans;
    }
};

