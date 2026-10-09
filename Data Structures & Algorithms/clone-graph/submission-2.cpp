/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> nodeMap; //map old node to new node

        dfs_copy(node, nodeMap);

        return nodeMap[node];
    }

    void dfs_copy(Node* node, unordered_map<Node*, Node*> &nodeMap) {
        //base case: copy the node, or if it already exists return it
        if (nodeMap.count(node)) return;

        //process current node
        Node* copy = new Node(node->val);
        nodeMap[node]= copy;

        //recurse!
        for (Node* neighbor : node->neighbors) {
            dfs_copy(neighbor, nodeMap);
            copy->neighbors.push_back(nodeMap[neighbor]);
        }

        return;
    }
};
