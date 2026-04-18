class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = INT_MAX;
        stack<int> nums;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1;
                int num2;
                int push;

                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                
                if (token == "+") {
                    push = num1 + num2;
                }
                else if (token == "-") {
                    push = num1 - num2;
                }
                else if (token == "*") {
                    push = num1 * num2;
                }
                else {
                    push = num1 / num2;
                }
                nums.push(push);
            }
            else {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};
