class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //kahns topological algo
        // if pre-reqs have no cycles then we can complete courses

        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;

        for (auto req: prerequisites) {
            // edge going from b to a ([1]->[0])
            inDegree[req[0]]++;
            adjList[req[1]].push_back(req[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (int course : adjList[cur]) {
                inDegree[course]--;
                if (inDegree[course] == 0) {
                    q.push(course);
                }
            }
        }

        if (ans.size() == numCourses) return ans;
        return {};
    }
};
