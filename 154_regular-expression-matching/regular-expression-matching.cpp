/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/regular-expression-matching
@Language: C++
@Datetime: 16-06-30 16:05
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *ss, const char *pp) {
        // write your code here
        string s=string(ss), p=string(pp);
        int sSize = s.size(), pSize = p.size(), i, j;
        bool checked[sSize+1][pSize+1];

        for(j=2, checked[0][0]=true, checked[0][1]= false; j<=pSize; ++j) // match s[0..0]
            checked[0][j] = p[j-1] == '*'? checked[0][j-2]  : false;

        for(i=1; i<=sSize; ++i) {
            for(j=1, checked[i][0]=false; j<=pSize; ++j) {
                if(p[j-1]=='*') // case (1)
                    checked[i][j] = (j>1) && ( checked[i][j-2]  || ( ( checked[i-1][j]) && (s[i-1]== p[j-2] || p[j-2] == '.')) );
                else // case (2)
                    checked[i][j] = checked[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');        
            }
        }
        return checked[sSize][pSize];     
    }
};
