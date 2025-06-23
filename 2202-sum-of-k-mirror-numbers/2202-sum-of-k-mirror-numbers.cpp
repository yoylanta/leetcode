class Solution {
private:
    bool isPalindrome(const string& s){
        int left = 0, right = s.size()-1;
        while(left<right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k){
        if (num == 0) return "0";
        string result;
        while (num > 0){
            result = char('0' + (num % k)) + result;
            num /= k;
        }
        return result;
    }

    long long createPalindrome(long long half, bool isOdd) {
        long long pal = half;
        if (isOdd) half /= 10;
        while (half > 0) {
            pal = pal * 10 + half % 10;
            half /= 10;
        }
        return pal;
    }

    long long ipow10(int exp) {
        long long r = 1;
        while (exp-- > 0) r *= 10;
        return r;
    }

 public:
    long long kMirror(int k, int n) {
        long long sum=0;
        int num = n;

        for(int len=1; num>0;++len){
            long long start = (len == 1) ? 1 : ipow10((len + 1) / 2 - 1);
            long long end=(long long)pow(10,(len+1)/2);
            bool isOdd = (len % 2 == 1);
            for (long long half = start; half < end && num > 0; ++half) {
                long long p = createPalindrome(half, isOdd);
                string basek = toBaseK(p, k);
                if (isPalindrome(basek)) {
                    sum += p;
                    --num;
                }
            }
        }
        return sum;
    }
};