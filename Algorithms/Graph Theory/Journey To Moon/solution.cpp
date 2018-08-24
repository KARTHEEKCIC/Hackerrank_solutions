#include<iostream>

using namespace std;

long long FIND_SET(long sets[], long long vertex) {
	while(sets[vertex] >= 0) {
		vertex = sets[vertex];
	}
	return vertex;
}

void JOIN_SETS(long sets[], long long v1, long long v2) {
	sets[v1]+=sets[v2];
	sets[v2] = v1;
}

void REMOVE_ELEMENT(long setIndex[], int index, long &length) {
	for(int i=index ; i<length-1 ; i++) {
		setIndex[i] = setIndex[i+1];
	}
    length--;
}

int main() {
	long long n, p, count = 0;
	cin>>n>>p;
	long sets[n];
    long setIndex[n];
    long length1 = 0;
	for(int i=0 ; i<n ; i++) {
		sets[i] = -1;
	}
	long long v1, v2;
	for(int i=0 ; i<p ; i++) {
		cin>>v1>>v2;
		long long r1, r2;
		r1 = FIND_SET(sets,v1);
		r2 = FIND_SET(sets,v2);
        if(r1!=r2) {
        int flag = 0, index, flag1 = 0, index1;
		  JOIN_SETS(sets,r1,r2);
          for(int k=0 ; k<length1 ; k++) {
            if(setIndex[k] == r2){
                flag++;
                index = k;
            }
            if(setIndex[k] == r1) {
            	flag1++;
            	index1 = k;
            } 
            if(flag && flag1) {
            	break;
            }
          }  
            if(flag && flag1){
               	REMOVE_ELEMENT(setIndex,index,length1);
            } else if(flag) {
            	setIndex[index] = r1;
            } else if(flag1 == 0) {
                setIndex[length1++] = r1;  
            }
          }
	}
    int sum = 0;
    for(int i=0 ; i<length1-1 ; i++) {
        sum+=sets[setIndex[i]]*(-1);
        for(int j=i+1 ; j<length1 ; j++) {
            count+=sets[setIndex[i]]*sets[setIndex[j]];
        }
    }
    sum+=sets[setIndex[length1-1]]*(-1);
    for(int i=0 ; i<length1 ; i++) {
		count+=sets[setIndex[i]]*(n-sum)*(-1);
	}
	count+=(n-sum)*(n-sum-1)/2;
	cout<<count;
	return 0;
}
