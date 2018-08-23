/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
void insertionSort(int ar_size, int *  ar) 
{ static int i=1;
  int key=ar[i];
  for(int k=i;k>=0;k--)
  { 
    if(k==0)
    { ar[0]=key;
      break;
    }
    if(key<ar[k-1])
      ar[k]=ar[k-1];
    else
    { ar[k]=key;
      break;
    }
  }
 
  for(int j=0;j<ar_size;j++)
    cout<<ar[j]<<" ";
  cout<<endl;
  i++;
  if(i<ar_size)
    insertionSort(ar_size,ar);

}
int main(void) {
   
    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]); 
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}

