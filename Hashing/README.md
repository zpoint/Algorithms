* ####Hashing
    - [x] [Hashing with Chaining (video)](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8)
    - [x] [Table Doubling, Karp-Rabin (video)](https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
	* [Rolling hash ADT(Karp-Rabin algorithm)](#karp-rabin-algorithm)
		* Implementation
		* Result


* #####Karp-Rabin algorithm
	* [Implementation in C](https://github.com/zpoint/Algorithms/tree/master/hashing/KR_string.c)
	* [Implementation in Python3](https://github.com/zpoint/Algorithms/tree/master/hashing/KR_string.py)
	* [Result](#result-in-c)

	* #####Hint

	![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/hs.png)


* #####Result in C

		$./a.out
		size: 150, After initialized
		 39   0   3  79  55  80  55  22  61  43 
		 72  74  89  83  78  59  77  80  41  10 
		 22  95  37  83  18  24  96  40  95  60 
		 85  34  12  88  66  67  68  21  42  81 
		 64  66  56   6  49  86  65  26  66  58 
		 88  40   6  77  75  24  54  23  16  49 
		 83   1  36  48  90  54  15  10  75   9 
		 92  92  75   0  98  24  86  15   2   4 
		 26  42  44  32  20  20  56  26  43  73 
		 27  79  26  63  27  16  17  94  79  45 
		  4  71  89  79  23  87  56  61  54  58 
		 65  32   1   9  64  73  81  73  99  77 
		 46  26  56  72  42  35  41  11  29  20 
		 56  85  43  45  17  18  84  73  79  91 
		 83  44  23  84   5  40   9  39  13  60 
		
		
		size: 150, After quicksort
		  0   0   1   1   2   3   4   4   5   6 
		  6   9   9   9  10  10  11  12  13  15 
		 15  16  16  17  17  18  18  20  20  20 
		 21  22  22  23  23  23  24  24  24  26 
		 26  26  26  26  27  27  29  32  32  34 
		 35  36  37  39  39  40  40  40  41  41 
		 42  42  42  43  43  43  44  44  45  45 
		 46  48  49  49  54  54  54  55  55  56 
		 56  56  56  56  58  58  59  60  60  61 
		 61  63  64  64  65  65  66  66  66  67 
		 68  71  72  72  73  73  73  73  74  75 
		 75  75  77  77  77  78  79  79  79  79 
		 79  80  80  81  81  83  83  83  83  84 
		 84  85  85  86  86  87  88  88  89  89 
		 90  91  92  92  94  95  95  96  98  99 
        
* #####Results in Python

		$python3 quick_sort.py
		size: 150, After initialized
		 47  98  30  18   9  82  28  51  75   1 
		 92  73  65  43  34   5  90  70  51  13 
		  2  66  97  10  85  59  80  92  51  73 
		 23  98  71   5  68  33  87  48  84  14 
		  1  76  40  66  71  74  24  61  96  75 
		 74  99  93  23   9  79  34  89  23  85 
		 62  98  83  85   3   3  18  90  51   2 
		 56  53  78  96  71  49  23  47  62  19 
		 75  36  18  68  60  27  99  94  68  22 
		 80  30  72  15  68  75  71  86  17  22 
		 89  74  27  19  22  99  21  45  98  83 
		 65  73  72  83  42  84  63  93  30  31 
		 68  10  14  40  78  82  68  49  20  85 
		 23   9  11  51  81  34   2  54  31   0 
		 37  96  26  61  32  20  45  47  13  76 
		
		
		size: 150, After quicksort
		  0   1   1   2   2   2   3   3   5   5 
		  9   9   9  10  10  11  13  13  14  14 
		 15  17  18  18  18  19  19  20  20  21 
		 22  22  22  23  23  23  23  23  24  26 
		 27  27  28  30  30  30  31  31  32  33 
		 34  34  34  36  37  40  40  42  43  45 
		 45  47  47  47  48  49  49  51  51  51 
		 51  51  53  54  56  59  60  61  61  62 
		 62  63  65  65  66  66  68  68  68  68 
		 68  68  70  71  71  71  71  72  72  73 
		 73  73  74  74  74  75  75  75  75  76 
		 76  78  78  79  80  80  81  82  82  83 
		 83  83  84  84  85  85  85  85  86  87 
		 89  89  90  90  92  92  93  93  94  96 
		 96  96  97  98  98  98  98  99  99  99 
