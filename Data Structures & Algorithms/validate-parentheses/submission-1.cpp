class Solution {
public:
    bool isValid(string s) {
        stack<char> open;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                open.push(c);
            }
            else if (c == ')') {
                if (!open.size() || open.top() != '(') {
                    return false;
                }
                else {
                    open.pop();
                }
            }
            else if (c == ']') {
                if (!open.size() || open.top() != '[') {
                    return false;
                }
                else {
                    open.pop();
                }
            }
            else if (c == '}') {
                if (!open.size() || open.top() != '{') {
                    return false;
                }
                else {
                    open.pop();
                }
            }
        }
        return (!open.size());
    }
};
