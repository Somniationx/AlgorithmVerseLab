#include <iostream>

// 定义二叉树节点结构
struct binary_tree_node {
    int _data;               // 节点存储的数据
    binary_tree_node* _left; // 左子树指针
    binary_tree_node* _right;// 右子树指针
};

// 使用别名简化节点类型名称
typedef binary_tree_node node;

// 前序遍历函数，以根-左-右的顺序遍历树
void pre_order(node* root) {
    if (root == nullptr) {
        std::cout << "NULL "; // 当前节点为空，输出"NULL"
        return;
    }

    std::cout << root->_data << " "; // 输出当前节点的数据
    pre_order(root->_left);          // 递归遍历左子树
    pre_order(root->_right);         // 递归遍历右子树
}

// 中序遍历函数，以左-根-右的顺序遍历树
void mid_order(node* root) {
    if (root == nullptr) {
        std::cout << "NULL "; // 当前节点为空，输出"NULL"
        return;
    }
    mid_order(root->_left);          // 递归遍历左子树
    std::cout << root->_data << " "; // 输出当前节点的数据
    mid_order(root->_right);         // 递归遍历右子树
}

// 后序遍历函数，以左-右-根的顺序遍历树
void pos_order(node* root) {
    if (root == nullptr) {
        std::cout << "NULL "; // 当前节点为空，输出"NULL"
        return;
    }
    pos_order(root->_left);         // 递归遍历左子树
    pos_order(root->_right);        // 递归遍历右子树
    std::cout << root->_data << " "; // 输出当前节点的数据
}

// 求取二叉树节点个数
int treeSize(node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSize = treeSize(root->_left);
    int rightSize = treeSize(root->_right);

    return 1 + leftSize + rightSize;
}

// 叶子节点个数
int treeLeafSize(node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->_left == nullptr && root->_right == nullptr) {
        // 当前节点是叶子节点
        return 1;
    }

    int leftLeafSize = treeLeafSize(root->_left);
    int rightLeafSize = treeLeafSize(root->_right);

    return leftLeafSize + rightLeafSize;
}

// 二叉树高度
int treeHeight(node* root) {
    if (root == nullptr) {
        return 0; // 空树的高度为0
    }

    int leftHeight = treeHeight(root->_left);
    int rightHeight = treeHeight(root->_right);

    // 返回左子树和右子树中更高的高度加上1（当前节点）
    return 1 + std::max(leftHeight, rightHeight);
}


// 清理二叉树内存的辅助函数
void deleteTree(node* root) {
    if (root == nullptr) {
        return;
    }

    // 递归地删除左子树和右子树
    deleteTree(root->_left);
    deleteTree(root->_right);

    // 删除当前节点
    delete root;
}

// 测试函数，用于创建并测试二叉树的遍历
void testBinaryTreeTraversal() {
    // 创建根节点并赋值为1
    auto root = new node;
    root->_data = 1;

    // 创建左子节点并赋值为2
    auto left = new node;
    left->_data = 2;
    left->_left = nullptr;
    left->_right = nullptr;

    // 创建右子节点并赋值为3
    auto right = new node;
    right->_data = 3;
    right->_left = nullptr;
    right->_right = nullptr;

    // 创建更多节点
    auto left_left = new node;
    left_left->_data = 4;
    left_left->_left = nullptr;
    left_left->_right = nullptr;

    auto left_right = new node;
    left_right->_data = 5;
    left_right->_left = nullptr;
    left_right->_right = nullptr;

    auto right_left = new node;
    right_left->_data = 6;
    right_left->_left = nullptr;
    right_left->_right = nullptr;

    auto right_right = new node;
    right_right->_data = 7;
    right_right->_left = nullptr;
    right_right->_right = nullptr;

    // 连接节点
    left->_left = left_left;
    left->_right = left_right;
    right->_left = right_left;
    right->_right = right_right;

    // 连接根节点和子节点
    root->_left = left;
    root->_right = right;

    // 打印遍历结果
    std::cout << "Pre-order traversal: ";
    pre_order(root);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    mid_order(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    pos_order(root);
    std::cout << std::endl;

    // 清理内存
    deleteTree(root);
}

int main() {
    testBinaryTreeTraversal(); // 调用测试函数
    return 0;
}
