//LeetCode

//128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (auto it : nums) {
            us.insert(it);
        }
        int currMax = 0;
        for (auto it : us) {
            if (us.find(it - 1) == us.end()) {
                int count = 0;
                while (us.find(it) != us.end()) {
                    count++;
                    it++;
                }
                currMax = max(currMax, count);
            }
        }
        return currMax;
    }
};

//290. Word Pattern
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        s+=' ';
        string temp="";
        for(auto ch:s){
            if(ch==' '){
                words.push_back(temp);
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        if(words.size() != pattern.size()){
            return false;
        }
        unordered_map<string, char> strToChar;
        unordered_map<char, string> charToStr;
        for(int i=0;i<words.size();i++){
            if((charToStr.find(pattern[i])!=charToStr.end())){
                if(charToStr[pattern[i]]!=words[i]){
                    return false;
                }
            }
            if((strToChar.find(words[i])!=strToChar.end())){
                if(strToChar[words[i]]!=pattern[i]){
                    return false;
                }
            }
            charToStr[pattern[i]]=words[i];
            strToChar[words[i]]=pattern[i];
        }
        return true;
    }
};