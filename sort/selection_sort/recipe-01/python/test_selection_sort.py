from selection_sort import SelectionSort

def main():
    myvector = [32,71,12,45,26,80,53,33]        # 32 71 12 45 26 80 53 33

    SelectionSort(myvector)                     #(12 26 32 33 45 53 71 80)

    print("myvector contains:")
    print(myvector)

if __name__ == "__main__":
    main()
