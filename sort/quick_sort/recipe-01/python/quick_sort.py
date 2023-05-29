
def pivot_index(v, first, last):
    # index for the midpoint of [first,last) and the
    # indices that scan the index range in tandem

    if first == last:
        return last
    elif first == last-1:
        return first
    else:
        mid = (last + first)//2;
        pivot = v[mid];

        # exchange the pivot and the low end of the range
        # and initialize the indices scanUp and scanDown.
        v[mid] = v[first];
        v[first] = pivot;

        scanUp = first + 1;
        scanDown = last - 1;

        # manage the indices to locate elements that are in
        # the wrong sublist; stop when scanDown <= scanUp
        while True:
            # move up lower sublist; stop when scanUp enters
            # upper sublist or identifies an element >= pivot
            while (scanUp <= scanDown and v[scanUp] < pivot):
                scanUp += 1

            # scan down upper sublist; stop when scanDown locates
            # an element <= pivot; we guarantee we stop at arr[first]
            while (pivot < v[scanDown]):
                scanDown -= 1

            # if indices are not in their sublists, partition complete
            if (scanUp >= scanDown):
                break

            # indices are still in their sublists and identify
            # two elements in wrong sublists. exchange
            temp = v[scanUp]
            v[scanUp] = v[scanDown]
            v[scanDown] = temp

            scanUp += 1
            scanDown -= 1

        # copy pivot to index (scanDown) that partitions sublists
        # and return scanDown
        v[first] = v[scanDown]
        v[scanDown] = pivot
        return scanDown

def quick_sort(v, first, last):
    # if the range is not at least two elements, return
    if (last - first <= 1):
        return

    # if sublist has two elements, compare v[first] and
    # v[last-1] and exchange if necessary
    elif (last - first == 2):
        if (v[last-1] < v[first]):
            temp = v[last-1]
            v[last-1] = v[first]
            v[first] = temp
        return
    else:
        pivotLoc = pivot_index(v, first, last)

        # make the recursive call
        quick_sort(v, first, pivotLoc)

        # make the recursive call
        quick_sort(v, pivotLoc +1, last)

# sort a vector of type T using quick sort
def QuickSort(v): 
    quick_sort(v, 0, len(v))

