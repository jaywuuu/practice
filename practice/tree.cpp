#include <iostream>
#include <math.h>
#include <queue>
#include "tree.h"

/* trees and graph practice */

/* methods for tree */
void init_tree(int key, int value, int depth, TreeNode *node) {
	node->key = key;
	node->value = value;
	node->depth = depth;
	node->left = NULL;
	node->right = NULL;
}

void add_left(int key, int value, TreeNode *root) {
	if (root->left != NULL) return;
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	init_tree(key, value, root->depth + 1, root->left);
}

void add_right(int key, int value, TreeNode *root) {
	if (root->right != NULL) return;
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	init_tree(key, value, root->depth + 1, root->right);
}

/* find node given key */
TreeNode *find_node(int key, TreeNode *root) {
	/* traverse until we find the key */
	if (root->key == key || root == NULL) return root;

	/* start left */
	root = find_node(key, root->left);
	if (root->key == key) return root;

	/* look right */
	root = find_node(key, root->right);
	if (root->key == key) return root;

	return NULL;
}

/* free tree from root node */
void free_tree(TreeNode *root) {
	if (root == NULL) return;
	free_tree(root->left);
	free_tree(root->right);
	root->left = NULL;
	root->right = NULL;

	free(root);
}

/* find min depth */
/* use bfs to find min depth */
int min_depth(TreeNode *root, int depth) {
	int min_left = depth;
	int min_right = depth;

	if (root->left == NULL) return depth;
	if (root->right == NULL) return depth;
	/* traverse left */
	min_left = min_depth(root->left, depth + 1);
	/* traverse right */
	min_right = min_depth(root->right, depth + 1);

	return (min_left < min_right ? min_left : min_right);
}

/* find max depth */
/* use dfs to find max depth */
int max_depth(TreeNode *root, int depth) {
	int max_left = depth;
	int max_right = depth;

	if (root == NULL) return (depth - 1);

	/* traverse left */
	max_left = max_depth(root->left, depth + 1);
	/* traverse right */
	max_right = max_depth(root->right, depth + 1);

	return (max_left > max_right ? max_left : max_right);
}

/* check if tree is balanced */
/* tree is balanced if max_depth - min_depth is <= 1 */
bool is_tree_balanced(TreeNode *root) {
	return (max_depth(root, 0) - min_depth(root, 0) <= 1);
}

/* print spaces */
inline void print_space(int n) {
	for (int i = 0; i < n; i++) std::cout << " ";
}

/* go through each layer and add to queue to print */
void print_tree(TreeNode *root) {
	if (root == NULL) return;
	int maxWidth = 2*pow(2, max_depth(root, 0));
	int depth = root->depth;
	int oldDepth = root->depth;
	std::queue<TreeNode*> node_queue;

	node_queue.push(root);

	/* print depth by depth */
	while (!node_queue.empty()) {
		/* pop from top of queue based on depth and print */
		TreeNode *node = node_queue.front();
		depth = node->depth;
		/* change in depth */
		if (depth != oldDepth) {
			std::cout << std::endl;
			oldDepth = depth;
		}
		print_space(maxWidth / pow(2, depth + 1));
		std::cout << node->key;
		node_queue.pop();

		/* add leaves to queue */
		if (node->left != NULL) node_queue.push(node->left);
		if (node->right != NULL) node_queue.push(node->right);
	}
}
