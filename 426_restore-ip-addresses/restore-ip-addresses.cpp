/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/restore-ip-addresses
@Language: C++
@Datetime: 15-12-21 22:10
*/

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> result;
        string ip = "";
        helper(s, 0, 0, ip, result);
        return result;
    }
private:
    void helper(string& s, int start, int dotcount, string ip, vector<string>& rst) {
        if (start == s.size() && dotcount == 4) {
            ip = ip.substr(0, ip.size()-1);
            rst.push_back(ip);
            return;
        }
        if ((s.size()-start > 3*(4-dotcount)) || (s.size()-start < (4-dotcount))) {
            return;
        }
        int i, num = 0;
        for (i=start; i<start+3; i++) {
            ip += s[i];
            num = 10*num + (s[i]-'0');
            if (num <= 255 && num >= 0) {
                helper(s, i+1, dotcount+1, ip+'.', rst);
            }
            if (num == 0) {
                break;
            }
        }
    }
};