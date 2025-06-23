class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> greatest;
        int maxCandies= *max_element(candies.begin(), candies.end());
        for(int i = 0; i<candies.size(); ++i){
            if(extraCandies+candies[i]>=maxCandies) greatest.push_back(true);
            else greatest.push_back(false);
        }
        return greatest;
    }
};