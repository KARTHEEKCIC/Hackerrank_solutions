#include<iostream>

using namespace std;

long long FIND_REPRESENTATIVE(long long sets[], long long vertex, long long &rank) {
	rank = 0;
	while(sets[vertex-1]!=vertex) {
		vertex = sets[vertex-1];
		rank++;
	}
	return vertex;
}

void JOIN_SET(long long sets[], long long v1, long long v2) {
	long long child = v1, oldparent, newparent = v2; 
	while(sets[child-1]!=child) {
		oldparent = sets[child-1];
		sets[child-1] = newparent;
		newparent = child;
		child = oldparent;
	}
	sets[child-1] = newparent;
}

int main() {
	long long q, n, m, cRoads, cLibraries;
	cin>>q;
	long long minCost[q];
	for (int i = 0; i < q; ++i)
	{
		minCost[i] = 0;
		cin>>n>>m>>cLibraries>>cRoads;
		long long v1, v2;
		if(cRoads<cLibraries) {
			long long sets[n];
			long long no_of_sets = n;
			for(int j=0 ; j<n ; j++) {
				sets[j]=j+1;
			}
			for(int j=0 ; j<m ; j++) {
				cin>>v1>>v2;	
				long long rank1, rank2;
				if(FIND_REPRESENTATIVE(sets,v1,rank1) != FIND_REPRESENTATIVE(sets,v2,rank2)) {
					if(rank1<rank2) {
						JOIN_SET(sets,v2,v1);
					} else {
						JOIN_SET(sets,v1,v2);
					}
					minCost[i]+=cRoads;
					no_of_sets--;
				}
			}
			minCost[i]+=no_of_sets*cLibraries;
		} else {
			for(int j=0 ; j<m ; j++) {
				cin>>v1>>v2;
			}
			minCost[i]+=n*cLibraries;
		}
	}
	for(int i=0 ; i<q ; i++)
		cout<<minCost[i]<<endl;
	return 0;
}
