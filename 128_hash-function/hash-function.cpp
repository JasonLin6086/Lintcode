/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 16-03-16 17:24
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long res = 0;
        for (int i = 0; i < key.size(); i++){
            res = 33 * res + (int)key[i];
//            cout<<res<<endl;
            res = res % HASH_SIZE;
//            cout<<res<<endl;
        }
        return (int)res;
    }
};
