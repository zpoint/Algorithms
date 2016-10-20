* ####Eratosthenes's Seive
	* [Video](https://www.youtube.com/watch?v=veZShPR82oc)
	* [Implementation in C](https://github.com/zpoint/Algorithms/blob/master/prime/find_prime.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/blob/master/prime/find_prime.py)
	* [Result](#result-in-c)

* #####Result in C

		$./a.out
		normal_prime:
		2    3    5    7    11   13   17   19   23   29   
		31   37   41   43   47   53   59   61   67   71   
		73   79   83   89   97   
		 from 1 to 100, Total: 25 prime
		eratosh_prime:
		2    3    5    7    11   13   17   19   23   29   
		31   37   41   43   47   53   59   61   67   71   
		73   79   83   89   97   
		from 1 to 100, Total: 25 prime
        
		normal_prime:  from 1 to 9999999 result: 664579, cost : 55.271000 seconds
		eratosh_prime: from 1 to 9999999 result: 664579, cost : 0.240000 seconds
        
* #####Results in Python

		$python3 insertion.py
		normal_prime from 1 to 9999999, result: 664579, time: 208 seconds
		eratos_prime from 1 to 9999999, result: 664579, time: 5 seconds
