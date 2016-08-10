/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 16-06-30 01:51
*/

class MinStack {
private:
    vector<int> minList;
    vector<int> stk;
    
public:
    MinStack() {
        // do initialization if necessary
        minList.push_back(INT_MAX);
    }

    void push(int number) {
        // write your code here
        stk.push_back(number);
        if (number < minList.back()) {
            minList.push_back(number);
        } else {
            minList.push_back(minList.back());
        }
    }

    int pop() {
        // write your code here
        minList.pop_back();
        int result = stk.back();
        stk.pop_back();
        return result;
    }

    int min() {
        // write your code here
        return minList.back();
    }
};

