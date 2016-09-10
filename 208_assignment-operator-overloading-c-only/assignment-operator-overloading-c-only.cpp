/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/assignment-operator-overloading-c-only
@Language: C++
@Datetime: 15-09-21 16:20
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (this != &object) {
            // 1: Allocate new memory and copy the elements.
            char *new_pData = NULL;
            if (object.m_pData != NULL) {
                int count = strlen(object.m_pData);
                new_pData = new char[count];
                copy(object.m_pData, object.m_pData + count, new_pData);
            }

            // 2: Deallocate old memory.
            if (m_pData != NULL) {
                delete[] m_pData;
            }

            // 3: Assign the new memory to the object.
            m_pData = new_pData;;
        }
        return *this;
    }
};
