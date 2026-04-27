class Solution {
public:
bool canEat(const vector<int>&piles, int s, int h)
{
    long long hours = 0;
    for(int pile : piles)
    {
        hours+=(pile+s-1)/s;
    }
    return hours<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::ranges::max_element(piles);
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(canEat(piles, mid, h))
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
