/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/singleton
@Language: C++
@Datetime: 15-09-19 06:32
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution *instance = new Solution();

        return instance;
    }

    // Noncopyable.
    Solution(const Solution&) = delete;
    Solution& operator=(const Solution&) = delete;
private:
    Solution() {}
    ~Solution() {}   
};
