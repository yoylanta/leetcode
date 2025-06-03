class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        const int n = status.size();
        queue<int> q;
        vector<bool> have_keys(n, false);
        vector<bool> have_boxes(n, false);
        vector<bool> visited(n, false);
        int total_candies=0;

       for(int box: initialBoxes){
        have_boxes[box]=true;
        if(status[box]==1) q.push(box);
       }

       while(!q.empty()){
        int temp_box=q.front();
        q.pop();

        if (visited[temp_box]) continue;
        visited[temp_box]=true;

        total_candies+=candies[temp_box];

        for (int temp_key : keys[temp_box]){
            if (!have_keys[temp_key]){
                have_keys[temp_key]=true;
                if( have_boxes[temp_key] && !visited[temp_key]){
                    q.push(temp_key);
                }
            }
        }

        for(int temp_contained_box : containedBoxes[temp_box]){
            if(!have_boxes[temp_contained_box]){
                have_boxes[temp_contained_box] = true;
            }
            if(!visited[temp_contained_box] && (status[temp_contained_box]==1 || have_keys[temp_contained_box])){
                q.push(temp_contained_box);
            }
        }

       }
       
    return total_candies;
    }
};