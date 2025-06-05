class Solution {
private:
    vector<int> parent;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y){
        int px=find(x);
        int py=find(y);
        if (px==py) return;
        if (px<py){
            parent[py]=px;
        } else{
            parent[px]=py;
        }
    }
public:
    Solution(){
        parent.resize(26);
        for(int i=0;i<26;++i){
            parent[i]=i;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<s1.size();++i){
            unite(s1[i]-'a',s2[i]-'a');
        }
        string res="";
        for(char ch : baseStr){
            res+=find(ch-'a')+'a';
        }
        return res;
    }
};