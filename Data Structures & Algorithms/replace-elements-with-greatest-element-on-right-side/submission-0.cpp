class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //max(2, 1) = 2

        //[2,4,5,3,1,2]

//for last elemnt we only able to get the -1
        int currMax = -1;

//temp
//-1 = arr[i]
//currmax = -1
//[-1, 2]]
        for(int i=arr.size()-1; i>=0 ; i--)
        {
            int temp = arr[i];
            arr[i] = currMax;
            currMax = max(temp, currMax);
        }
return arr;
        
    }
};