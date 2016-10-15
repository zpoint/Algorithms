###Practice and Notes
* [Stacks](#stacks)
	* [Concept](#stacks)
	* [early Implementation (stack & queue)](https://github.com/zpoint/Algorithms/blob/master/CLRS/stack_queue.c)
	* [early practice (stack & queue)](https://github.com/zpoint/Algorithms/blob/master/CLRS/stack_queue_practice.c)
* [Queue](#queue)
	* [Double-ended_queue](#queue)
	* [Priority_queue](#queue)
		* [my implementation](#queue)
		* [result](#queue)
* [Circular buffer](#circular-buffer)
	* [Concept](#circular-buffer)
* [Practice](#practice)
	* [practice from here](https://github.com/jwasham/google-interview-university#queue)
	* [Implement using linked-list, with tail pointer]()
	* [Implement using fixed-sized array]()
* [test result](#)

- - -

####Stacks

[Concept of Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

 ![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/stack.png)

- - -

####Queue
[Double-ended_queue](https://en.wikipedia.org/wiki/Double-ended_queue)

[Priority_queue](https://en.wikipedia.org/wiki/Priority_queue)
- [my implementation](https://github.com/zpoint/Algorithms/tree/master/Stack_Queue/pq.c)


![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/ipq.png)


- ######result(priority_queue)
		Queue length is 0, find err		After initialized
		capacity: 16, length: 0, pq_findmin: -2147483648
		
		After insert value 100 to 1:
		capacity: 128, length: 100, pq_findmin: 1
		0:1	1:100	2:99	3:98	4:97	5:96	6:95	7:94	8:93	9:92	10:91	
		11:90	12:89	13:88	14:87	15:86	16:85	17:84	18:83	19:82	20:81	
		21:80	22:79	23:78	24:77	25:76	26:75	27:74	28:73	29:72	30:71	
		31:70	32:69	33:68	34:67	35:66	36:65	37:64	38:63	39:62	40:61	
		41:60	42:59	43:58	44:57	45:56	46:55	47:54	48:53	49:52	50:51	
		51:50	52:49	53:48	54:47	55:46	56:45	57:44	58:43	59:42	60:41	
		61:40	62:39	63:38	64:37	65:36	66:35	67:34	68:33	69:32	70:31	
		71:30	72:29	73:28	74:27	75:26	76:25	77:24	78:23	79:22	80:21	
		81:20	82:19	83:18	84:17	85:16	86:15	87:14	88:13	89:12	90:11	
		91:10	92:9	93:8	94:7	95:6	96:5	97:4	98:3	99:2	
		Call deletemin 30 times
		capacity: 128, length: 70, pq_findmin: 31
		0:31	1:100	2:99	3:98	4:97	5:96	6:95	7:94	8:93	9:92	10:91	
		11:90	12:89	13:88	14:87	15:86	16:85	17:84	18:83	19:82	20:81	
		21:80	22:79	23:78	24:77	25:76	26:75	27:74	28:73	29:72	30:71	
		31:70	32:69	33:68	34:67	35:66	36:65	37:64	38:63	39:62	40:61	
		41:60	42:59	43:58	44:57	45:56	46:55	47:54	48:53	49:52	50:51	
		51:50	52:49	53:48	54:47	55:46	56:45	57:44	58:43	59:42	60:41	
		61:40	62:39	63:38	64:37	65:36	66:35	67:34	68:33	69:32	

- - -

####Circular buffer
[Concept of Circular buffer](https://en.wikipedia.org/wiki/Circular_buffer)

![image](https://github.com/zpoint/Algorithms/blob/master/screenshots/cb.gif)

- - -

####Practice
- [practice from here](https://github.com/jwasham/google-interview-university#queue)


- [x] Implement using linked-list, with tail pointer:
    - enqueue(value) - adds value at position at tail
    - dequeue() - returns value and removes least recently added element (front)
    - empty()
- [x] Implement using fixed-sized array:
    - enqueue(value) - adds item at end of available storage
    - dequeue() - returns value and removes least recently added element
    - empty()
    - full()
- [ ] Cost:
    - a bad implementation using linked list where you enqueue at head and dequeue at tail would be O(n)
        because you'd need the next to last element, causing a full traversal each dequeue
    - enqueue: O(1) (amortized, linked list and array [probing])
    - dequeue: O(1) (linked list and array)
    - empty: O(1) (linked list and array)


- [Implement using linked-list, with tail pointer](https://github.com/zpoint/Algorithms/tree/master/Stack_Queue/linked_list.c)
- [Implement using fixed-sized array](https://github.com/zpoint/Algorithms/tree/master/Stack_Queue/fsize_array.c)

####Results
- Implement using linked-list

		Queue initialized empty?: 1 size: 0
		
		Enqueue 1 -- 100 empty?: 0 size: 100
		0: 0	1: 1	2: 2	3: 3	4: 4	5: 5	6: 6	7: 7	8: 8	9: 9	10: 10	
		11: 11	12: 12	13: 13	14: 14	15: 15	16: 16	17: 17	18: 18	19: 19	20: 20	
		21: 21	22: 22	23: 23	24: 24	25: 25	26: 26	27: 27	28: 28	29: 29	30: 30	
		31: 31	32: 32	33: 33	34: 34	35: 35	36: 36	37: 37	38: 38	39: 39	40: 40	
		41: 41	42: 42	43: 43	44: 44	45: 45	46: 46	47: 47	48: 48	49: 49	50: 50	
		51: 51	52: 52	53: 53	54: 54	55: 55	56: 56	57: 57	58: 58	59: 59	60: 60	
		61: 61	62: 62	63: 63	64: 64	65: 65	66: 66	67: 67	68: 68	69: 69	70: 70	
		71: 71	72: 72	73: 73	74: 74	75: 75	76: 76	77: 77	78: 78	79: 79	80: 80	
		81: 81	82: 82	83: 83	84: 84	85: 85	86: 86	87: 87	88: 88	89: 89	90: 90	
		91: 91	92: 92	93: 93	94: 94	95: 95	96: 96	97: 97	98: 98	99: 99	
		Dequeue 50 times empty?: 0 size: 50
		0: 0	1: 1	2: 2	3: 3	4: 4	5: 5	6: 6	7: 7	8: 8	9: 9	10: 10	
		11: 11	12: 12	13: 13	14: 14	15: 15	16: 16	17: 17	18: 18	19: 19	20: 20	
		21: 21	22: 22	23: 23	24: 24	25: 25	26: 26	27: 27	28: 28	29: 29	30: 30	
		31: 31	32: 32	33: 33	34: 34	35: 35	36: 36	37: 37	38: 38	39: 39	40: 40	
		41: 41	42: 42	43: 43	44: 44	45: 45	46: 46	47: 47	48: 48	49: 49	
        

- Implement using fixed-sized array

		start: 0, end: 0, empty: 1, full: 0, initialized
		0	0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	
		start: 0, end: 19, empty: 0, full: 1, enqueue 1 - 19
		0	X 	X 	X 	X 	X 	X 	X 	X 	X 	X 	
		X 	X 	X 	X 	X 	X 	X 	X 	19	
		start: 0, end: 9, empty: 0, full: 0, dequeue 10 times
		0	X 	X 	X 	X 	X 	X 	X 	X 	9	10	
		11	12	13	14	15	16	17	18	19	