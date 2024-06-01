#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjacencyList;
vector<bool> visited;
vector<bool> reachable;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    reachable[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int receiver : adjacencyList[node]) {
            if (!visited[receiver]) {
                q.push(receiver);
                visited[receiver] = true;
                reachable[receiver] = true;
            }
        }
    }
}

int main() {
    int v, e, s, d;
    cin >> v >> e >> s >> d;

    adjacencyList.resize(v + 1);
    visited.resize(v + 1, false);
    reachable.resize(v + 1, false);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
    }

    bfs(s);

    vector<int> undeliverablePackage;

    for (int i = 0; i < d; i++) {
        int p;
        cin >> p;

        if (!reachable[p]) {
            undeliverablePackage.push_back(p);
        }
    }

    if (undeliverablePackage.empty()) {
        cout << "All packages are delivered today!" << endl;
    }
    else {
        cout << "Packages to be delivered tomorrow: ";
        for (int package : undeliverablePackage) {
            cout << package << " ";
        }
        cout << endl;
    }
}
