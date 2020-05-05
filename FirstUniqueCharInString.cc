class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        unordered_map<char,int> hashMap; 
        for (auto elem : s) {
            hashMap[elem]++;
        }
        
        for(int index = 0; index < s.length(); ++index) {
            auto it = hashMap.find(s[index]);
            if (it != hashMap.end()) {
                if (it->second == 1) {
                    return index;
                }
            }
        }
        return -1;
    }
};