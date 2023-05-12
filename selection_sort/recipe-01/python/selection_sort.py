
def SelectionSort(v):
    # index of smallest item in each pass_
    smallIndex = 0

    # save the vector size in n
    n = len(v)

    # sort v[0]..v[n-2], and arr[n-1] is in place
    for pass_ in range(n-1):
        # start the scan at index pass_; set smallIndex to pass_
        smallIndex = pass_
        # j scans the sublist v[pass_+1]..v[n-1]
        for j in range(pass_+1, n):
            # update smallIndex if smaller element is found
            if v[j] < v[smallIndex]:
                smallIndex = j
        # when finished, place smallest item in arr[pass_]
        if smallIndex != pass_:
            temp = v[pass_];
            v[pass_] = v[smallIndex];
            v[smallIndex] = temp;
