* ####String

    * [Longest Palindrome Substring String](#palindrome-string)
    	* [Dynamic Programming (O(n^2))](#dynamic-programming)
    	* [maracher's Algorithms (O(n)) (Unsolved)](#maracher's-algorithm)
	* [Longest Common Substring (Dynamic Programming)](#longest-common-substring)



- - -

* #####Palindrome String
	* ######**Dynamic Programming**
		* [Video](https://www.youtube.com/watch?v=obBdxeCx_Qs)
		* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/String/ps_dp.c)
		* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/String/ps_dp.py)
		* hint
		![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/lps.png)
		* **Result**


		* Result in C


					$./a.out
					HJKJH
					result: 5



		* Result in Python3

                	string: BANANA, maxsubstring: ANANA, len: 5


	* ######**Maracher's Algorithm**
		* [Video](https://www.youtube.com/watch?v=V-sEwsca1ak)



- - -

* #####Longest Common Substring
	* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/String/lcstring.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/String/lcstring.py)


	* **hint**
    
    ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/lcs.png)
    
	* Result in C

			stringA:	tutorialhorizon
			stringB:	dynamictutorialProgramming
			lcstring:	tutorial
			length: 	8

	* Result in Python

			stringA:	12345678999999987654321
 			stringB:	87654321
 			lsctring:	87654321
 			length:	    8
