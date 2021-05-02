#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    set<char> menus;
    vector<char> menusV;
    
    for(string item : orders){
        int size = item.length();
        for(int i=0;i<size;i++){
            menus.insert(item[i]);
        }
    }
    
    for(char menu : menus){
        menusV.push_back(menu);
    }
    
    int length = menusV.size();
    
    for(int k : course){
        vector<int> getCombs;
        int maxCount = 2;
        int i=0;
        for(;i<length-k;i++)getCombs.push_back(0);
        for(;i<length;i++) getCombs.push_back(1);
        
        vector<string> tempCandis;
        
        do{
            string candidate = "";
            for(i=0;i<length;i++){
                if(getCombs[i]==1) candidate += menusV[i];
            }
            
            int count = 0;
            for(string item : orders){
                int chk=0;
                for(char a : candidate){
                    if(item.find(a)==string::npos) {chk=1;break;}
                }
                if(chk==1)continue;
                count++;
            }
            if(count>maxCount){
                maxCount = count;
                tempCandis.clear();
            }
            if(count==maxCount) tempCandis.push_back(candidate);
            
        }while(next_permutation(getCombs.begin(), getCombs.end()));
        for(string candi : tempCandis) answer.push_back(candi);
        
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}