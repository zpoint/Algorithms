* #### String

    * [Longest Palindrome Substring String](#palindrome-string)
    	* [Dynamic Programming (O(n^2))](#dynamic-programming)
    	* [maracher's Algorithms (O(n)) (Unsolved)](#maracher's-algorithm)
	* [Longest Common Substring (Dynamic Programming)](#longest-common-substring)
	* [Knuth–Morris–Pratt Algorithm](#knuth–morris-pratt-algorithm)



- - -

* ##### Palindrome String
	* ###### **Dynamic Programming**
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


	* ###### **Maracher's Algorithm**
		* [Video](https://www.youtube.com/watch?v=V-sEwsca1ak)



- - -

* ##### Longest Common Substring
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


- - -

* ##### Knuth–Morris–Pratt algorithm
	* [KMP Full Video](https://www.youtube.com/watch?annotation_id=annotation_109280825&feature=iv&src_vid=KG44VoDtsAA&v=GTJr8OvyEVQ)
	* [KMP PreFix Array Logic](https://www.youtube.com/watch?v=KG44VoDtsAA)
	* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/String/kmp.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/String/kmp.py)


	* **hint**

    ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/kmp.png)


	* Result in C

			a: abxabcabcabyxxabcabyj, b: abcaby
			match in index: 6
			match in index: 14


	* Result in Python

			a: banana, b: ana
			match_index: 1
			match_index: 3
