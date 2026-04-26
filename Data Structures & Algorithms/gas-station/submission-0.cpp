class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         Input: gas = [1,2,3,4], cost = [2,2,4,1]

// Output: 3
//gas needed got less then teh total cost to travel we return -1 it's impossibel to finish circuit 
//10>9 false for this 
if(accumulate(gas.begin(), gas.end(), 0)<accumulate(cost.begin(), cost.end(), 0))
return -1;

int total_tank = 0; //current gas balance as you travel
int start_idx = 0;  // starting position for circuit

for(int i=0; i<gas.size(); i++)
{
    //1-2 = -1
    //
    total_tank+=gas[i]-cost[i];
    //-1<0
    if(total_tank<0)
    {
        //start_idx = 0+1 = 1
        start_idx = i+1;
        //total_tank = 0
        total_tank = 0;
    }
}
return start_idx;

    }
};
