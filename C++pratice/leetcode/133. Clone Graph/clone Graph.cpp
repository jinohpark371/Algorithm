#include <unordered_map>
#include <vector>
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
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
private:
    Node* dfs(Node *node, unordered_map<Node*, Node*>& visited){
        if(node == nullptr) return nullptr;

        //이미 방문한 노드 복사본 반환
        if(visited.count(node)){
            return visited[node];
        }
        //미방문 노드 방문처리
        Node* clone = new Node(node->val);
        visited[node] = clone;

        for(Node* neighbor : node -> neighbors){
            
            Node* v=dfs(neighbor, visited);
            clone->neighbors.push_back(v);
        }

        return clone;
    }
};