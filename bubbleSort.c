void bubbleSort (int ar[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (ar[j] > ar[j+1]) {
				ar[j] += ar[j+1];
				ar[j+1] = ar[j] - ar[j+1];
				ar[j] = ar[j] - ar[j+1];
			}
		}
	}
}
