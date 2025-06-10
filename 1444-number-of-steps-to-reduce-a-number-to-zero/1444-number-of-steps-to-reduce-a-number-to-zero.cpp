class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num) {
            num = (num & 1) ? num - 1 : num >> 1;
            cnt++;
        }
        return cnt;
    }
};