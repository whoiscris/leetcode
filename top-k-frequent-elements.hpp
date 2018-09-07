class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for (auto& n : nums) {
            m[n]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>> q;
        
        for (auto& k : m)
            q.push({k.second, k.first});
        
        vector<int> r;
        for(int i=0; i<k; ++i) {
            auto e = q.top(); q.pop();
            r.push_back(e.second);
        }
        return r;
    }
};
