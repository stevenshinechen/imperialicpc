#if __has_include(<bits/stdc++.h>)
# include <bits/stdc++.h>
#elif __has_include("/usr/local/include/bits/stdc++.h")
# include "/usr/local/include/bits/stdc++.h"
#endif

using namespace std;
typedef long long ll;

#define EPS 1e-9
#define MOD 998244353

map<string,int> numUsed;

bool comp(string &a, string &b){
    if(numUsed[a] != numUsed[b]){
        return numUsed[a] > numUsed[b];
    }
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    map<string,set<string>> wordsUsed;


    for(int i=0;i<m;i++){
        string name;
        cin >> name;
        string line;
        getline(cin,line);

        string word;
        stringstream ss(line);
        while(ss >> word){
            wordsUsed[name].insert(word);
            numUsed[word]++;
        }
    }

    vector<string> intersect1;

    for(string word:wordsUsed.begin()->second){
        intersect1.push_back(word);
    }

    for(auto it = next(wordsUsed.begin(),1); it != wordsUsed.end(); it++){
        vector<string> intersect2((int)intersect1.size());
        auto intersectIt = set_intersection(it->second.begin(), it->second.end(),intersect1.begin(),intersect1.end(),intersect2.begin());

        intersect2.resize(intersectIt - intersect2.begin());

        intersect1 = intersect2;

    }

    sort(intersect1.begin(),intersect1.end(),comp);

    if(intersect1.empty()){
        cout << "ALL CLEAR" << endl;
    }
    else{
        for(string word:intersect1){
            cout << word << endl;
        }
    }

    return 0;
}