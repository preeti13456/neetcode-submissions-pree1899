class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
//         Input: temperatures = [30,38,30,36,35,40,28]

// Output: [1,4,1,2,1,0,0]
//n = 7
int n = temperatures.size();

vector<int>ans(n, 0); //[0,0,0,0,0,0,0]
//stack to track temperature and index
stack<pair<int, int>>st;//[[_,_],[_,_]]
for(int i=0; i<n; i++)
{
    //stack not empty nd current temperature is hotter
    //then top of stack
    //pop from stack and set answer for index as number of days waited
    //push current day and index onto stack
    //38>30
    //30<38
    //36>30
    //35<36
    //40>35
    //40>36
    //40>38
    //28<40
while(!st.empty() && st.top().first<temperatures[i])
{
    //ans[0] = 1-0 = 1
    
    //ans[2] = 3-2 = 1
    //ans[4] = 5-4 = 1
    //ans[3] = 5-3 = 2
    //ans[1] = 5-1 = 4 

ans[st.top().second] = i-st.top().second;
//pop[30,0]
//pop [30, 2]
//pop [35, 4]
//pop [36, 3]
//pop [38, 1]
//stack is empty 
st.pop();
}

//[40, 5], [28, 6]
st.push({temperatures[i], i});
    }
    //[1, 4, 1, 2, 1, 0, 0]
    return ans;
    }
};
