class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        //since we have to find the string which is same as backwards and forwards
        //it's feasibel if we have create two pointers one fixed at stat end is fixed at the end 
        //such that we can shrink our window for nay unmatched value
        

        int start = 0;
        int end = s.length()-1;
        while(start<end)
        {
        while(start < end && !((s[start]>='a' && s[start]<='z') || (s[start]>='A' && s[start]<='Z') || (s[start]>='0' && s[start]<='9')))start++;
        while(start < end && !((s[end]>='a' && s[end]<='z') || (s[end]>='A' && s[end]<='Z') || (s[end]>='0' && s[end]<='9')))end--;
        char l = s[start];
        char e = s[end];
        //convert uppercase letter to lowercase for any valida characters
        if(l>='A' && l<='Z') l = l-'A'+'a';
        if(e>='A' && e<='Z') e = e-'A'+'a';
        //compare characters if they don't match return false;
        if(l!=e) return false;
        start++;
        end--;
    }
    //else return true palindrome match found 
    return true;
    }
};
