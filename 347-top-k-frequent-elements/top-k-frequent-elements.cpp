class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Min-heap based on frequency
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for (auto &entry : freq) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract results
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};