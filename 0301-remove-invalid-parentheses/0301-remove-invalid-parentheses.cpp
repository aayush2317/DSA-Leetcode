class Solution {
    bool isValid(string s) {
        int open = 0;

        for (char ch : s) {
            if (ch == '(') {
                open++;
            }
            else if (ch == ')') {
                if (open == 0) {
                    return false;
                }
                open--;
            }
        }
        return open == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }
                if (found) {
                    continue;
                }
                for (int i = 0; i < curr.size(); i++) {
                    if (curr[i] != '(' && curr[i] != ')') {
                        continue;
                    }
                    string next =
                        curr.substr(0, i) +
                        curr.substr(i + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if (found) {
                break;
            }
        }
        return ans;
    }
};