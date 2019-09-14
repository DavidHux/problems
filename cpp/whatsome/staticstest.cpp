#include <iostream> 
using namespace std;

int kmp(string a, string b){
    int p[] = new int[b.size()];
    p[0] = -1;
    for(int i = 1;i<b.size();i++){
        if(b[i] == b[p[i-1]+1])
            p[i] = p[i-1]+1;
        else{
            int j;
            while((j=))
        }
    }
}

int main(){
    
}