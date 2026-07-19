class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                stk.push(stoi(token));
            } else {
                // take last two numbers from the stack(stk) and operate
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                int result = 0;
                if (token == "+")
                    {result = left + right;}
                else if (token == "-")
                    {result = left - right;}
                else if (token == "*")
                    {result = left * right;}
                else
                    {result = left / right;}

                stk.push(result);
            }
        }

        return stk.top();
    }
};
