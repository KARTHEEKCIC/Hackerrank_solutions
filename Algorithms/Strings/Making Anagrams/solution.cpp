/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include<iostream>
#include<stdio.h>
#define MAX 10000
using namespace std;

int main() {
        int frequency[26];
        for(int i=0 ; i<26 ; i++)
                frequency[i]=0;
        char str1[MAX];
        cin.getline(str1,MAX);
        for(int i=0 ; str1[i]!='\0' ; i++)
                frequency[str1[i]-97]+=1;
        cin.getline(str1,MAX);
        for(int i=0 ; str1[i]!='\0' ; i++)
                frequency[str1[i]-97]-=1;
        int sum = 0;
        for(int i=0 ; i<26 ; i++) {
                if(frequency[i] < 0)
                        frequency[i]*=-1;
                sum+=frequency[i];
        }
        cout<<sum;
        return 0;
}
