* Binary Search Tree
	* [Video week 5](https://www.coursera.org/learn/data-structures-optimizing-performance/home/week/5)
	* [Implementation in C](https://github.com/zpoint/Algorithms/tree/master/Tree/BST/bst.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/tree/master/Tree/BST/bst.py)
	* Hint

	![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/preorder.png)
    ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/postorder.png)
    ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/inorder.png)
    ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/levelorder.png)

	* Result in C

                    5
		     	  /  \
		         3   10
	            /     \
	           2     15
	          /
             1
			preorder_traversal:5	3	2	1	10	15	
			postorder_traversal:1	2	3	15	10	5	
			inorder_traversal:1	2	3	5	10	15	
			levelorder_traversal:5	3	10	2	15	1	
			Height: 3, node: 2 depth of 15: 2 isbinarytree(tree): 1, 1





	* Result in Python3

			python3 bst.py
			preorder_traversal:	5	3	2	1	10	15	
			postorder_traversal:	1	2	3	15	10	5	
			inorder_traversal:	1	2	3	5	10	15	
			levelorder_traversal:	5	3	10	2	15	1	
			BST.height(): 3	 BST.node_count(): 2	 BST.depth(15): 2 BST.isbinarytree(): 1

