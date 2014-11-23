/* practice with trees */

#ifndef TREE_H_
#define TREE_H_

/* some data structure */
typedef struct tagTreeNode {
	int key;
	int value;
	int depth;
	tagTreeNode *left;
	tagTreeNode *right;
} TreeNode;

void init_tree(int key, int value, int depth, TreeNode *node);
void add_left(int key, int value, TreeNode *root);
void add_right(int key, int value, TreeNode *root);

/* find node given key */
TreeNode *find_node(int key, TreeNode *root);

/* free tree from root node */
void free_tree(TreeNode *root);
/* find min depth */
/* use bfs to find min depth */
int min_depth(TreeNode *root, int depth);

/* find max depth */
/* use dfs to find max depth */
int max_depth(TreeNode *root, int depth);

/* check if tree is balanced */
/* tree is balanced if max_depth - min_depth is <= 1 */
bool is_tree_balanced(TreeNode *root);

void print_tree(TreeNode *root);

#endif