class Solution {
public:
    string minWindow(string s, string t) {
//        Input: s = "OUZODYXAZV", t = "XYZ"

// Output: "YXAZ" 



if(t.empty()) return "";
vector<int>freq(128, 0);
//Input: s = "OUZODYXAZV", t = "XYZ"


//we will store all the characters of t with each frequency in it 
for(char c  : t)
    //[[X, 1], [Y, 1], [Z,1]]
    freq[c]++;
//required = 3
int required = t.size();
int l = 0;
int minLen = INT_MAX;
int start = 0;
//start
//          l               
//                  r            
//O U Z O D Y X A Z V
for(int r=0; r<s.size(); r++)
{
    //l=6, r=9
    //required=1
    //O is not in t
    //U not in t
    //Z is in t
    //freq[Z]>0
    //O not in t
    //D not in t
    //Y in t
    //freq[Y] > 0
    //X in t
    //A not in t
    //Z in t
    //freq in Z > 0
    //V not in t

if(freq[s[r]]>0)

    //required=0
required--;    //r=0  r=1  r=2   r=4  r=5  r=6  r=7  r=9
//               r=3       r=8
freq[s[r]]--; //[O=0, U=1, Z=0, D=0, Y=0, X=0, A=0, V=0]

//l=0, r=6 , "O U Z O D Y X"
//l=3 , r=8, "O D Y X A Z"

while(required==0)
{
    //minlen = 9-6+1=4
    //YXAZ
    
    if(r-l+1<minLen)
    {
        
        minLen = r-l+1;
        
        start = l;
    }
//shrink from left
//    l       r  
//O U Z O D Y X
//freq[O]++ 
//freq[U]++
//freq[Z]++
//    l     r
//O D Y X A Z
freq[s[l]]++; //O=1 U=1 Z=1
            //O=1 D=1 Y=1
//Y in t
//freq[Y]++
    if(freq[s[l]]>0) 
    
//required = 1!=0
    required++;
    
    //l=6
    l++;
}
}
return minLen == INT_MAX ? "" : s.substr(start, minLen);

    }
};
