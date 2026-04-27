class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        if(n==1) return true;
        int su;
        int cpy = n;
        while(n)
        {
            su = 0;
            while(cpy >= 1)
            {
                int mod = cpy % 10;
                su += mod*mod;
                cpy = cpy/10;
            }
            if(su==1) return true;
            if(seen.count(su)) return false;
            seen.insert(su);
            cpy = su;
        }
        return false;
    }
};
