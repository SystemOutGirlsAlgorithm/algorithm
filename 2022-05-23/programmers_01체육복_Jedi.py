def solution(n, lost, reserve):

    _re = [r for r in reserve if r not in lost]
    _lo = [l for l in lost if l not in reserve]

    for r in _re:
        f = r - 1
        b = r + 1
        if f in _lo:
            _lo.remove(f)
        elif b in _lo:
            _lo.remove(b)


    return n - len(_lo)

print(solution(5, [2, 4], [1, 3, 5]))
print(solution(5,[2, 4],[3]))
print(solution(3,[3],[1]))