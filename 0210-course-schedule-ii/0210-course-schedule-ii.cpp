class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // graph[prerequisite] = courses that depend on it
        vector<vector<int>> graph(numCourses);
        
        // indegree[i] = number of prerequisites for course i
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        // BFS
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            order.push_back(course);

            // Reduce indegree of dependent courses
            for (int next : graph[course]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we couldn't take all courses, there is a cycle
        if (order.size() != numCourses) {
            return {};
        }

        return order;
    }
};