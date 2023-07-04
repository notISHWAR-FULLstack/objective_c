


#include<stdio.h>
#include<stdlib.h>

struct dober{

long long int number;
struct dober *next;
//int position;
};typedef struct dober dob;

int main(){
    long long int input;
    scanf("%lld",&input);
    long long int input2;
    scanf("%lld",&input2);
    dob *start=NULL;
    dob *end=NULL;
    //int pos=0;
    for(long long int i = 0 ; i<input;++i){
            long long int temp;
            dob *tomp;
            tomp=(dob*)malloc(sizeof(dob));
            scanf("%lld",&temp);
        if( i== 0 ){
            start=tomp;
            start->number=temp;
            start->next=NULL;
            //start->position=pos;
            end=start;
            //pos+=1;
        }
        else{
            if(end->number==temp){
                continue;
            }
            else{
                end->next=tomp;
                end = tomp;
                end->number=temp;
                end->next=NULL;
                //end->position=pos;
            }
        }
    }

    //#################################################################################################################################//


    for(long long int i=0 ; i< input2;++i){
        long long int temp;
        scanf("%lld",&temp);
        dob *tomp;
        dob *tomp2=start;
        if(start->number<temp){
            tomp=(dob*)malloc(sizeof(dob));
            tomp->number=temp;
            tomp->next=start;
            start=tomp;
        }
        else if(end->number>temp){
            tomp=(dob*)malloc(sizeof(dob));
            tomp->number=temp;
            end->next=tomp;
            tomp->next=NULL;
            end=tomp;
        }
        else{
            while(tomp2 != NULL){
                if(tomp2->number > temp && tomp2->next->number<temp){
                    tomp= (dob*)malloc(sizeof(dob));
                    tomp->next=tomp2->next;
                    tomp2->next=tomp;
                    tomp->number=temp;
                }

                tomp2=tomp2->next;
            }

        }
        dob *duke=start;
        for(long long int z=1;;++z){
            if(duke == NULL)
                break;
            else{
                if(duke->number==temp)
                    printf("%lld\n",z);
            }
            duke=duke->next;
        }


    }


return 0;
}

