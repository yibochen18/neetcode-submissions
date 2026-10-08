class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build in-degree + adj matrix
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        queue<int> q;
        int taken = 0;

        for (auto &rec : prerequisites) {
            inDegree[rec[0]]++;

            //directed edge from b to a
            adjList[rec[1]].push_back(rec[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            //push everything with no indegrees onto queue
            if (inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            taken++;

            for (int nextClass : adjList[temp]) {
                inDegree[nextClass]--;
                if (inDegree[nextClass] == 0) q.push(nextClass);
            }
            
        }

        return taken == numCourses;
    }
};
