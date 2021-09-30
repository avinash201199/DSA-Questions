# Function to print all distinct triplet in the list with the given sum
def printAllTriplets(A, target):

    # sort the list in ascending order
    A.sort()

    n = len(A)

    # check if triplet is formed by `A[i]` and a pair from
    # sublist `A[i+1…n)`
    for i in range(n - 2):

        # remaining sum
        k = target - A[i]

        # maintain two indices pointing to endpoints of the
        # sublist `A[i+1…n)`
        (low, high) = (i + 1, n - 1)

        # loop if `low` is less than `high`
        while low < high:

            # increment `low` index if the total is less than the remaining sum
            if A[low] + A[high] < k:
                low = low + 1

            # decrement `high` index if the total is more than the remaining sum
            elif A[low] + A[high] > k:
                high = high - 1

            # triplet with the given sum is found
            else:
                # print the triplet
                print((A[i], A[low], A[high]))

                # increment `low` index and decrement `high` index
                low = low + 1
                high = high - 1


if __name__ == '__main__':

    A = list(map(int, input().split()))
    target = int(input())
    printAllTriplets(A, target)