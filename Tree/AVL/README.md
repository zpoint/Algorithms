* #####Binary Search Tree
	* [AVL & Insertion (Video)](https://www.youtube.com/watch?v=rbg7Qf8GkQ4)
	* [Implementation in C](https://github.com/zpoint/Algorithms/tree/master/Tree/AVL/avl.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/tree/master/Tree/AVL/avl.py)

	* Result in C

                    8                           8
		     	  /  \                        /  \
		         5   10       delete 10:     5   13
	                / \                         /
	               9  13                       9
			node value: 5, left_height: -1, right_height: -1, node_height: 0
			node value: 8, left_height: 0, right_height: 1, node_height: 2
			node value: 9, left_height: -1, right_height: -1, node_height: 0
			node value: 13, left_height: 0, right_height: -1, node_height: 1






	* Result in Python3

			preorder_traversal:
			node_value: 5, left_height: -1, right_height: -1, height: 0
			node_value: 8, left_height: 0, right_height: 1, height: 2
			node_value: 9, left_height: -1, right_height: -1, height: 0
			node_value: 13, left_height: 0, right_height: -1, height: 1
