class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
       queue<int> q;
       unordered_set<int> have_keys;
       unordered_set<int> have_boxes;
       unordered_set<int> visited;
       int total_candies=0;

       for(int box: initialBoxes){
        have_boxes.insert(box);
        if(status[box]==1) q.push(box);
       }

       while(!q.empty()){
        int temp_box=q.front();
        q.pop();

        if (visited.contains(temp_box)) continue;
        if (status[temp_box]==0 && !have_keys.contains(temp_box)) continue;

        visited.insert(temp_box);
        total_candies+=candies[temp_box];

        for (int temp_key : keys[temp_box]){
            if (!have_keys.contains(temp_key)){
                have_keys.insert(temp_key);
                if( have_boxes.contains(temp_key) && !visited.contains(temp_key)){
                    q.push(temp_key);
                }
            }
        }

        for(int temp_contained_box : containedBoxes[temp_box]){
            if(!have_boxes.contains(temp_contained_box)){
                have_boxes.insert(temp_contained_box);
            }
            if(!visited.contains(temp_contained_box) && (status[temp_contained_box]==1 || have_keys.contains(temp_contained_box))){
                q.push(temp_contained_box);
            }
        }

       }
       
    return total_candies;
    }
};