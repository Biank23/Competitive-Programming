#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
struct Customer {
    int arrival, departure, idx, room;
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<Customer> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].arrival >> v[i].departure;
        v[i].idx = i;
    }
    sort(all(v), [](const Customer &lhs, const Customer &rhs) {
        return lhs.arrival < rhs.arrival;
    });
    
    auto cmp = [](const Customer &lhs, const Customer &rhs) {
        return lhs.departure > rhs.departure;
    };
    
    priority_queue<Customer, vector<Customer>, decltype(cmp)> pq;
    
    int cantRooms = 0;
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top().departure < v[i].arrival) {
            v[i].room = pq.top().room;
            pq.pop();
        } else {
            cantRooms++;
            v[i].room = cantRooms;
        }
        pq.push(v[i]);
    }
    
    sort(all(v), [](const Customer &lhs, const Customer &rhs) {
        return lhs.idx < rhs.idx;
    });
    cout << cantRooms << '\n';
    for (int i = 0; i < n; i++) {
        cout << v[i].room << ' ';
    }
    
    return 0;
}