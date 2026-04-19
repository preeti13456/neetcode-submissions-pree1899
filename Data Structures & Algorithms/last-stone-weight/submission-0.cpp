class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>>maxHeap;
        //2,3,6,2,4 -> 6,4,3,2,2
        for(auto stone: stones)
        {
            maxHeap.push(stone); // 6, 4, 2, 2, 3
        }
        while(maxHeap.size()>1)
        {
            //stone with less weight
            int y = maxHeap.top(); maxHeap.pop();
            int x =  maxHeap.top(); maxHeap.pop();
            maxHeap.push(abs(y-x));
        }
return maxHeap.top();
    }
};
