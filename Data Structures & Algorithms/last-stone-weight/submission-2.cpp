class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //heap
        priority_queue<int> heap(stones.begin(), stones.end());

        while (heap.size() > 1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();

            if (x > y) {
                heap.push(x - y);
            }
        }
        if (heap.empty()) return 0;
        return heap.top();
    }
};
