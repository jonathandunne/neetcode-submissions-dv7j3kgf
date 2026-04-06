class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        encoded_string += to_string(strs.size());
        encoded_string.push_back('#');
        for (string str : strs) {
            encoded_string += to_string(str.length());
            encoded_string.push_back('#');
        }
        for (string str : strs) {
            encoded_string += str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> output;
        vector<int> lengths;
        int n;
        int idx = 0;
        string temp = "";

        while (s[idx] != '#') {
            temp.push_back(s[idx]);
            idx++;
        }

        n = stoi(temp);
        temp = "";
        idx++;

        for (int i = 0; i < n; i++) {
            while (s[idx] != '#') {
                temp.push_back(s[idx]);
                idx++;
            }

            lengths.push_back(stoi(temp));
            temp = "";
            idx++;
        }

        for (int i = 0; i < lengths.size(); i++) {
            output.push_back("");
            for (int j = 0; j < lengths[i]; j++) {
                output[i].push_back(s[idx]);
                idx++;
            }
        }

        return output;
    }
};
