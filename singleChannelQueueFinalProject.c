#include<stdio.h>
void main(){

 int i;
 int customer[10]={1,2,3,4,5,6,7,8,9,10};
 int timeSinceLastArrival[10];
 int arrivalTime[10];
 int serviceTime[10];
 int startServiceTime[10];
 int waitInQueue[10];
 int endServiceTime[10];
 int timeSpendInSystem[10];
 int idleTime[10];
 int randomDigitForCustomer[10];
 int randomDigitForService[10];

 timeSinceLastArrival[0]=0;
 printf("enter random digit to obtain the corresponding time between arrivals\n");

 for(i=1;i<10;i++){
        scanf("%d",&randomDigitForCustomer[i]);
 }

 for(i=1;i<10;i++){

       if((randomDigitForCustomer[i]>=1)&&(randomDigitForCustomer[i]<=125))
        timeSinceLastArrival[i]=1;

       else if((randomDigitForCustomer[i]>=126)&&(randomDigitForCustomer[i]<=250))
        timeSinceLastArrival[i]=2;

       else if((randomDigitForCustomer[i]>=251)&&(randomDigitForCustomer[i]<=375))
        timeSinceLastArrival[i]=3;


        else if((randomDigitForCustomer[i]>=376)&&(randomDigitForCustomer[i]<=500))
        timeSinceLastArrival[i]=4;

        else if((randomDigitForCustomer[i]>=501)&&(randomDigitForCustomer[i]<=625))
        timeSinceLastArrival[i]=5;

        else if((randomDigitForCustomer[i]>=626)&&(randomDigitForCustomer[i]<=750))
        timeSinceLastArrival[i]=6;

         else if((randomDigitForCustomer[i]>=751)&&(randomDigitForCustomer[i]<=875))
        timeSinceLastArrival[i]=7;

         else if(randomDigitForCustomer[i]>=876)
                  timeSinceLastArrival[i]=8;

         else
          timeSinceLastArrival[i]=8;

     }

arrivalTime[0]=0;
        for(i=1;i<10;i++){
            arrivalTime[i]=timeSinceLastArrival[i]+arrivalTime[i-1];
            }



printf("\nenter random digit to obtain the corresponding service time \n");

for(i=0;i<10;i++){
        scanf("%d",&randomDigitForService[i]);
 }
  printf("\n\n");


 for(i=0;i<10;i++){

    if((randomDigitForService[i]>=1)&&(randomDigitForService[i]<=10))
        serviceTime[i]=1;

    else if((randomDigitForService[i]>=11)&&(randomDigitForService[i]<=30))
         serviceTime[i]=2;

    else if((randomDigitForService[i]>=31)&&(randomDigitForService[i]<=60))
         serviceTime[i]=3;

    else if((randomDigitForService[i]>=61)&&(randomDigitForService[i]<=85))
         serviceTime[i]=4;

    else if((randomDigitForService[i]>=86)&&(randomDigitForService[i]<=95))
         serviceTime[i]=5;

    else if(randomDigitForService[i]>=96)
                   serviceTime[i]=6;

    else
           serviceTime[i]=6;

     }


//for(i=0;i<10;i++){
//printf("%d\t %d \t %d\n",timeSinceLastArrival[i],arrivalTime[i],serviceTime[i]);
 //}

//printf("somethig here before \n");

 startServiceTime[0]=0;
 waitInQueue[0]=0;
 endServiceTime[0]=serviceTime[0]+startServiceTime[0];
 idleTime[0]=0;
 timeSpendInSystem[0]=serviceTime[0]+ waitInQueue[0];

            for(i=1;i<10;i++){

                    if(arrivalTime[i]>endServiceTime[i-1]){

                        startServiceTime[i]=arrivalTime[i];
                        endServiceTime[i]=startServiceTime[i]+serviceTime[i];
                        waitInQueue[i]=startServiceTime[i]-arrivalTime[i];
                        timeSpendInSystem[i]=serviceTime[i]+waitInQueue[i];
                        idleTime[i]=startServiceTime[i]-endServiceTime[i-1];

                        }
                        else{
                            startServiceTime[i]=endServiceTime[i-1];
                            endServiceTime[i]=startServiceTime[i]+serviceTime[i];
                            waitInQueue[i]=startServiceTime[i]-arrivalTime[i];
                            timeSpendInSystem[i]=serviceTime[i]+waitInQueue[i];
                            idleTime[i]=startServiceTime[i]-endServiceTime[i-1];
                            }

            }

printf("customer TSLA ArrivalT ServiceT TSB WInQueue EServiceT TTinSystem idleTime\n\n");
printf("---------------------------------------------------------------------------\n");

            for(i=0;i<10;i++){
                printf("%d\t %d \t %d \t %d \t %d\t %d\t %d\t %d\t\t %d\n\n",customer[i],timeSinceLastArrival[i],arrivalTime[i],
                       serviceTime[i], startServiceTime[i],waitInQueue[i],endServiceTime[i],timeSpendInSystem[i],idleTime[i]);
                    }

    int totalSrviceTime=0;
    int totalTimeBetweenArrival=0;
    int totalTimeWaitInQueue=0;
    int totalTimeSpendInSystem=0;
    int totalIdleTimeInSystem=0;



        for(i=0;i<10;i++){
            totalSrviceTime=totalSrviceTime+serviceTime[i];
            totalTimeBetweenArrival=totalTimeBetweenArrival+timeSinceLastArrival[i];
            totalTimeWaitInQueue=totalTimeWaitInQueue+waitInQueue[i];
            totalTimeSpendInSystem=totalTimeSpendInSystem+timeSpendInSystem[i];
            totalIdleTimeInSystem=totalIdleTimeInSystem+idleTime[i];
        }

printf("---------------------------------------------------------------------------\n");
printf(" total : %d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\n\n ",totalTimeBetweenArrival,totalSrviceTime,totalTimeWaitInQueue
       , totalTimeSpendInSystem,totalIdleTimeInSystem);
float averageWaitingTime;
float averageTimeBetweenArrival;
float probabilityOfCustomerWaiting;
float probabilityOfIdleServer;
float probabilityOfServerBusy;
float avgTimeCustomerSpendInSystem;

    int totalNumberWait=0;
    for(i=1;i<10;i++){
        if(waitInQueue[i]>0){
            totalNumberWait=totalNumberWait+1;
        }
    }

averageWaitingTime=(float)totalTimeWaitInQueue/10;
averageTimeBetweenArrival=(float)totalTimeBetweenArrival/9;
probabilityOfIdleServer=(float)totalIdleTimeInSystem/endServiceTime[9];
probabilityOfServerBusy=(float)1-probabilityOfIdleServer;
probabilityOfCustomerWaiting=(float)totalNumberWait/10;
avgTimeCustomerSpendInSystem=(float)totalTimeSpendInSystem/10;

printf("      a) average Waiting Time = %f \n\n",averageWaitingTime);
printf("      b) average Time Between Arrival = %f\n\n",averageTimeBetweenArrival);
printf("      c) probability Of Customer Waiting = %f \n\n",probabilityOfCustomerWaiting);
printf("      d) probability Of ServerBusy = %f \n\n",probabilityOfServerBusy);
printf("      e) average Time Customer Spend In System = %f \n\n",avgTimeCustomerSpendInSystem);


}

