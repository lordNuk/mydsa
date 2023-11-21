int linearSearch (int a[], int n, int t) {
	int i;
	for(i = 0; i<n; i++) 
		if (a[i] == t)
			return i;	// returns the index of target
	return -1;
}
