class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hash;
        for (auto elem : J) {
            hash.insert(elem);
        }
        int res = 0;
        for (auto elem : S) {
            if (hash.find(elem) != hash.end()) {
                ++res;
            }
        }
        return res;
    }
};