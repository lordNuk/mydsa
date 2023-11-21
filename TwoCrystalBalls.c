// given 2 crystal balls find the minimum height to break the ball.

#include <maths.h>

optimumHeight (int height[], int n) {
	int jumpSize = pow(1/2, n);
	int i,j;
	for(i = 0; i < n; i += jumpSize) 
		if (height[i])
			break;
        for(j = i - jumpSize; j < n; j++)
		if(height[j])
			return j;
	return -1;
}         
         
