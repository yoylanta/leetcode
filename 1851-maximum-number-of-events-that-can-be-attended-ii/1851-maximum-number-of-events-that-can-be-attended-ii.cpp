class Solution {
private:
    int n;
    vector<int> starts, nxt;
    vector<vector<int>> memo;
    vector<vector<int>> const* events;
    int dp(int i, int remaining){
        if(i>=n || remaining == 0) return 0; //no more events left to check or we are not able to attend any more events
        if(memo[i][remaining]!=-1) return memo[i][remaining]; //in case we already precomputed smth
        int best=dp(i+1,remaining);//skip the event option
        best=max(best, (*events)[i][2]+dp(nxt[i],remaining-1)); //choose max between the skip opotion and the attend option
        return memo[i][remaining]=best;
    };
public:
    int maxValue(vector<vector<int>>& events, int k) {
        this->n = events.size();
        k=min(k,n); //we cannot attend more than all the events in the events array
        sort(events.begin(),events.end(),[](auto& a, auto& b){return a[0]<b[0];});
        starts.resize(n);
        for(int i =0;i<n;++i) starts[i]=events[i][0]; //here we get array of only startDays of all events sorted ascendingly 
        nxt.resize(n);
        for(int i =0; i<n;++i){
            nxt[i]=upper_bound(starts.begin(),starts.end(),events[i][1]) - starts.begin(); //this way we will find the nearest available next event. its startDay should be strictly > than our current event's endDay. we will get the zero-based idx of such event in starts ector 
        }
        memo.assign(n, vector<int>(k+1, -1));
        this->events = &events;
        return dp(0, k);
    }
};