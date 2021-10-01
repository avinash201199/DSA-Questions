'''
@Author 28Pollux28
In order to calculate the largest rectangle position and area in the matrix, we will first transform the matrix into an
array of histogram (where each number tells how many consecutive zeros (the zero of the row is included) are above the
 number we are looking at). For example, the matrix :
[[0,1,0,1],
[1,1,0,0],
[0,0,1,0],
[1,1,1,0]]
becomes :
[[1,0,1,0],
[0,0,2,1]
[1,1,0,2],
[0,0,0,3]]

Then for each histogram, we will calculate what I called L and R :
L represent the minimum index i such as 0<=i<=x and histogram[j]>=histogram[x] for j such as i<=j<=x
The same process goes for R
The idea is to calculate for each index x the width of the rectangle of height histogram[x]. This is given by :
width = D[x]-G[x]+1
Then width*histogram[x] gives the area of the rectangle.
By iterating on the whole matrix, we can find the largest rectangle.

As for complexity, the create_histogram_tab is a O(n^2), and the largest_rectangle_histogram is a O(n),
giving us an optimal complexity of O(n^2)
'''

import numpy as np

n = 8


def main():
    # Construction of the matrix
    matrix = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            matrix[i, j] = np.random.randint(0, 2)

    max_area, bottomX, bottomY, width, height = all_zeros_rectangle(matrix)
    print("The bottom-left corner of the largest rectangle is at (" + str(int(bottomX)) + "," + str(int(bottomY)) + ")")
    print("It is " + str(int(width)) + " wide and " + str(int(height)) + " high for a total area of " + str(
        int(max_area)))


def create_histogram_tab(matrix):  # O(n^2)
    col = np.zeros((n, n))
    for y in range(n):
        c = 0
        for x in range(n):
            if matrix[x, y] != 0:
                c = 0
            else:
                c += 1
            col[x, y] = c
    return col


def all_zeros_rectangle(matrix):
    max_area = 0
    column = create_histogram_tab(matrix)  # O(n^2)
    rectX = 0
    rectY = 0
    rectDX = 0
    rectDY = 0
    for y in range(n):
        histo = [column[y, x] for x in range(n)]
        area, rectx, rectdx, rectdy = largest_rectangle_histogram(histo)  # O(n)
        if area > max_area:
            max_area = area
            rectX = rectx
            rectY = y
            rectDX = rectdx
            rectDY = rectdy
    return max_area, rectX, rectY, rectDX, rectDY


def calculateL(histogram):
    L = []
    for x in range(n):
        i = x - 1
        while i >= 0 and histogram[i] >= histogram[x]:
            i = L[i] - 1
        L.append(i + 1)
    return L


def calculateR(histogram):
    R = []
    for x in range(n - 1, -1, -1):
        i = x + 1
        while i <= n - 1 and histogram[i] >= histogram[x]:
            i = R[n - 1 - i] + 1
        R.append(i - 1)
    # swap order of R
    R.reverse()
    return R


def largest_rectangle_histogram(histo):
    L = calculateL(histo)  # O(n)
    R = calculateR(histo)  # O(n)
    max_area = 0
    xRect = 0
    dx = 0
    dy = 0
    for x in range(n):
        x_ = R[x] - L[x] + 1
        histo_x_ = histo[x]
        area = histo_x_ * (x_)
        if area > max_area:
            max_area = area
            xRect = L[x]
            dx = x_
            dy = histo_x_

    return max_area, xRect, dx, dy


if __name__ == '__main__':
    n = int(input("Enter matrix size :"))
    main()
