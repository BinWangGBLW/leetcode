#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
 public:
    static bool comp(const Interval &a, const Interval &b) {
        return (a.start < b.start);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
    void print_interval(vector<Interval> &intervals) {
    	for (int i = 0; i < (int) intervals.size(); ++i) {
    		cout << "[" << intervals[i].start << "," << intervals[i].end << "]" << '\t';
		}
		cout << endl;
	}
};

int main() {
	vector <Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
	Solution s;
	vector <Interval> res = s.merge(intervals);
	s.print_interval(res);
	return 0;
}
 


