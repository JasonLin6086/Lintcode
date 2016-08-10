/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/building-outline
@Language: C++
@Datetime: 16-03-29 16:29
*/

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ?  a.second < b.second : a.first < b.first;
}
class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int>> result;
        vector<pair<int, int>> dict;
        int size_ = buildings.size();
        if(size_ == 0)  return result;

        for(int i = 0; i < size_; i++) {
            dict.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            dict.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(dict.begin(), dict.end(), compare);


        multiset<int> max_height {0};
        int pre = 0;
        for(int i = 0; i < dict.size(); i++) {
            //cout<<i<<":"<<dict[i].first<<dict[i].second<<endl;
            if(dict[i].second < 0) {
                max_height.insert(-dict[i].second);
            } else {
                max_height.erase(max_height.find(dict[i].second));
            }

            int cur = *(max_height.rbegin());
            if(cur != pre) {
                result.push_back({dict[i].first, 0, cur});
                pre = cur;
            }
        }

        //cout<<result.size()<<endl;
        for(int i = 0; i < result.size() - 1; i++) {
            result[i][1] = result[i+1][0];
        }

        vector<vector<int>> outline;
        for(int i = 0; i < result.size(); i++) {
            if(result[i][2] != 0)  outline.push_back(result[i]);
        }
        return outline;
    }
};
