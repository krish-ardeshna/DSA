#include <bits/stdc++.h>
using namespace std;

// Problem: Largest Rectangle in Histogram
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Difficulty: Hard
// Pattern: Monotonic Stack

// ------------------------------------------------------------
// Approach 1: Single Pass with Post-Loop Cleanup
// ------------------------------------------------------------
class SolutionSinglePass {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(heights[element] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int nse = n;
            int element = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(heights[element] * (nse - pse - 1), maxArea);
        }

        return maxArea;
    }
};

// ------------------------------------------------------------
// Approach 2: Separate PSE/NSE Arrays
// ------------------------------------------------------------
class SolutionSeparatePSENSE {
public:
    vector<int> findPSE(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> findNSE(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse = findNSE(heights, n);
        vector<int> pse = findPSE(heights, n);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    SolutionSinglePass s1;
    cout << s1.largestRectangleArea(heights) << "\n";

    SolutionSeparatePSENSE s2;
    cout << s2.largestRectangleArea(heights) << "\n";

    return 0;
}