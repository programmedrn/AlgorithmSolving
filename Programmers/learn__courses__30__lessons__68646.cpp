#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int size = a.size();
    int index = distance(a.begin(), min_element(a.begin(), a.end()));
    
    int min = 1000000001;
    for(int i=0;i<index;i++){
        if(a[i]<min){
            answer++;
            min = a[i];
        }
    }
    min = 1000000001;
    for(int i=size-1;i>index;i--){
        if(a[i]<min){
            answer++;
            min = a[i];
        }
    }
    
    return answer+1;
}