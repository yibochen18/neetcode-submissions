class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //valid ordering, kahns topological sort
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;

        for (auto vec : prerequisites) {
            // [a, b] means directed edge from b to a [1] -> [0]
            inDegree[vec[0]]++;
            adjList[vec[1]].push_back(vec[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (int classes : adjList[cur]) {
                inDegree[classes]--;
                if (inDegree[classes] == 0) q.push(classes);
            }
        }

        if (ans.size() == numCourses) return ans;
        return {};
    }
};
