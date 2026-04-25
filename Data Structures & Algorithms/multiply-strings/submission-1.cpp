class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
         //nums1 = 12
//nums2 = 34
int n1 = num1.size(); //2
int n2 = num2.size(); //2
//size = 2+2 = 4
//res=[0,0,0,0]
        vector<int>res(n1+n2, 0);
     

for(int i=n1-1; i>=0; i--)
{
  
    for(int j=n2-1; j>=0; j--)
    {
        
       int mul=(num1[i]-'0')*(num2[j]-'0');
        int sum = res[i+j+1]+mul;
        res[i+j+1] = sum%10;
        res[i+j] += sum/10;
    }
    
}
string result;
int i=0;
while(i<res.size() && res[i]==0)++i;
for(; i<res.size(); i++) result+=(res[i]+'0');
//"408"
return result;
        
    }
};
