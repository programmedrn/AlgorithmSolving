#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int getParent(vector<int> tree, int a){
    if(tree[a]==a) return a;
    return getParent(tree, tree[a]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> reached(n);
    
    sort(costs.begin(), costs.end(), comp);
    
    int size = costs.size();
    
    for(int i=0;i<n;i++){
        reached[i]=i;
    }
    
    for(int i=0;i<size;i++){
        int a = getParent(reached, costs[i][0]);
        int b = getParent(reached, costs[i][1]);
        
        if(a!=b){
            answer+=costs[i][2];
            int term = (a>b)?a:b;
            reached[a] = reached[b] = term;
        }
        
    }
    
    return answer;
}