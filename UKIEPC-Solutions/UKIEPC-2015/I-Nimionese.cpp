#include <bits/stdc++.h>
using namespace std;

vector<char> hard = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};

string process_syl(string s, char c) {
    vector<char> result;
    if (c == '\0') {
        bool is_upper = (s[0] >= 'A') && (s[0] <= 'Z');
        int i;
        for (i = 0; i < hard.size(); i++) {
            if (hard[i + 1] - (is_upper ? 32 : 0) > s[0]) break;
        }

        if (i + 1 >= hard.size())
            result.push_back(hard[i - 1] - (is_upper ? 32 : 0));
        else {
            int dist_above = hard[i + 1] - (is_upper ? 32 : 0) - s[0];
            int dist_below = s[0] - hard[i] + (is_upper ? 32 : 0);

            if (dist_above < dist_below)
                result.push_back(hard[i + 1] - (is_upper ? 32 : 0));
            else
                result.push_back(hard[i] - (is_upper ? 32 : 0));
        }

        s.erase(s.begin());
    }

    for (char x : s) {
        vector<char>::iterator iter = find(hard.begin(), hard.end(), x);
        if (iter != hard.end() && c != '\0') {
            result.push_back((char)tolower(c));
        } else {
            result.push_back(x);
        }
    }

    string final_result = "";
    for (char x : result) final_result += x;
    return final_result;
}

string process_word(string s) {
    string result = "";
    string current_syl = "";
    char start_consonant = '\0';
    for (char c : s) {
        if (c == '-') {
            result += process_syl(current_syl, start_consonant);
            if (start_consonant == '\0') start_consonant = result[0];
            current_syl = "";
        } else {
            current_syl += c;
        }
    }

    result += process_syl(current_syl, start_consonant);
    vector<char> ending = {'a', 'o', 'u'};
    if (find(hard.begin(), hard.end(), (char)tolower(result.back())) !=
        hard.end()) {
        bool is_upper = (result.back() >= 'A') && (result.back() <= 'Z');
        int i;
        for (i = 0; i < ending.size(); i++) {
            if (ending[i + 1] - (is_upper ? 32 : 0) > result.back()) break;
        }

        if (i + 1 >= ending.size()) {
            result.push_back(ending[i]);
        } else {
            int dist_above =
                ending[i + 1] - (is_upper ? 32 : 0) - result.back();
            int dist_below = result.back() - ending[i] + (is_upper ? 32 : 0);

            if (dist_above < dist_below)
                result.push_back(ending[i + 1]);
            else
                result.push_back(ending[i]);
        }

        result.push_back('h');
    }
    return result;
}

int main() {
    string input;
    getline(cin, input);

    string ans = "";
    string current_word = "";
    for (char c : input) {
        if (c == ' ') {
            ans += process_word(current_word) + " ";
            current_word = "";
        } else {
            current_word += c;
        }
    }

    ans += process_word(current_word);
    cout << ans << "\n";
    return 0;
}
