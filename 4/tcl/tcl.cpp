#include <bits/stdc++.h>

using namespace std;

long long maximumRectangleArea(vector<int>& heights) {
    stack<int> stacks;
    long long maximumArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        while (!stacks.empty() && (i == n || heights[stacks.top()] > heights[i])) {
            int height = heights[stacks.top()];
            stacks.pop();

            int width = stacks.empty() ? i : (i - stacks.top() - 1);
            long long area = static_cast<long long>(height) * width;
            maximumArea = max(maximumArea, area);
        }
        stacks.push(i);
    }
    return maximumArea;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        long long result = maximumRectangleArea(heights);
        cout << result << endl;
    }
}
