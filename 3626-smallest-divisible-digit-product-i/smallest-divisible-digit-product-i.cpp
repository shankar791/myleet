class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp;
        int product=1;
        for(int i=n;i<=n+10;i++){
            temp=i;
            while (i > 0) {
                product *= (i% 10);
                i/= 10;
            }
        if(product%t==0){
            return temp;
        }
        
        i=temp;
        product=1;   
    }
    return -1;
    }
};