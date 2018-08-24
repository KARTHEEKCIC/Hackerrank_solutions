#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// function to fetch the nodes with minimum key value and not in the mst set
int min(int arr[], int n, bool arr1[]) {
    int min = 100001;
    int min_index = -1;
    for(int i=0 ; i<n ; i++) {
        if(arr[i]<min && arr1[i] == false) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    int mstSet_count = 0;
    int total_weight = 0;
    int arr[n];
    bool arr_mst[n] = {};
    // initializing every element with maximum value
    for(int i=0 ; i<n ; i++) {
        arr[i] = 100001;
        arr_mst[i] = false;
    }
    arr[start-1] = 0;
    while(mstSet_count!=n) {
        int index = min(arr,n,arr_mst);
        cout<<index+1<<endl;
        if(index != -1) {
            // adding the node to the MST
            mstSet_count++;
            // marking it as added
            arr_mst[index] = true;
            // adding the weight of the edge in the tree
            cout<<" "<<arr[index];
            total_weight+=arr[index]; 
            // updating the weights
            for(int i=0 ; i<edges.size() ; i++) {
                if(edges[i][0] == index+1){
                    // updating the adjacent vertices weights
                    if(arr[edges[i][1]-1] > edges[i][2]) {
                        arr[edges[i][1]-1] = edges[i][2];
                    }
                } else if(edges[i][1] == index+1) {
                    // updating the adjacent vertices weights
                    if(arr[edges[i][0]-1] > edges[i][2]) {
                        arr[edges[i][0]-1] = edges[i][2];
                    }
                }
            }
        }
    }
    return total_weight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

