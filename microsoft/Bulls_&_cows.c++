class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, int> mp1;
        map<int, int> mp2;
        int n = secret.size();
        string s="";
        int cntb = 0;
        int cntc = 0;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                cntb++;
            }
            else
            {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for(auto it: mp1)
        {
            if(mp2.find(it.first)!=mp2.end())
            {
                cntc += min(mp2[it.first],it.second);
            }
        }
        s += to_string(cntb) + "A" + to_string(cntc) + "B";
        return s;
    }
};