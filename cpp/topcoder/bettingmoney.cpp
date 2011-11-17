#include "bettingmoney.h"
#include <iostream>

using namespace std;



int BettingMoney::moneyMade(int *amounts, int *centsPerDollar, int finalResult)
{
    int profit = 0;
    int loss = 0;
    int net = 0;
    int numelements = sizeof(amounts)/sizeof(int);
    cout<<numelements<<endl;
    int count;
    for (count = 0; count<numelements; count++){
        if(count==finalResult){
            continue;
        }
        else{
            cout<<amounts[count]<<endl;
            profit += amounts[count]*100;
        }
    }

    loss = amounts[finalResult]*( 100 + centsPerDollar[finalResult] );
    cout<<profit<<endl<<loss<<endl;
    net = profit - loss;
    return net;
}



int main(){

    BettingMoney bm;
    int result;
    int amounts[] = {10, 20, 30};
    int centsperdollar[] = {20, 30, 40};
    int dresult = 1;
    result = bm.moneyMade(amounts, centsperdollar, dresult);
    //({10, 20, 30}, {20, 30, 40}, 1);
    cout<<result<<endl;
    return 0;
}
