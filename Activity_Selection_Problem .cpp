#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int s, f;         ///s = start, f = finish
};

bool compare(Activity a, Activity b) {
    return a.f < b.f;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish times of each activity:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i].s >> arr[i].f;

    sort(arr, arr + n, compare);

    cout << "Selected activities:\n";
    int lastFinish = arr[0].f;
    cout << arr[0].s << " " << arr[0].f << endl;

    for(int i = 1; i < n; i++) {
        if(arr[i].s >= lastFinish) {
            cout << arr[i].s << " " << arr[i].f << endl;
            lastFinish = arr[i].f;
        }
    }

    return 0;
}
