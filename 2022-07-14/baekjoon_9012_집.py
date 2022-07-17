import sys


# read an integer (the num of input lines)
n = int(sys.stdin.readline())


# for loop to get multi inputs
for i in range(n):
    # get an input (removed '\n')
    vps = sys.stdin.readline().rstrip()
    count = 0
    dictionary = {}

    for paren in vps:
        # 1 nothing is in the dictionary
        # 2 ( is in the dictionary
        # 3 )

        count += 1
        # when ( appears
        # store ( in the dict or add the value + 1
        # however, if ) doesn't appear until the end --> print(NO)
        if paren == '(':
            # initialization a key in dict
            if '(' not in dictionary:
                dictionary['('] = 1
            else:
                if count == len(vps):
                    print('NO')
                else:
                    dictionary['('] += 1
        # when ) appears
        # check the key '(' and subtract the value - 1
        else:
            # if ( is not in the dictionary --> not able to check --> print(NO) and stop
            if '(' not in dictionary or dictionary.get('(') <= 0:
                print('NO')
                break
            # if ( is in the dictionary
            else:
                dictionary['('] -= 1
                if count == len(vps):
                    if dictionary.get('(') == 0:
                        print('YES')
                    else:
                        print('NO')