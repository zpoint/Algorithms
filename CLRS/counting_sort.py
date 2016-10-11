def counting_sort(array_unsorted, max_value):
	array_temp = [0 for i in range(max_value + 1)]
	array_return = [float("-inf") for i in range(len(array_unsorted))]
	for i in range(len(array_unsorted)):
		array_temp[array_unsorted[i]] += 1
	for i in range(1, max_value + 1):
		array_temp[i] += array_temp[i - 1]
	"""
	print("array_unsorted",array_unsorted)
	print("array_temp",array_temp)
	print("array_return",array_return)
	"""
	for i in range(len(array_unsorted) - 1, -1, -1):
		array_return[array_temp[array_unsorted[i]] - 1] = array_unsorted[i]
		array_temp[array_unsorted[i]] -= 1
		#print (i)
		#print (array_return)
	return array_return
	
if __name__ == '__main__':
	A = [2,5,3,0,2,3,0,3]
	print(counting_sort(A, 5))