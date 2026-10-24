#include <bits/stdc++.h>
using namespace std;

// Problem: Count Days Spent Together
// Link: https://leetcode.com/problems/count-days-spent-together/
// Difficulty: Easy
// Pattern: Math - Date to Day-of-Year + Interval Overlap

// ------------------------------------------------------------
// Approach: Convert Dates to Day Numbers, Intersect the Two Ranges
// ------------------------------------------------------------
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto dayOfYear = [&](const string& date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }

            return day;
        };

        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));

        return max(0, end - start + 1);
    }
};

int main() {
    Solution obj;
    cout << obj.countDaysTogether("08-15", "08-18", "08-16", "08-19") << " "
         << obj.countDaysTogether("10-01", "10-31", "11-01", "12-31") << "\n";
    return 0;
}