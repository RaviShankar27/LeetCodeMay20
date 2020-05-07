class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        unordered_map<int,int> hashMap;
        for (auto elem : nums) {
            hashMap[elem]++;
            if (hashMap[elem] > nums.size()/2) return elem;
        }

        return -1;
    }
};