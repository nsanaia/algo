#include <bits/stdc++.h>

class Solution {
private:

    struct Course {
        int depsN;
        unordered_set<int> children;
    };

    vector<Course> getCourses(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Course> res(numCourses);

        for (auto& p : prerequisites) {
            int preReq = p[1];
            int course = p[0];

            res[preReq].children.insert(course);
            res[course].depsN++;
        }

        return res;
    }

    queue<int> getCoursesWithZeroDep(vector<Course> & courses) {
        queue<int> res;

        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].depsN == 0) {
                res.push(i);
            }
        }

        return res;
    }

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        auto courses = getCourses(numCourses, prerequisites);
        auto coursesWithZeroPreReq =  getCoursesWithZeroDep(courses);
        vector<int> res;

        while (!coursesWithZeroPreReq.empty()) {
            int curr = coursesWithZeroPreReq.front();
            coursesWithZeroPreReq.pop();

            res.push_back(curr);

            for (auto child : courses[curr].children) {
                courses[child].depsN--;

                if (courses[child].depsN == 0) {
                    coursesWithZeroPreReq.push(child);
                }
            }

        }

        return res.size() == numCourses ? res : vector<int>();
    }
};

