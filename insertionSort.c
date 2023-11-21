void insertionSort (int *arr, int len) {
  for (int i = 1; i<len; i++) {
    int j = i;
    int key = arr[i];
    while(j>0 && key > arr[j-1]) {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = key; 
  }
}
