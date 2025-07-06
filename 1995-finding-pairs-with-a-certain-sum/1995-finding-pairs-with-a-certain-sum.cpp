class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2){
        for(int i : this->nums2){
            freq[i]++;
        }
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index]+=val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for(int i : nums1){
            int complement = tot - i;
            if(freq.count(complement)) res+=freq[complement];
        } return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */