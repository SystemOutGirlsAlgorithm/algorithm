class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto i: stones) 
            pq.push(i);
        
        int val1, val2;
        while(true) {
            if (!pq.empty()) {
                val1 = pq.top();
                pq.pop();
            } else {
                return 0;
            }
            
            if (!pq.empty()) {
                val2 = pq.top();
                pq.pop();
            } else {
                return val1;
            }
            
            if (val1 != val2)
                pq.push(max(val1, val2) - min(val1, val2));
        }
    }
};