class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n), right(n);
        stack<int>st;

        for(int i=n-1; i>=0 ; i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
st.pop();
            }
if(st.empty())
{
    right[i]=n;
}
else
{
    right[i]=st.top();
}
            
            st.push(i);
        }
        while(!st.empty()) st.pop();


        for(int i=0; i<n ; i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
st.pop();
            }
if(st.empty())
{
    left[i]=-1;
}
else
{
    left[i]=st.top();
}
            
            st.push(i);
        }
        int area = 0;
        for(int i=0; i<n; i++)
        {
            int width = right[i]-left[i]-1;
            int curr = width*arr[i];
            area = max(area, curr);
        }
        return area;

    }
};
