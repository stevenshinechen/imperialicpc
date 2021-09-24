#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define EPS 1e-9
#define MOD 1000000007

bool isPossible(){
    int C,n;
    cin >> C >> n;

    int onTrain = 0;

    for(int i=0;i<n;i++){
        int left, entered,stayed;
        cin >> left >> entered >> stayed;

        onTrain -= left;
        if(onTrain < 0) return false;

        onTrain += entered;
        if(onTrain > C || onTrain < C && stayed){
            return false;
        }
    }

    if(onTrain) return false;

    return true;
}

int main() {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);

    if(isPossible()){
        cout << "possible" << endl;
    }
    else{
        cout << "impossible" << endl;
    }

    return 0;
}