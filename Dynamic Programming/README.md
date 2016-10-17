###Practice and Notes
- [x] [Skiena: CSE373 2012 - Lecture 19 - Introduction to Dynamic Programming (video)](https://youtu.be/Qc2ieXRgR0k?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=1718)
	* [Pascal's Triangle](#pascal's-triangle)
- [Edit Distance](#edit-distance)




####Edit Distance

* [Edit Distance 1 (video)](https://www.youtube.com/watch?v=8Q2IEIY2pDU&index=33&list=PL2mpR0RYFQsBiCWVJSvVAO3OJ2t7DzoHA)
* [Edit Distance 2 (video)](https://www.youtube.com/watch?v=0KzWq118UNI&index=34&list=PL2mpR0RYFQsBiCWVJSvVAO3OJ2t7DzoHA)
* [Edit Distance 3 (video)](https://www.youtube.com/watch?v=Xg6uyW9Bscs&index=35&list=PL2mpR0RYFQsBiCWVJSvVAO3OJ2t7DzoHA)
* [Implementation in C](https://github.com/zpoint/Algorithms/tree/master/Dynamic%20Programming/edit_distance.c)
* [Implementation in Python3](https://github.com/zpoint/Algorithms/tree/master/Sort/quick%20sort/edit_distance.py)
* ####hint
* ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/ed.png)
* #####Results in Python

		$python3 edit_distance.py
		Oh my gooood
		hh mv goooid
		editDistanceRecursive result: 3	Cost: 118.52966 seconds
		Dynamic Programming Editdistance result:  3	Cost: 0.00015 seconds

* #####Result in C

		$./a.out
		Oh my gooiidood
		hh mv gooioeoid
		Calling editDistanceRecursive:
		Result: 5, Cost: 232.185000 seconds
		Calling Dynamic Programming editDistance:
		result: 5, Cost: 0.000000 seconds




#####Pascal's Triangle
[Implementation](https://github.com/zpoint/Algorithms/tree/master/Dynamic%20Programming/pt.c)

![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/pt.png)

