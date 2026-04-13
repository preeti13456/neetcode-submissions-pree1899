class Solution {
public:
    string longestPalindrome(string s) {
       //Two pointer approach 
       //every palindrom has one of the two centers

       //odd length center between two characters
       //aa

//single character center in odd length
       //babab

       //1. Instead of checking all substrings we:
       //taking each center as. apossible center
       //expand left and right while characters match
       //track longest plaindrome found during expansion


       //resIdx = 0;
       //resLen = 0;
       //odd length 
       //l = i, r=i
       //expand while l>=0, r<nand s[l]==s[r] 


       //resIdx = 0;
       //resLen = 0;
       //evenlength 
       //l = i, r=i+1
       //expand while l>=0, r<nand s[l]==s[r] 

       //update them 
       //resIdx ;
       //resLen;
       //return s[resIdx+resLen]

       int resIdx = 0;
       int resLen = 0;
int n = s.size();
       for(int i=0; i<s.size(); i++)
       {
        int l = i, r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            if(r-l+1>resLen)
            {
                resIdx = l;
                resLen = r-l+1;
            }
            l--;
            r++;
        }
        l=i; r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            if(r-l+1>resLen)
            {
                resIdx = l;
                resLen = r-l+1;
            }
            l--;
            r++;
        }
       }
return s.substr(resIdx, resLen);
    }
};
