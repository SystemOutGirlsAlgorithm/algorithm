# 566. Reshape the Matrix
import numpy as np

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        cnt = len(mat)*len(mat[0])
        if r*c != cnt:
            return mat
        
        flat_num = []
        for arr in mat:
            for num in arr:
                flat_num.append(num)
        
        answer = np.zeros([r, c], dtype=np.int64)
        for i in range(r):
            for j in range(c):
                answer[i][j] = flat_num[i*c + j]
        
        return answer