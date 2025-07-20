
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

// Problem Statement: Given a list of folder paths, delete all duplicate folder subtrees and return the remaining paths.
// Approach: Construct a tree structure from paths, encode subtrees into signatures, mark duplicates, and collect surviving paths.

// Step-by-step Procedure:
// 1. Build a prefix tree (trie) from the list of folder paths where each node represents a folder.
// 2. Traverse the tree to generate a unique string encoding for each subtree and store them in a hash map.
// 3. If multiple nodes share the same subtree encoding, mark all such nodes (except one) as deleted.
// 4. Perform a DFS traversal to collect all folder paths that are not part of any deleted subtree.
// 5. Return the collected folder paths after cleanup, and delete the allocated memory to prevent leaks.

// Time Complexity: O(N * L * log L), where N is the number of paths and L is the average path length (log L for sorting in encoding).
// Space Complexity: O(N * L), due to the tree structure and hash map storing encodings.


class Node {
public:
    std::map<std::string, Node*> children;
    bool deleted = false;
    
    Node() = default;
    ~Node() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }
};

class Solution {
public:
    std::vector<std::vector<std::string>> deleteDuplicateFolder(
        std::vector<std::vector<std::string>>& paths) {
        
        Node* root = new Node();
        
        // Build the tree structure
        for (const auto& path : paths) {
            Node* curr = root;
            for (const std::string& name : path) {
                if (curr->children.find(name) == curr->children.end()) {
                    curr->children[name] = new Node();
                }
                curr = curr->children[name];
            }
        }
        
        // Encode each subtree and group nodes with identical structures
        std::unordered_map<std::string, std::vector<Node*>> map;
        encode(root, map);
        
        // Mark duplicate subtrees for deletion
        for (const auto& group : map) {
            if (group.second.size() > 1) {
                for (Node* n : group.second) {
                    n->deleted = true;
                }
            }
        }
        
        // Collect all non-deleted paths
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;
        collect(root, path, result);
        
        delete root;
        return result;
    }
    
private:
    std::string encode(Node* node, std::unordered_map<std::string, std::vector<Node*>>& map) {
        if (node->children.empty()) return "()";
        
        std::vector<std::string> parts;
        for (const auto& entry : node->children) {
            std::string sub = encode(entry.second, map);
            parts.push_back(entry.first + sub);
        }
        std::sort(parts.begin(), parts.end());
        
        std::string sign = "(";
        for (const std::string& part : parts) {
            sign += part;
        }
        sign += ")";
        
        map[sign].push_back(node);
        return sign;
    }
    
    void collect(Node* node, std::vector<std::string>& path, 
                 std::vector<std::vector<std::string>>& res) {
        for (const auto& entry : node->children) {
            if (entry.second->deleted) continue;
            path.push_back(entry.first);
            res.push_back(path);
            collect(entry.second, path, res);
            path.pop_back();
        }
    }
};