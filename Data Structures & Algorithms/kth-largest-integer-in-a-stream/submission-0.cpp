class KthLargest {
private:
    //max-heap queue
    priority_queue<int> pq;
    int k_val;

public:
    KthLargest(int k, vector<int>& nums) {
        // There will always be at least k integers in the stream when you search for the kth integer so don't need to check for valid K
        k_val = k;

        for (int num : nums)
        {
            pq.push(num);
        }
    }
    
    int add(int val) {
        pq.push(val);

        auto temp = pq;
        for (int i = 0; i < k_val - 1; i++)
        {
            temp.pop();
        }

        return temp.top();
    }
};
