class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       if(hand.size()%groupSize!=0) return false;
        // hand = [1,2,4,2,3,5,3,4], groupSize = 4
         //sort hands 
        //hand = [1,2,2,3,3,4,4,5] 
        //map count cards
        //consecutive cards groupsize 
        //possibel true not false
        map<int, int>count;
        //count -> 1 : 1, 2:2, 3:2, 4:2, 5:1
        for(auto card : hand) count[card]++;
        //[1,1], [2,2], [3,2], [4,2], [5,1]
        for(auto it=count.begin(); it!=count.end(); it++)
        {
int card = it->first, freq=it->second;
            if(freq>0)
            {
                //i=0...4
                for(int i=1; i<groupSize; i++)
                {
                   
                if(count[card+i]<freq) return false;
                count[card+i]-=freq;
            }
            }
        
        //return true for iteration 1
        }
        
        return true;
    }
};
