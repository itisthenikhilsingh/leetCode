class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos;
    // While an occurrence is found, remove it.
    while ((pos = s.find(part)) != std::string::npos) {
        s.erase(pos, part.size());
    }
    return s;

        
        
    }
};