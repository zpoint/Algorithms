###Practice
* [Linked Lists](#linked-lists)
* [my Double(single the same) Linked Lists implementation](https://github.com/zpoint/Algorithms/blob/master/Linked%20Lists/list.c)
* [test result](#results)

####Linked Lists
[practice from here](https://github.com/jwasham/google-interview-university#linked-lists)
- [x] implement :
    - [ ] size() - returns number of data elements in list
    - [ ] empty() - bool returns true if empty
    - [ ] value_at(index) - returns the value of the nth item (starting at 0 for first)
    - [ ] push_front(value) - adds an item to the front of the list
    - [ ] pop_front() - remove front item and return its value
    - [ ] push_back(value) - adds an item at the end
    - [ ] pop_back() - removes end item and returns its value
    - [ ] front() - get value of front item
    - [ ] back() - get value of end item
    - [ ] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
    - [ ] erase(index) - removes node at given index
    - [ ] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
    - [ ] reverse() - reverses the list
    - [ ] remove_value(value) - removes the first item in the list with this

####Results
		$./a.out
		initialized:
		HEAD at: (nil), Tail at: (nil), size: 0 front: -2147483648, back: -2147483648
		
		push 100 (50 front, 50 back) random value
		HEAD at: 0x15cf060, Tail at: 0x15cf080, size: 100 front: 0, back: 99
		 0: 0	 1: 1	 2: 2	 3: 3	 4: 4	 5: 5	 6: 6	 7: 7	 8: 8	 9: 9	
		 10: 10	 11: 11	 12: 12	 13: 13	 14: 14	 15: 15	 16: 16	 17: 17	 18: 18	 19: 19	
		 20: 20	 21: 21	 22: 22	 23: 23	 24: 24	 25: 25	 26: 26	 27: 27	 28: 28	 29: 29	
		 30: 30	 31: 31	 32: 32	 33: 33	 34: 34	 35: 35	 36: 36	 37: 37	 38: 38	 39: 39	
		 40: 40	 41: 41	 42: 42	 43: 43	 44: 44	 45: 45	 46: 46	 47: 47	 48: 48	 49: 49	
		 50: 50	 51: 51	 52: 52	 53: 53	 54: 54	 55: 55	 56: 56	 57: 57	 58: 58	 59: 59	
		 60: 60	 61: 61	 62: 62	 63: 63	 64: 64	 65: 65	 66: 66	 67: 67	 68: 68	 69: 69	
		 70: 70	 71: 71	 72: 72	 73: 73	 74: 74	 75: 75	 76: 76	 77: 77	 78: 78	 79: 79	
		 80: 80	 81: 81	 82: 82	 83: 83	 84: 84	 85: 85	 86: 86	 87: 87	 88: 88	 89: 89	
		 90: 90	 91: 91	 92: 92	 93: 93	 94: 94	 95: 95	 96: 96	 97: 97	 98: 98	 99: 99	
		
		erase , pop_back, pop_front 33 times
		HEAD at: 0x15ce840, Tail at: 0x15ce840, size: 1 front: 66, back: 66
		 0: 66	
		insert 0-99:
		HEAD at: 0x15cf0a0, Tail at: 0x15ce840, size: 101 front: 99, back: 66
		 0: 99	 1: 98	 2: 97	 3: 96	 4: 95	 5: 94	 6: 93	 7: 92	 8: 91	 9: 90	
		 10: 89	 11: 88	 12: 87	 13: 86	 14: 85	 15: 84	 16: 83	 17: 82	 18: 81	 19: 80	
		 20: 79	 21: 78	 22: 77	 23: 76	 24: 75	 25: 74	 26: 73	 27: 72	 28: 71	 29: 70	
		 30: 69	 31: 68	 32: 67	 33: 66	 34: 65	 35: 64	 36: 63	 37: 62	 38: 61	 39: 60	
		 40: 59	 41: 58	 42: 57	 43: 56	 44: 55	 45: 54	 46: 53	 47: 52	 48: 51	 49: 50	
		 50: 49	 51: 48	 52: 47	 53: 46	 54: 45	 55: 44	 56: 43	 57: 42	 58: 41	 59: 40	
		 60: 39	 61: 38	 62: 37	 63: 36	 64: 35	 65: 34	 66: 33	 67: 32	 68: 31	 69: 30	
		 70: 29	 71: 28	 72: 27	 73: 26	 74: 25	 75: 24	 76: 23	 77: 22	 78: 21	 79: 20	
		 80: 19	 81: 18	 82: 17	 83: 16	 84: 15	 85: 14	 86: 13	 87: 12	 88: 11	 89: 10	
		 90: 9	 91: 8	 92: 7	 93: 6	 94: 5	 95: 4	 96: 3	 97: 2	 98: 1	 99: 0	
		 100: 66	

		now call reverse: 
		HEAD at: 0x15ce840, Tail at: 0x15cf0a0, size: 101 front: 66, back: 99
		 0: 66	 1: 0	 2: 1	 3: 2	 4: 3	 5: 4	 6: 5	 7: 6	 8: 7	 9: 8	
		 10: 9	 11: 10	 12: 11	 13: 12	 14: 13	 15: 14	 16: 15	 17: 16	 18: 17	 19: 18	
		 20: 19	 21: 20	 22: 21	 23: 22	 24: 23	 25: 24	 26: 25	 27: 26	 28: 27	 29: 28	
		 30: 29	 31: 30	 32: 31	 33: 32	 34: 33	 35: 34	 36: 35	 37: 36	 38: 37	 39: 38	
		 40: 39	 41: 40	 42: 41	 43: 42	 44: 43	 45: 44	 46: 45	 47: 46	 48: 47	 49: 48	
		 50: 49	 51: 50	 52: 51	 53: 52	 54: 53	 55: 54	 56: 55	 57: 56	 58: 57	 59: 58	
		 60: 59	 61: 60	 62: 61	 63: 62	 64: 63	 65: 64	 66: 65	 67: 66	 68: 67	 69: 68	
		 70: 69	 71: 70	 72: 71	 73: 72	 74: 73	 75: 74	 76: 75	 77: 76	 78: 77	 79: 78	
		 80: 79	 81: 80	 82: 81	 83: 82	 84: 83	 85: 84	 86: 85	 87: 86	 88: 87	 89: 88	
		 90: 89	 91: 90	 92: 91	 93: 92	 94: 93	 95: 94	 96: 95	 97: 96	 98: 97	 99: 98	
		 100: 99	
		Value_n_from_end(3): 96, value_at(3): 2