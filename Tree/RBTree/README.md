* #####Red Black Tree
	* [Red Black Tree Insertion](https://www.youtube.com/watch?v=UaLIHuR1t8Q)
	* [Red Black Tree Deletion](https://www.youtube.com/watch?v=CTvfzU_uNKE)
	* [Implementation in C](https://github.com/zpoint/Algorithms/tree/master/Tree/RBTree/rbt.c)
	* Hint

	![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/rbtinsert.png)
    ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/rbtdelete.png)

	* Result in C



            middle order traversal(first line is root):
			value: 15	 color: BLACK	parent: NIL	left: -10	right: 40
			value: -10	 color: BLACK	parent: 15	left: NIL	right: NIL
			value: 40	 color: RED	parent: 15	left: 17	right: 50
			value: 17	 color: BLACK	parent: 40	left: NIL	right: 20
			value: 20	 color: RED	parent: 17	left: NIL	right: NIL
			value: 50	 color: RED	parent: 40	left: NIL	right: NIL



