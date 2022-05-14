/*
  869. Reordered Power of 2 - Medium

  You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

  Return true if and only if we can do this so that the resulting number is a power of two.
*/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> powersOfTwo;
        string nString = std::to_string(n);
        bool output = false;
        
        int power = 1;
        
        powersOfTwo.push_back(std::to_string(power));
        
        while (std::to_string(power).length() <= nString.length()) {
            power *= 2;
            
            powersOfTwo.push_back(std::to_string(power));
        }
        
        int powerLength;
        string powerString;
        
        for (int i = 0; i < powersOfTwo.size(); i++) {
            powerString = powersOfTwo[i];
            
            if (powerString == nString) {
                return true;
            }
            
            if (powerString.length() == nString.length()) {
                cout << "Checking " << powerString << endl;
                bool canBeRearranged = true;
                
                for (int j = 0; j < nString.length(); j++) {
                    cout << "Looking for " << nString.at(j) << " in " << powerString << endl;
                    std::size_t found = powerString.find(nString.at(j));
                    
                    if (found != std::string::npos) {
                        powerString.erase(found, 1);
                    } else {
                        canBeRearranged = false;
                        break;
                    }
                }
                
                if (canBeRearranged) {
                    return true;
                }
            }
        }
        
        return false;
    }
};