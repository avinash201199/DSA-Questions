class Solution:
    # @param A : list of integers
    # @return an integer
    def merge(self,A, aux, low, mid, high):
        k = i = low
        j=mid+1
        inversionCount = 0
        while i <= mid and j <= high:
            if A[i] <= A[j]:
                aux[k] = A[i]
                i = i + 1
            else:
                aux[k] = A[j]
                j = j + 1
                inversionCount += (mid - i + 1)	
            k = k + 1
        while i <= mid:
            aux[k] = A[i]
            k = k + 1
            i = i + 1
        for i in range(low, high + 1):
            A[i] = aux[i]
        return inversionCount%1000000007

        
    def mergesort(self,A, aux, low, high):
    	if high <= low:	
    		return 0
    	mid = low + ((high - low) >> 1)
    	inversionCount = 0
    	inversionCount += self.mergesort(A, aux, low, mid)  
    	inversionCount += self.mergesort(A, aux, mid + 1, high)
    	inversionCount += self.merge(A, aux, low, mid, high)
    	return inversionCount%1000000007

    def solve(self, A):
        n=len(A)
        aux=A.copy()
        return (self.mergesort(A,aux,0,n-1))

cat=Solution()
arr=[3, 2, 1]
count=cat.solve(arr)
print("Inversion Count is:",count)
