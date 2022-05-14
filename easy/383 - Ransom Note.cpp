/*
  383. Ransom Note - Easy

  Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

  Each letter in magazine can only be used once in ransomNote.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool output = true;
        
        for (int i = 0; i < ransomNote.length(); i++) {
            std::size_t letterFound = magazine.find(ransomNote[i]);
            
            if (letterFound != std::string::npos) {
                magazine.erase(letterFound, 1);
            } else {
                output = false;
                break;
            }
        }
        
        return output;
    }
};