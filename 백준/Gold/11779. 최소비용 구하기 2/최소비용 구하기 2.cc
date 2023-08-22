#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

#define INF 1000000000

struct edge {
    int start;
    int end;
    int value;
};

int prevVertex[1001] = {0};
int length[1001] = {0};

void dijkstra(vector<vector<edge>> cost, int start, int end, int n);

struct compare {
	bool operator()(const edge& e1, const edge& e2) {
        if(e1.value == e2.value)
            return e1.end > e2.end;
        else
		    return e1.value > e2.value;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<edge>> cost(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cost[u].push_back(edge{u, v, c});
    }

    int start, end;
    cin >> start >> end;
    for(int i = 1; i <= n; i++)
        length[i] = INF;
    length[start] = 0;

    dijkstra(cost, start, end, n);

    cout << length[end] << '\n';

    int count = 1;
    int prev = end;
    stack<int> s;
    s.push(end);
    while(prev != start) {
        prev = prevVertex[prev];
        count++;
        s.push(prev);
    }
    cout << count << '\n';
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}

void dijkstra(vector<vector<edge>> cost, int start, int end, int n) {
    int nextVertex = start;
    int isSelected[1001] = {false};
    isSelected[nextVertex] = true;

    priority_queue<edge, vector<edge>, compare> pq;
    while(nextVertex != end) {
        for(int i = 0; i < cost[nextVertex].size(); i++) {
            edge e = cost[nextVertex][i];
            pq.push(edge{e.start, e.end, length[e.start] + e.value});
            if(length[e.end] > length[e.start] + e.value) {
                length[e.end] = length[e.start] + e.value;
                prevVertex[e.end] = e.start;
            }
        }

        edge e = pq.top();        
        pq.pop();
        while(isSelected[e.end]) {
            e = pq.top();
            pq.pop();
        }

        nextVertex = e.end;
        isSelected[e.end] = true;
    }
}