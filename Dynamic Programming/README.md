### Practice and Notes

- [x] [Skiena: CSE373 2012 - Lecture 19 - Introduction to Dynamic Programming (video)](https://youtu.be/Qc2ieXRgR0k?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=1718)
	* [Pascal's Triangle](#pascal's-triangle)
- [Edit Distance](#edit-distance)
- [RNA_secondary_structure](#rna-secondary-structure)
- [LCS (longest commin subsequence)](#lcs)


---
##### Edit Distance
---
* [Edit Distance 1 (video)](https://www.youtube.com/watch?v=8Q2IEIY2pDU&index=33&list=PL2mpR0RYFQsBiCWVJSvVAO3OJ2t7DzoHA)
* [Edit Distance 2 (video)](https://www.youtube.com/watch?v=0KzWq118UNI&index=34&list=PL2mpR0RYFQsBiCWVJSvVAO3OJ2t7DzoHA)
* [Edit Distance 3 (video)](https://www.youtube.com/watch?v=Xg6uyW9Bscs&index=35&list=PL2mpR0RYFQsBiCWVJSvVAO3OJ2t7DzoHA)
* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/Dynamic%20Programming/edit_distance.c)
* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/Dynamic%20Programming/edit_distance.py)
---
##### hint


* ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/ed.png)

* Results in Python

		$python3 edit_distance.py
		Oh my gooood
		hh mv goooid
		editDistanceRecursive result: 3	Cost: 118.52966 seconds
		Dynamic Programming Editdistance result:  3	Cost: 0.00015 seconds

* Result in C

    	$./a.out
		Oh my gooiidood
		hh mv gooioeoid
		Calling editDistanceRecursive:
		Result: 5, Cost: 232.185000 seconds
		Calling Dynamic Programming editDistance:
		result: 5, Cost: 0.000000 seconds
- - -

##### RNA secondary structure

[RNA secondary structure (video)](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/80RrW/the-rna-secondary-structure-problem)
* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/Dynamic%20Programming/RNA_secondary_structure.c)
* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/Dynamic%20Programming/RNA_secondary_structure.py)

* Results in Python

		 1   [0, 0, 0, 0, 0, 1, 1, 1, 2, 2]
		 2   [0, 0, 0, 0, 0, 0, 0, 1, 1, 1]
		 3   [0, 0, 0, 0, 0, 0, 0, 1, 1, 1]
		 4   [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
		 5   [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
		 6   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		 7   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		 8   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		 9   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		10   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
     
		      1  2  3  4  5  6  7  8  9 10 
		
		match: ACCGGUAGUC
		(1, 9) (2, 8) 
		(1, 9) (2, 10) 
		(1, 9) (3, 8) 
		(1, 9) (3, 10) 
		(1, 9) (4, 10) 
		(1, 9) (5, 10) 
		(1, 10) (2, 8) 
		(1, 10) (2, 9) 
		(1, 10) (3, 8) 
		(1, 10) (3, 9) 

* Result in C
	
    	$./a.out
		ACCGGUAGUCGGAT
		 1:  0  0  0  0  0  1  1  1  2  2  2  2  2  2 
		 2:  0  0  0  0  0  0  0  1  1  1  2  2  2  2 
		 3:  0  0  0  0  0  0  0  1  1  1  2  2  2  2 
		 4:  0  0  0  0  0  0  0  0  0  1  1  1  1  1 
		 5:  0  0  0  0  0  0  0  0  0  1  1  1  1  1 
		 6:  0  0  0  0  0  0  0  0  0  0  0  0  1  1 
		 7:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		 8:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		 9:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		10:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		11:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		12:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		13:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		14:  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
		
		     1  2  3  4  5  6  7  8  9 10 11 12 13 14 



---
#### Pascal's Triangle

[Implementation](https://github.com/zpoint/Algorithms/blob/master/Dynamic%20Programming/pt.c)

![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/pt.png)


---
##### LCS

- [Video](https://www.youtube.com/watch?v=NnD96abizww)
* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/Dynamic%20Programming/lcs.c)
* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/Dynamic%20Programming/lcs.py)

* Result in C

		0  0  0  0  0  0  0  0  0  0  
		0  1  1  1  1  1  1  1  1  1  
		0  1  1  2  2  2  2  2  2  2  
		0  1  2  2  2  2  2  2  2  2  
		0  1  2  3  3  3  3  3  3  3  
		0  1  2  3  3  3  4  4  4  4  
		0  1  2  3  3  3  4  5  5  5  
		0  1  2  3  3  3  4  5  6  6  
		abcdeffff
		acbcfff
		Result:f f f c b a 

* Result in Python3

		abcdeffff
		acbcfff
		0  0  0  0  0  0  0  0  0  0  
		0  1  1  1  1  1  1  1  1  1  
		0  1  1  2  2  2  2  2  2  2  
		0  1  2  2  2  2  2  2  2  2  
		0  1  2  3  3  3  3  3  3  3  
		0  1  2  3  3  3  4  4  4  4  
		0  1  2  3  3  3  4  5  5  5  
		0  1  2  3  3  3  4  5  6  6  
		Result:f  f  f  c  b  a  
---