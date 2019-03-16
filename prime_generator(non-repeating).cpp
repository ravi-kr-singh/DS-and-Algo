#include <iostream>
#include <cmath>   //For Sqrt
#include <vector>  //For Vector
static int counter;
static std::vector <int> primes;
int prime_generator(int n) {
    counter++;
    if(counter==1) {
        int c=0,k=2,i;
        while(c!=n){
            if(k==2 || k==3 || k==5){
                if(c==n)
                    break;
                else
                    c++;
                primes.push_back(k);

            }
            else if(k>=7) {
                int m=sqrt(k);
                for(i=2;i<=m;i++) {
                    if(k%i==0)
                        break;
                }
                if(i==m+1){
                    if(c==n)
                        break;
                    else
                        c++;
                    primes.push_back(k);
                }
            }
            k++;
        }
        return primes[0];
    }
    else if(counter<=n){
        return primes[counter-1];
    }
    else{
        counter=0;
        return 0;
    }

}

int main()
{

    std::cout<<prime_generator(5)<<std::endl;  //2
    std::cout<<prime_generator(5)<<std::endl;  //3
    std::cout<<prime_generator(5)<<std::endl;  //5
    std::cout<<prime_generator(5)<<std::endl;  //7
    std::cout<<prime_generator(5)<<std::endl;  //11
    std::cout<<prime_generator(5)<<std::endl;  //0
    std::cout<<prime_generator(5)<<std::endl;  //2

    return 0;
}
