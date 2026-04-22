class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        bottom_half.push(num);
        // Move the largest from bottom_half to upper_half if needed
        if (!upper_half.empty() && bottom_half.top() > upper_half.top()) {
            upper_half.push(bottom_half.top());
            bottom_half.pop();
        }
        // Balance sizes
        if (bottom_half.size() > upper_half.size() + 1) {
            upper_half.push(bottom_half.top());
            bottom_half.pop();
        }
        if (upper_half.size() > bottom_half.size()) {
            bottom_half.push(upper_half.top());
            upper_half.pop();
        }
    }

    double findMedian() {
        if (bottom_half.size() == upper_half.size())
            return (bottom_half.top() + upper_half.top()) / 2.0;
        else
            return bottom_half.top();
    }

    priority_queue<int> bottom_half;
    priority_queue<int, vector<int>, greater<int>> upper_half;
};