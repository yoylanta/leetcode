class Solution {
public:
    vector<int> countDistances(vector<int>& edges, int node) {
        vector<int> distances(edges.size(), -1);
        int steps = 0;
        while (node!=-1 && distances[node]==-1) {
            distances[node]=steps++;
            node = edges[node];
        }
        return distances;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
     vector<int> d1 = countDistances(edges, node1);   
     vector<int> d2 = countDistances(edges, node2);
     int res=-1, min_dist = INT_MAX;
     for(int i=0; i<edges.size(); ++i) {
        if(d1[i]>=0 && d2[i]>=0) {
            int max_dist = max(d1[i],d2[i]);
            if(max_dist<min_dist) {
                min_dist = max_dist;
                res=i;
            }
        }
     } return res;
    }


};