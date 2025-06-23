class Solution {
private:
    int gcd(int a, int b){
        while(b!=0){
            int t=a%b;
            a=b; b=t;
        } return a;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        int g= gcd(str1.size(),str2.size());
        return str1.substr(0,g);
    }
};