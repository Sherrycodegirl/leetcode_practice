README.txt
Definition of Binary Search Tree (BST):
Binary search tree is a node based binary tree data structure which has the following properties:
The left subtree of a node contains only nodes with keys lesser than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
The left and right subtree each must also be a binary search tree. There must be no duplicate nodes.

The implementation of the BST is built on C++. Here I define the BST as a class data type.
The data and memeber functions include the key, Insert(), Inorder traverse function: Inorder(), Search a node 
and print the node subtrees fuction: searchnode(). Delete a node function: deletenode(). Find a minimum node
function: minimum_val().

#delete a node.
The situation of deleteing a node in a BST has three possibilities:
1. Node to be deleted is a leaf. What we need to do is replace the leaf with a NULL.
2. Node to be deleted has one child.  What we need to do is replace the node with it's child.
3. Node to be deleted has two children. What we need to do is to find the minimum node on the right subtree 
of this node. Then we change the key of this node to the found minimum key and delete the minimum node on the right
subtree.

Definition of Binary Heap:
A complete binary tree in which every level such that a parent node is greater or smaller than the values in
its two children nodes.
Left node index is 2*i + 1, right node index is 2*i+2. i is from 0.
Heapify is the process that make the parent node is smaller or greater than children nodes (Min Heap or Max Heap).
The heapsort is to make the root is the mimimum or maximum after heapifying each time. replace the root with the last entry
in the array and heapifying again with the shrink array. 

Here I present two forms of heapsort, the first one min_heap.cpp is to construct a heap and realize other functions (like change a key in a node, delete a key at index i, extract root value) in a heap.
The second heapsort is to do sorting on a given array.
A binary heap is typically represented as an array.




 