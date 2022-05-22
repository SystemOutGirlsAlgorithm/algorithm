# 566. Reshape the Matrix(list comprehension)
class Solution(object):
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        len_mat = len(mat) * len(mat[0])
        if len_mat != r * c:
            return mat
        vector = [x for row in mat for x in row]
        return [vector[i:i + c] for i in range(0, len_mat, c)]