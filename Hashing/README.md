* ####Hashing
    - [x] [Hashing with Chaining (video)](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8)
    - [x] [Table Doubling, Karp-Rabin (video)](https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    * [Hash Map](#hash-map)
	* [Rolling hash ADT(Karp-Rabin algorithm)](#karp-rabin-algorithm)
		* Implementation
		* Result


* #####Karp-Rabin algorithm
	* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/Hashing/KR_string.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/Hashing/KR_string.py)
	* [Result](#result-in-c)

	* #####Hint

	![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/hs.png)


	* #####Result in C


			$./a.out
			result: 982, Took 0.000000 seconds
            result: 982, Took 0.000000 seconds

* #####Hash Map
	* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/Hashing/hashmap.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/Hashing/hashmap.py)
	* [Result](#hash-result-in-c)

	* #####Hint

	![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/hashfunc.png)

    * #####Hash Result in C

			size: 1, capacity: 1
			size: 2, capacity: 2
			size: 2, capacity: 4
			delete c:	1
			hashget(table, c): 0	hashget(table, d):10
