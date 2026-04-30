/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int code[] = {2, 4, 9, 3};
    int n = sizeof(code) / sizeof(code[0]);
    int k = 2;
    
    int* result = (int*)malloc(n * sizeof(int));
    
    if (k == 0) {
        for (int i = 0; i < n; i++) result[i] = 0;
    } else {
        int cnt = abs(k);
        int step = (k > 0) ? 1 : -1;
        
        // Compute the first window sum
        int sum = 0;
        for (int j = 1; j <= cnt; j++) {
            int idx = (0 + j * step) % n;
            if (idx < 0) idx += n;
            sum += code[idx];
        }
        result[0] = sum;
        
        // Slide the window
        for (int i = 1; i < n; i++) {
            // Remove element that goes out of the window from previous position
            int outIndex = (i - 1 + step) % n;
            if (outIndex < 0) outIndex += n;
            sum -= code[outIndex];
            
            // Add the new element that enters the window for current i
            int inIndex = (i + cnt * step - step) % n;
            if (inIndex < 0) inIndex += n;
            sum += code[inIndex];
            
            result[i] = sum;
        }
    }
    
    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    // Output: 13 12 5 6
    
    free(result);
    return 0;
}

*/

#include <stdio.h>

int main(){
    int n,k;
    printf("enter the n and k");
    scanf("%d%d", &n, &k);
    int code[n], result[n];
    printf("enter the code array");
    for(int i=0; i<n; i++){
        scanf("%d",&code[i]);
    }
    if(k==0){
        for(int i=0; i<n; i++){
            result[i]=0;
        }
    }    
    if(k>0){
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=1; j<=k; j++){
                sum+=code[(i+j)%n];
            }
            result[i]=sum;
        }
    }
    if(k<0){
        k=-k;
        int temp[2*n];
        for(int i=0; i<2*n; i++){
            temp[i]=code[i%n]; //circular array is stored as a linear array of size 2*n
        }
        int prefixSum[2*n+1];

        for (int i=0; i<=2*n; i++){
            prefixSum[i]=prefixSum[i-1]+temp[i];
        }
        //we got the prefix sum array of the circular array. Now we can easily calculate the sum of any k elements in O(1) time.
        for(int i=0; i<n; i++){
            int left=i+n-k;
            int right=i+n-1;

            if(left==0){
                result[i]=prefixSum[right];
            }
            else{
                result[i]=prefixSum[right]-prefixSum[left-1];
            }
        }

        /*
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=1; j<=-k; j++){
                sum+=code[(i-j+n)%n];
            }
            result[i]=sum;
        }*/
    }
    printf("result array is:");
    for(int i=0; i<n; i++){
        printf("%d ", result[i]);
    }
    return 0;
}
