# Python program to demonstrate FCFS Disk Scheduling algorithm

size = 8

def FCFS(arr, head):

	seek_count = 0
	distance, cur_track = 0, 0

	for i in range(size):
		cur_track = arr[i]

		# calculate absolute distance
		distance = abs(cur_track - head)

		# increase the total count
		seek_count += distance

		# accessed track is now new head
		head = cur_track
	
	print("Total number of seek operations = ", seek_count)

	# Seek sequence would be the same as request array sequence
	print("Seek Sequence is")

	for i in range(size):
		print(arr[i])
	

if __name__ == '__main__':

	# request array
	arr = [56, 88, 15, 48, 86, 23, 158, 9]
	head = 50

	FCFS(arr, head)