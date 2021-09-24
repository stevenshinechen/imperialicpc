#include <bits/stdc++.h>
using namespace std;

deque<int> least_rotation(deque<int> s) {
    auto old_size = s.size();
    s.resize(2 * old_size);
    copy_n(s.begin(), old_size, s.begin() + old_size);

    vector<int> f(s.size(), -1);
    int k = 0;

    for (int j = 1; j < s.size(); j++) {
        int sj = s[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != s[k + i + 1]) {
            if (sj < s[k + i + 1]) k = j - i - 1;
            i = f[i];
        }

        if (sj != s[k + i + 1]) {
            if (sj < s[k]) k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    deque<int> result(old_size);
    for (int i = k; i < k + old_size; i++) result[i - k] = s[i];

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    deque<int> a_diffs(n);
    deque<int> b_diffs(n);
    for (int i = 1; i < n; i++) {
        a_diffs[i - 1] = a[i] - a[i - 1];
        if (a_diffs[i - 1] < 0) a_diffs[i - 1] += 360000;
        b_diffs[i - 1] = b[i] - b[i - 1];
        if (b_diffs[i - 1] < 0) b_diffs[i - 1] += 360000;
    }

    a_diffs[n - 1] = a[0] - a[n - 1];
    if (a_diffs[n - 1] < 0) a_diffs[n - 1] += 360000;
    b_diffs[n - 1] = b[0] - b[n - 1];
    if (b_diffs[n - 1] < 0) b_diffs[n - 1] += 360000;

    deque<int> rotated_a = least_rotation(a_diffs);
    deque<int> rotated_b = least_rotation(b_diffs);

    if (rotated_a == rotated_b)
        cout << "possible\n";
    else
        cout << "impossible\n";

    return 0;
}
