class Solution {
public:
    int characterReplacement(string s, int k) {
//         Input: s = "AAABABB", k = 1

// Output: 5

//putting A at index 3 AAAAABB
//how many times the character comes 
//map["A"->4, "B"->3]
//k=1
//7/3=
//n=7
int n = s.size();
//edge case if size of arrya is less
//if changing only one elemnet can return in maximum length of array 
//ba k=1 you can return the whole string 
if(n<k+2) return n;




unordered_map<char, int>count;

//safe starting value for the resukt
//all substring changing atmost k+1
//fr k=1     two consecutive letters will be same hence it safe to say that resulatnt length 
int result = k+1;
int maxF = 0;
int i=0;
for(int j=0; j<n; j++)
{
    maxF = max(maxF, ++count[s[j]]);
    //(j-i+1) is the sliding window which take into 
    //consideration new character added 
    //and at any given point of pount 
    //the window length become greater then k
    if((j-i+1-maxF)<=k)
    {
result = max(result, (j-i+1));
    }
    else
    {

        --count[s[i++]];
    }

}   
return result;                    




    }
};
