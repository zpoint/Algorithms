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


- [Implement using linked-list, with tail pointer]()
- [Implement using fixed-sized array]()
