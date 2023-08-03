#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(const unordered_map<int, vector<char>>& m, const string& digits, int index, string&  current, vector<string>& result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    int digit = digits[index] - '0';
    for (char letter : m.at(digit)) {
        current.push_back(letter);
        backtrack(m, digits, index + 1, current, result);
        current.pop_back();
    }
    }
    vector<string> letterCombinations(string digits) {

        unordered_map<int,vector<char>> m;
        vector<string> strings;

        m[2]={'a','b','c'};
        m[3]={'d','e','f'};
        m[4]={'g','h','i'};
        m[5]={'j','k','l'};
        m[6]={'m','n','o'};
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};

        if(digits.length()!=0){
            string current;
            backtrack(m, digits, 0, current, strings);
        }
        
        return strings;
    }
};