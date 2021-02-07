from sys import stdin


def merge(arr1, M, arr2, N):
    # Your code goes here
    i = 0
    j = 0
    outSize = M+N
    output = [None for _ in range(outSize)]
    outIndex = 0

    while(i < M and j < N):
        # compare
        if(arr1[i] <= arr2[j]):
            output[outIndex] = arr1[i]
            i += 1
        else:
            output[outIndex] = arr2[j]
            j += 1
        outIndex += 1

    # Check which arr has remaining elements
    if(i < M):
        while(i < M):
            output[outIndex] = arr1[i]
            i += 1
            outIndex += 1
    else:
        while(j < N):
            output[outIndex] = arr2[j]
            j += 1
            outIndex += 1

    return output

# Driver code
# Taking Input Using Fast I/O


def takeInput():
    n = int(stdin.readline().rstrip())
    if n != 0:
        arr = list(map(int, stdin.readline().rstrip().split(" ")))
        return arr, n

    return list(), 0

# to print the array/list


def printList(arr, n):
    for i in range(n):
        print(arr[i], end=" ")

    print()


# main
t = int(stdin.readline().rstrip())

while t > 0:

    arr1, n = takeInput()
    arr2, m = takeInput()

    ans = merge(arr1, n, arr2, m)
    printList(ans, (n + m))

    t -= 1
