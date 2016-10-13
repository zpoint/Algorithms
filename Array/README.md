###Practice
* [A vector](#a-vector)
* [my vector implementation](https://github.com/zpoint/Algorithms/blob/master/Array/vector.c)
* [test result](#results)

####A vector

[practice from here](https://github.com/jwasham/google-interview-university#arrays)

- [x] Implement a vector (mutable array with automatic resizing):
	- [ ] Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
	- [ ] new raw data array with allocated memory
     - can allocate int array under the hood, just not use its features
     - start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
    - [ ] size() - number of items
    - [ ] capacity() - number of items it can hold
    - [ ] is_empty()
    - [ ] at(index) - returns item at given index, blows up if index out of bounds
    - [ ] push(item)
    - [ ] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
    - [ ] prepend(item) - can use insert above at index 0
    - [ ] pop() - remove from end, return value
    - [ ] delete(index) - delete item at index, shifting all trailing elements left
    - [ ] remove(item) - looks for value and removes index holding it (even if in multiple places)
    - [ ] find(item) - looks for value and returns first index with that value, -1 if not found
    - [ ] resize(new_capacity) // private function
        - when you reach capacity, resize to double the size
        - when popping an item, if size is 1/4 of capacity, resize to half
    - [ ] Time
        - O(1) to add/remove at end (amortized for allocations for more space), index, or update
        - O(n) to insert/remove elsewhere
    - [ ] Space
        - contiguous in memory, so proximity helps performance
        - space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)

####Results
		$gcc vector.c
		$./a.out
		vector intialized
		size: 0, capacity: 16, is_empty(): 0
		traverse:
		
		After push 200 random number between 0 - 100
		size: 200, capacity: 256, is_empty(): 200
		traverse:
		81	90	52	51	15	26	55	29	48	99	75	
		34	36	74	16	13	35	4	58	23	51	
		92	91	48	85	61	66	6	91	57	13	
		24	47	65	75	62	91	83	91	92	34	
		66	78	70	93	94	83	80	51	94	3	
		2	86	47	2	72	8	20	30	52	77	
		43	76	25	60	4	39	52	39	31	44	
		73	49	74	43	94	69	79	74	72	73	
		30	26	11	77	80	35	37	0	65	41	
		29	60	70	54	21	26	46	25	65	77	
		21	38	78	95	33	25	64	64	51	36	
		37	81	14	1	10	94	88	0	94	54	
		41	24	66	63	30	87	89	76	12	54	
		5	33	44	36	29	30	61	45	94	12	
		34	84	46	48	85	8	95	73	60	89	
		79	54	65	46	17	48	85	59	76	50	
		13	34	83	10	70	64	40	83	62	34	
		47	48	70	45	48	55	6	43	81	66	
		33	12	20	50	10	90	50	48	49	27	
		98	62	13	33	24	35	50	64	18	
		After pop 100 number
		size: 100, capacity: 256, is_empty(): 100
		traverse:
		81	90	52	51	15	26	55	29	48	99	75	
		34	36	74	16	13	35	4	58	23	51	
		92	91	48	85	61	66	6	91	57	13	
		24	47	65	75	62	91	83	91	92	34	
		66	78	70	93	94	83	80	51	94	3	
		2	86	47	2	72	8	20	30	52	77	
		43	76	25	60	4	39	52	39	31	44	
		73	49	74	43	94	69	79	74	72	73	
		30	26	11	77	80	35	37	0	65	41	
		29	60	70	54	21	26	46	25	65	
		insert 10 in 210, result: 10
		size: 211, capacity: 256, is_empty(): 211
		traverse:
		81	90	52	51	15	26	55	29	48	99	75	
		34	36	74	16	13	35	4	58	23	51	
		92	91	48	85	61	66	6	91	57	13	
		24	47	65	75	62	91	83	91	92	34	
		66	78	70	93	94	83	80	51	94	3	
		2	86	47	2	72	8	20	30	52	77	
		43	76	25	60	4	39	52	39	31	44	
		73	49	74	43	94	69	79	74	72	73	
		30	26	11	77	80	35	37	0	65	41	
		29	60	70	54	21	26	46	25	65	77	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	10	
		
		find 10:210
		size: 211, capacity: 256, is_empty(): 211
		traverse:
		81	90	52	51	15	26	55	29	48	99	75	
		34	36	74	16	13	35	4	58	23	51	
		92	91	48	85	61	66	6	91	57	13	
		24	47	65	75	62	91	83	91	92	34	
		66	78	70	93	94	83	80	51	94	3	
		2	86	47	2	72	8	20	30	52	77	
		43	76	25	60	4	39	52	39	31	44	
		73	49	74	43	94	69	79	74	72	73	
		30	26	11	77	80	35	37	0	65	41	
		29	60	70	54	21	26	46	25	65	77	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	10	
		
		remove 10:0
		size: 211, capacity: 256, is_empty(): 211
		traverse:
		81	90	52	51	15	26	55	29	48	99	75	
		34	36	74	16	13	35	4	58	23	51	
		92	91	48	85	61	66	6	91	57	13	
		24	47	65	75	62	91	83	91	92	34	
		66	78	70	93	94	83	80	51	94	3	
		2	86	47	2	72	8	20	30	52	77	
		43	76	25	60	4	39	52	39	31	44	
		73	49	74	43	94	69	79	74	72	73	
		30	26	11	77	80	35	37	0	65	41	
		29	60	70	54	21	26	46	25	65	77	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	