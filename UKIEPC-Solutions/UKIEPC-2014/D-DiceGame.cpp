#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;

#define REPE(i, a, b) for (int i = int(a); i <= int(b); i++) 
#define FORI(i, a) for (int i = 0; i < a; i++)
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)
#define REMOVE(v, e) v.erase(std::find(v.begin(), v.end(), e))
#define IS_IN(container, element) (container.find(element) != container.end())
#define EXISTS(i, n) (find(n.begin(), n.end(), i) != n.end())
#define FIND(i, n) (find(n.begin(), n.end(), i))
#define all(x) (x).begin(), (x).end()
#define sz size
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define INF 1e9
#define PI 3.1415926535897932384626433832795

const int d4x[4] = { 1, 0, -1, 0 }, d4y[4] = { 0, 1, 0, -1 };
const int d8x[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }, d8y[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    // double gunExpecValue = ((a1 + b1) / 2) + ((a2 + b2) / 2);
    double gunExpecValue = ((a1 + b1)) + ((a2 + b2));
    cin >> a1 >> b1 >> a2 >> b2;
    double emExpecValue = ((a1 + b1)) + ((a2 + b2));

    if (gunExpecValue == emExpecValue){
        cout << "Tie" << endl;
    }
    else if (gunExpecValue > emExpecValue){
        cout << "Gunnar" << endl;
    }
    else{
        cout << "Emma" << endl;
    }
    return 0;
}