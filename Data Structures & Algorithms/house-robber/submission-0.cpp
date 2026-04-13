class Solution {
public:
    int rob(vector<int>& nums) {
        //[1,1,3,3]
        //we can rob house no. 1 but we can't rob house no. 1 cause they are adjacent we can rob 3,3 instead
        //so it's liek an subproblem 
        //but we can't rob 3,3 we can either rob house 3 or house 3

        //Brute force is decision tree
        //Decision 1.
        //we can either rob house 1,3 or 1,3

        //decision 2.
        //we can rob 1,3 only

        //at max 4  money can rob


        //we rob at 0th index house then skip 1st index then rob at 2nd 
        //so 1,3 , or 1,3
        

        //for example case 2
        //2, 9, 8, 3, 6
        //so here we are find macx of subprolem of entire arrya 


        //How can we rob exactly then ?
        //recurrence relationship
        // rob = max(arr[0], rob[2:n] , rob[1:n])

        //Robbing the first house will be our base case 
        int n = nums.size();
        // int base = nums[0];
        //we only need to compute up until that point max rob money we have done to take decison 
        //2,7,9,3,1
        int rob1 = 0, rob2 = 0;
        //as we iterate through each and every house 
        for(int num : nums)
        {
            //[rob2, rob1, n, n+1]
            //rob2+num is the gap between current house and prev house
            //rob1 is current house
            int curr = max(rob2, rob1+num);
            rob1 = rob2;
            rob2 = curr;
        }

        return rob2;
    }
};
