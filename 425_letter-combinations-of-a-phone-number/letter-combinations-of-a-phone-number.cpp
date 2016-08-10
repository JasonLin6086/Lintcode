/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/letter-combinations-of-a-phone-number
@Language: C++
@Datetime: 15-12-07 17:22
*/

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> result;
        int size = digits.size();
        if (size <= 0) return result;
        vector<string> mapNumber = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int i, j, k;
        result.push_back("");
        for (i=0; i<size; i++) {
            int pos = digits[i]-'0';
            vector<string> tmpRst;
            if (mapNumber[pos] != "") {
                string tmpStr = mapNumber[pos];
                for (j=0; j<result.size(); j++) {
                    for (k=0; k<tmpStr.size(); k++) {
                       tmpRst.push_back(result[j] + tmpStr[k]);
                    };
                }
                result.swap(tmpRst);
            }
        }
        return result;
    }
};