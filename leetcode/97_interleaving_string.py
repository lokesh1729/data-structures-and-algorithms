class Solution:
    # @param A : string
    # @param B : string
    # @param C : string
    # @return an integer
    def isInterleave(self, A, B, C):
        n1  = len(A)
        n2 = len(B)
        n3 = len(C)
        if n3 != n1 + n2:
            return False
        def isInterleaveRecursive(index1, index2, index3):
            if index3 >= n3:
                return True
            result = False
            if(index1 < n1 and A[index1] == C[index3]):
                result |= isInterleaveRecursive(index1+1, index2, index3+1)
            if(index2 < n2 and B[index2] == C[index3]):
                result |= isInterleaveRecursive(index1, index2+1, index3+1)
            return result
        return isInterleaveRecursive(0, 0, 0)
