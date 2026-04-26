class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;//track total time req to complete task
        queue<pair<int, int>>cooldown;  // tasks waiting for cooldown
        //{remaining count, avalaible time}

        //count freq of each task
        unordered_map<char, int>count;

//tasks = [A, A, A, B, B, B], n = 2
//count A :3
//count B : 3
        for(char task : tasks ) count[task]++; //X=2, Y=2

        //Maxheap to pick most frequecnt task 
        priority_queue<int>maxHeap;
//[3,3]
        for(auto&p : count) maxHeap.push(p.second);//push freq into heap
        //loop unti all task done
        while(!maxHeap.empty () || !cooldown.empty())
        {
            //move to next time unit
time++;
//Time 1 : Pick A 
//if task is avlaible
//Time 2 : Pick B
if(!maxHeap.empty())
{
    int freq = maxHeap.top();
    //pop A freq 3 now [] left
    maxHeap.pop(); //take the most freq task
//means if the chaarcer we pop still have count left
//A: 2 left 
//heap = []
        if(freq-1>0)

        //cooldown [(2, 3)]
        //cooldown [(2,3), (2, 4)]
        cooldown.push({freq-1, time+n});// add cooldwon with unlock time
}
if(!cooldown.empty() && cooldown.front().second == time)
{
    
    maxHeap.push(cooldown.front().first);
    cooldown.pop();
}
        }
        return time;

    }
};
