/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/minimum-window-substring
@Language: C++
@Datetime: 16-01-29 20:33
*/

class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        int sizeS = source.size(), sizeT = target.size();
        if (sizeT > sizeS) return "";
        int winStart=-1, winEnd=sizeS, start=0, end=0;
        int search[256] = {0};
        int found[256] = {0};
        int hasfound = 0;
        for (int i=0; i<sizeT; i++) {
            search[target[i]]++;
        }
        for (; end<sizeS; end++) {
            if (search[source[end]] > 0) { //found one char
                found[source[end]]++;
                if (found[source[end]] <= search[source[end]]) {
                    hasfound ++;
                }
                if (hasfound == sizeT) {
                    while (search[source[start]] == 0 ||
                           found[source[start]] > search[source[start]]) {
                        if (search[source[start]] > 0) {
                            found[source[start]] --;
                        }           
                        start ++;
                    }
                
                    if (end - start < winEnd - winStart + 1) {
                        winStart = start;
                        winEnd = end;
                    }
                }
            }
        }
        if (winStart == -1) return "";
        else {
            return source.substr(winStart, winEnd-winStart+1);
        }
    }
};
