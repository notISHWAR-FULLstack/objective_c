/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<iostream>
using namespace std;
int main(int argc, char *a[])
{
    //Write code here
    long long m,n;
    cin>>m>>n;
    long long arr[m+n];
    long long count=0;
    long long last;
    for(long long i=0;i<m;++i){
        long long input;
        cin>>input;
        if(i==0){
            last=input;
            arr[count] = input;
            count+=1;
        }
        else{
            if(input!=last){
                last=input;
                arr[count] = input;
                count+=1;
            }
        }

    }
    for(long long j=0;j<n;++j){
        long long input;
        cin>>input;
        bool found=false;
        for(long long l=0;l<count;++l){
            //bool found=false;
            if(arr[l]==input){
                cout<<l+1<<endl;
                found=true;
                break;
            }
            else if(arr[l]<input){
                count+=1;
                for(long long f=count;f>l;--f){
                    arr[f] = arr[f-1];
                }
                arr[l] = input;
                cout<<l+1<<endl;
                found=true;
                break;
            }
        }
        if(found == false){
            //cout<<"kk";
            arr[count] = input;
            cout<<count+1<<endl;
            count+=1;
        }
    }
}
