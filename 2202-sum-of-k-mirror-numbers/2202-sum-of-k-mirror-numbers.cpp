class Solution {
private:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string toBaseK(long long value, int base) {
        if (value == 0) return "0";
        string out;
        while (value > 0) {
            out.push_back(char('0' + (value % base)));
            value /= base;
        }
        reverse(out.begin(), out.end());
        return out;
    }

    long long createPalindrome(long long half, bool isOdd) {
        long long pal = half;
        if (isOdd) half /= 10;
        while (half > 0) {
            pal = pal * 10 + (half % 10);
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
        long long sum = 0;
        int remaining = n;

        for (int length = 1; remaining > 0; ++length) {
            bool isOdd = (length % 2 == 1);
            int halfLen = (length + 1) / 2;

            long long start = (length == 1) ? 1LL : ipow10(halfLen - 1);
            long long end   = ipow10(halfLen);

            for (long long half = start; half < end && remaining > 0; ++half) {
                long long pal = createPalindrome(half, isOdd);
                if (isPalindrome(toBaseK(pal, k))) {
                    sum += pal;
                    --remaining;
                }
            }
        }

        return sum;
    }
};
