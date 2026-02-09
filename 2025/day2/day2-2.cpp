#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

// parses input and outputs an array of the low value stored at range[0] and high value stored at range[1]
vector<string> parse(string rangestr){
    vector<string> range(2);   
    string low; string high; 

    //parses low number in range 
    //low = stoi(rangestr.substr(0, rangestr.find("-")));
    low = rangestr.substr(0, rangestr.find("-"));
    range[0] = low;
    //parses high number in range
    high = rangestr.substr(rangestr.find("-") + 1);
    range[1] = high;

    return range;
}

// returns true if string is made up of a repeating substring
bool repeats(string str){
    for(int i = 1; i < str.length() / 2; i++){
        string currsub = str.substr(0, i);
        /*
        string inverse = str.substr(i, str.length() - i);
        int repeats = 0;
        while( !inverse.empty()){
            string check = inverse.substr(0, i);
            inverse = inverse.substr(i, inverse.length() - i);
            if(currsub != check){
                inverse = "";
            }
            else{
                repeats = 1;   
            }
        }
        */
       cout << str.length() % i << endl;
        if (str.length() % i != 0){
            continue;
        }
        // contruct test string 
        while(currsub.length() < str.length()){
            currsub += currsub;
        }
        cout << currsub << endl;
        if(currsub == str){
            return true;
        }
    }
    return false;
}

int main(){
    ifstream input("input.txt"); // input stream

    long accumulator = 0; // output variable

    string rangestr;
    // repeat while the input is full
    while (getline(input, rangestr, ',') && !rangestr.empty())
    {
        // this function might be unneccary ...
        vector<string> range = parse(rangestr);// first element is low, second is high

        // counts the number of invalid ids in the given range
        for(long i = stol(range[0]); i < stol(range[1]); i++){
            string istr = to_string(i);

            if(repeats(istr)){
                cout << istr << endl;
                accumulator += i;
            }
        }

    }

    cout << accumulator << endl;
    
    return 0;
}
