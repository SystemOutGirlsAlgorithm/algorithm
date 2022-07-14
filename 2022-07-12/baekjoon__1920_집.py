# put the numbers in the hash (dictionary)

# nums of elems in the array
n = int(input())
# read a line (array)
arr = list(map(int, input().split()))

# declare a dictionary to store the numbers
dicts = {}

# store the elems
for elem in arr:
    dicts[elem] = 100

# 2nd inputs
n_two = int(input())
arr_two = list(map(int, input().split()))

for elem in arr_two:
    if elem in dicts:
        print(1)
    else:
        print(0)