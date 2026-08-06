class Solution {
public:
 
   int Product(int num){
    int prod=1;
    while(num>0){
        prod*=(num%10);
        num/=10;
    }
    return prod;
   }
    int smallestNumber(int n, int t) {
        
        while(true){
            if(Product(n)%t==0)
                return n;
            
            n++;
        }
    
    }
};