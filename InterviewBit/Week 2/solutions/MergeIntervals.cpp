/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <bits/stdc++.h>

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    int idx = 0;

    while (idx < intervals.size()) {
        auto curr = intervals[idx];
        if (curr.end < newInterval.start) {
            res.push_back(curr);
            idx++;
        } else {
            break;
        }
    }

    res.push_back(newInterval);


     while (idx < intervals.size()) {
        auto curr = intervals[idx++];
        auto& last = res[res.size() - 1];

        if (curr.start > last.end) {
            res.push_back(curr);
        } else {
            last.end = max(last.end, curr.end);
            last.start = min(last.start, curr.start);
        }
    }

    return res;
}
