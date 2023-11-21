int binarySearch(int ar[], int lo, int hi, int target) {
	int mid;
	while(lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (ar[mid] == t) 
			return mid;
		if(ar[mid] > target)
			hi = mid;
		else
			lo = mid+1;
	}
	return -1;
}
