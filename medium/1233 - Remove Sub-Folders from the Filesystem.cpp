/*
  1233. Remove Sub-Folders from the Filesystem - Medium

  Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

  If a folder[i] is located within another folder[j], it is called a sub-folder of it.

  The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

    For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        string current;
        
        sort(folder.begin(), folder.end());
        
        current = folder[0];
        result.push_back(current);
        
        for (int i = 1; i < folder.size(); i++) {
            if (folder[i].substr(0, current.length() + 1) != current + "/") {
                current = folder[i];
                result.push_back(current);
            }
        }
        
        return result;
    }
};