/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    if(time[8]=='A')
    {  if(time[0]=='1' && time[1]=='2')
      { time[0]='0';
        time[1]='0';
      }
    }
    else if(time[1]=='8')
         {
            time[0]='1';
            time[1]='1';
         }
         else if(time[1]=='9')
              {
                    time[0]='1';
                    time[1]='2';
              }
              else if(time[0]!='1' || time[1]!='2') 
                   {
                      time[0]+=1;
                      time[1]+=2;
                   }
    for(int i=0 ;i<8;i++)
      cout<<time[i];
    return 0;
}

