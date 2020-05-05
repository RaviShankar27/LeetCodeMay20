class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty() && magazine.empty()) return true;
        if (magazine.empty()) return false;
        
        unordered_map<char,int> ransomNoteHash;
        unordered_map<char,int> magazineHash;
        for (auto elem : ransomNote) {
            ransomNoteHash[elem]++;
        }
        
        for (auto elem : magazine) {
            magazineHash[elem]++;
        }
        
        for (auto elem : ransomNoteHash) {
            auto it = magazineHash.find(elem.first);
            if (it != magazineHash.end()) {
                if (it->second < elem.second){
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};