#include <iostream>

bool P_Triplets(int n) {
    int counter=0,i=5,j=4,k=3;
    for(i=5;i<1000;i++){
        for(j=4;j<1000;j++) {
            for(k=3;k<1000 ;k++){
                if((j+k)>i && ((j*j)+(k*k)==(i*i))){
                    if(counter!=n){
                        counter++;
                        std::cout<<k<<" "<<j<<" "<<i<<" "<<(i+j+k)<<std::endl;
                    }
                    else
                        return true;
                }
            }
        }
    }


}


int main()
{
    int num;
    std::cout << "Enter number of Triplets : ";
    std::cin>>num;
    P_Triplets(num);
    return 0;
}
