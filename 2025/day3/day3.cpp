#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

//Brute force solution
int main(){
    ifstream input("input.txt");
    int accumulator; // holds results
    string line;
    while(getline(input, line)){
        int max_num = 0;
        for(int i = 0; i < line.size(); i++){
            for(int j = i + 1; j < line.size(); j++){
                char* ptr;
                string num = line.substr(i, 1) + line.substr(j,1);
                int curr = strtol(num.c_str(), &ptr, 10);
                if(curr > max_num){
                    max_num = curr;
                }
            }
        }
        cout << "max_num: " << max_num << endl;
        accumulator += max_num;
    }
    cout << accumulator << endl;
    return 0;
}
