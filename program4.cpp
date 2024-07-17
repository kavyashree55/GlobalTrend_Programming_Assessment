#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Serialize a binary tree to a string.
    std::string serialize(TreeNode* root) {
        if (root == NULL) return "X,";

        std::string left = serialize(root->left);
        std::string right = serialize(root->right);

        return std::to_string(root->val) + "," + left + right;
    }

    // Deserialize a string to a binary tree.
    TreeNode* deserialize(std::string data) {
        std::istringstream iss(data);
        return deserializeHelper(iss);
    }

private:
    TreeNode* deserializeHelper(std::istringstream& iss) {
        std::string val;
        getline(iss, val, ',');
        if (val == "X") return NULL;

        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);

        return node;
    }
};

void printTree(TreeNode* node) {
    if (node == NULL) return;

    std::cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}

int main() {
    Codec codec;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the binary tree
    std::string serialized = codec.serialize(root);
    std::cout << "Serialized binary tree: " << serialized << std::endl;

    // Deserialize the binary tree
    TreeNode* deserializedRoot = codec.deserialize(serialized);

    // Print the deserialized binary tree
    std::cout << "Deserialized binary tree: ";
    printTree(deserializedRoot);
    std::cout << std::endl;

    return 0;
}
