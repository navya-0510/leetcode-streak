class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (string s : strs) { //process word one by one
            string key = s;
            sort(key.begin(), key.end()); //sorting to create key
            mp[key].push_back(s); //storing in hashmap 
        }
        
        vector<vector<string>> result;
        
        for (auto& it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};