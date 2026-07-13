class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;


        int strLen = s.length();

        for(int i=0; i<strLen; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            } else {
                if(i == 0) {return false;}
                if(stk.empty()) {return false;}

                if(s[i] == ')'){
                    if(stk.top() == '(') {stk.pop();}
                    else {stk.push(s[i]);}
                }
                else if(s[i] == '}'){
                    if(stk.top() == '{') {stk.pop();}
                    else {stk.push(s[i]);}
                }
                else if(s[i] == ']'){
                    if(stk.top() == '[') {stk.pop();}
                    else {stk.push(s[i]);}
                }
            }
        }

        if(stk.empty()){
            return true;
        }

        return false;
    }
};
