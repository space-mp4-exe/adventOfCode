#include <iostream>
#include <fstream>
#include <string>
using namespace std; 


int main(){
    ifstream input("input.txt");
    long accumulator; //holds results
    string line;//holds input 
    //separates input into each line
    while(getline(input, line)){
        string max_num = "";
        for(int i = 0; i < line.size(); i++){
            char max_digit = '0';
            int max_index = -1;
            //finds the highest digit in the range. Leaves space so that there are enought digts to at to the highest number
            for(int j = i; j < line.size() - 11 + max_num.size() && max_num.size() < 12; j++){
                if(line[j] > max_digit){
                    max_digit = line[j];
                    max_index = j;
                }
                i = max_index;
            }
            if(max_index != -1) max_num += line[max_index]; //checks if new digit was found
        }

        cout << "max_num: " << max_num << endl;
        char* ptr;
        accumulator += strtol(max_num.c_str(), &ptr, 10);
    }
    cout << accumulator << endl;//outputs result
    return 0;
}
