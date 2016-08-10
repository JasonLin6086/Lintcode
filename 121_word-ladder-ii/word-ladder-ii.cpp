/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/word-ladder-ii
@Language: C++
@Datetime: 15-12-02 19:43
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        unordered_map<string, set<string>> backPath;
        
        // BFS, each round is a generation
        set<string> generations[2];
        int curGen = 0;
        
        generations[curGen].insert(start);
        while(dict.size() > 0 && generations[curGen % 1].size() > 0) 
        {
            // end is in current generation, stop
            if (backPath.count(end) == 1) 
              break;

           // clear words from the dictionary to avoid it' apear in future generation again
            for(string word : generations[curGen & 1]) 
                dict.erase(word);
                
            generations[(curGen+1) & 1].clear();
            for(string from : generations[curGen & 1]) {
                string newWord = from;
                for(int i = 0; i < newWord.length(); i++) {
                    char origC = from[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        newWord[i] = c;
                        if (dict.count(newWord) == 1) 
                        {
                           backPath[newWord].insert(from);
                           generations[(curGen+1) & 1].insert(newWord);
                        }
                    }
                    newWord[i] = origC;
                }
            }
            
            curGen += 1;
        }
        
        vector<vector<string>> output;
        vector<string> temp;
        buildPath(backPath, temp, end, output);
        return output;
    }
    
    void buildPath(
        unordered_map<string, set<string>> &backPath, 
        vector<string> &temp,
        string end, 
        vector<vector<string>> &output)
    {
        temp.push_back(end);
        if (backPath.count(end) != 1) {
            vector<string> path = temp;
            reverse(path.begin(), path.end());
            output.push_back(path);
        }
        else {
            for(string word: backPath[end]) 
               buildPath(backPath, temp, word, output); 
        }
        temp.pop_back();
    }
};
