#include <iostream>
#include "tree.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

void test_tree() {
	TreeNode *tree = (TreeNode*)malloc(sizeof(TreeNode));
	int key = 0;

	init_tree(key++, 0, 0, tree);
	add_left(key++, 0, tree);
	add_right(key++, 0, tree);
	add_left(key++, 0, tree->left);
	add_right(key++, 0, tree->left);
	add_left(key++, 0, tree->right);
	add_right(key++, 0, tree->right);
	add_left(key++, 0, tree->left->left);

	print_tree(tree);
	std::cout << std::endl;
	std::cout << "max depth: " << max_depth(tree, 0) << std::endl;
	std::cout << "min depth: " << min_depth(tree, 0) << std::endl;
	std::cout << "Is tree balanced? " << (is_tree_balanced(tree) == 1 ? "yes" : "no") << std::endl;

	free_tree(tree);
}

void test_graph() {
	Graph graph;
	init_graph(&graph, DIRECTED);
	add_verts(&graph, 6);
	add_edge(&graph, 0, 1);
	add_edge(&graph, 0, 2);
	add_edge(&graph, 1, 3);
	add_edge(&graph, 1, 2);
	add_edge(&graph, 3, 4);
	add_edge(&graph, 4, 5);

	std::cout << "Number of vertices: " << graph.nvertices << std::endl;
	std::cout << "Number of edges: " << graph.nedges << std::endl;
	std::cout << "Route from 0 to 5? " << (is_route(&graph, 2, 5) == true ? "yes" : "no") << std::endl;
}

void test_stack() {
	Stack stack;
	init_stack(&stack);
	for (int i = 0; i < 10; i++) {
		push(&stack, i);
	}

	std::cout << "min: " << stack_min(&stack) << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << pop(&stack) << " ";
	}

	free_stack(&stack);
}

void test_queue() {
	Queue q;
	init_queue(&q);
	for (int i = 0; i < 10; i++) {
		enqueue(&q, i);
	}

	std::cout << "size: " << q.size << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << dequeue(&q) << " ";
	}
	std::cout << std::endl;
	std::cout << "size: " << q.size << std::endl;
	free_queue(&q);
}

int main(void) {
	test_queue();

	return 0;
}

