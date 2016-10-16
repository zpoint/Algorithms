* ####Insertion Sort
	* [Implementation in C](https://github.com/zpoint/Algorithms/tree/master/Sort/insertion%20sort/insertion.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/tree/master/Sort/insertion%20sort/insertion.py)
	* [Result](#result-in-c)


* #####Hint

	![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/is.gif)


* #####Result in C

		$./a.out
		size: 150, Iinitialized
		  2   2   8   4   7   2   9   9   5   2   8 
		  2   4   1   2   1   4   0   0   1   3 
		  9   8   7   6   6   4   0   1   2   8 
		  4   4   8   0   3   0   2   5   7   4 
		  3   9   1   6   4   4   1   4   4   4 
		  0   5   4   7   2   0   3   2   2   5 
		  2   8   1   3   8   7   3   0   2   3 
		  7   7   2   8   4   6   2   5   3   9 
		  1   3   4   5   0   8   8   6   1   2 
		  1   3   0   5   8   0   2   4   1   4 
		  7   8   1   9   8   7   8   2   4   1 
		  3   5   4   0   3   6   8   1   2   9 
		  3   6   5   5   1   3   5   5   7   6 
		  1   6   6   4   6   6   2   6   9   6 
		  7   2   4   3   2   7   9   1   8 

		size: 150, After Insertion sort
		  0   0   0   0   0   0   0   0   0   0   0 
		  0   1   1   1   1   1   1   1   1   1 
		  1   1   1   1   1   1   1   1   2   2 
		  2   2   2   2   2   2   2   2   2   2 
		  2   2   2   2   2   2   2   2   2   2 
		  3   3   3   3   3   3   3   3   3   3 
		  3   3   3   3   3   4   4   4   4   4 
		  4   4   4   4   4   4   4   4   4   4 
		  4   4   4   4   4   4   5   5   5   5 
		  5   5   5   5   5   5   5   5   6   6 
		  6   6   6   6   6   6   6   6   6   6 
		  6   6   7   7   7   7   7   7   7   7 
		  7   7   7   7   8   8   8   8   8   8 
		  8   8   8   8   8   8   8   8   8   8 
		  9   9   9   9   9   9   9   9   9 
        
* #####Results in Python

		$python3 insertion.py
		Initialized
		  3  3  7  9  9  2  4  4  2  5  0
		  8  7  8  7  8  8  8  8  2  9
		  4  0  3  7  2  8  3  0  2  9
		  5  4  1  1  5  8  4  8  5  3
		  1  1  9  7  9  1  9  7  1  1
		  1  5  0  3  3  2  4  3  5  2
		  1  2  6  7  7  3  4  1  5  3
		  8  6  5  3  9  1  0  6  8  8
		  9  5  0  8  0  3  3  4  7  6
		  2  6  0  7  3  5  1  4  2  2
		  5  3  2  6  9  4  2  7  5  0
		  1  7  6  1  9  4  8  4  1  1
		  8  2  6  9  2  1  1  8  8  4
		  0  0  3  4  0  9  4  6  2  0
		  6  0  5  6  8  9  6  4  8

		After insertion_sort
		  0  0  0  0  0  0  0  0  0  0  0
		  0  0  0  1  1  1  1  1  1  1
		  1  1  1  1  1  1  1  1  1  1
		  1  2  2  2  2  2  2  2  2  2
		  2  2  2  2  2  2  2  3  3  3
		  3  3  3  3  3  3  3  3  3  3
		  3  3  3  4  4  4  4  4  4  4
		  4  4  4  4  4  4  4  4  4  5
		  5  5  5  5  5  5  5  5  5  5
		  5  5  6  6  6  6  6  6  6  6
		  6  6  6  6  7  7  7  7  7  7
		  7  7  7  7  7  7  8  8  8  8
		  8  8  8  8  8  8  8  8  8  8
		  8  8  8  8  8  9  9  9  9  9
		  9  9  9  9  9  9  9  9  9
