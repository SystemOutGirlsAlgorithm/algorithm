baduk = []

for _ in range(19) :
    baduk.append(list(map(int, input().split())))

check = [[1, 0], [1, 1], [0, 1], [-1, 1]]

def solution(value, tmpi, tmpj, a, b, baduk, count) :
    while True :
        tmpi += a
        tmpj += b
        if 0 <= tmpi <= 18 and 0 <= tmpj <= 18 and baduk[tmpi][tmpj] == value:
            count += 1
            solution(value, tmpi, tmpj, a, b, baduk, count)
        else :
            return count
            break

for i in range(19) :
    for j in range(19) :
        if baduk[i][j] == 1 or baduk[i][j] == 2 :
            for a, b in check :
                chki = i - a
                chkj = j - b
                if 0 <= chki <= 18 and 0 <= chkj <= 18 and baduk[chki][chkj] == baduk[i][j] :
                    continue
                count = solution(baduk[i][j], i, j, a, b, baduk, 1)
                if count == 5 :
                    print(baduk[i][j])
                    print(i + 1, j + 1)
                    exit(0)
print(0)

    