#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

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

int main(){
    ifstream input("input.txt");

    long accumulator = 0;

    string rangestr;
    while (getline(input, rangestr, ',') && !rangestr.empty())
    {
        // this function might be unneccary ...
        vector<string> range = parse(rangestr);// first element is low, second is high

        // all id's are valid if every id in the range has an odd number of digits
        if(range[0].length() % 2 == 1 && range[1].length() % 2 == 1){
            continue;
        }
        // check if entire range is 
        for(long i = stol(range[0]); i < stol(range[1]); i++){

            // if id has odd number of digts then it's valid
            string istr = to_string(i);
            if(istr.length() % 2 == 1){
                continue;
            }

            int strlength = istr.length();
            string lowerHalf = istr.substr(0, strlength / 2);
            string upperHalf = istr.substr(strlength / 2, strlength / 2);

            // check if num has the same halves
            if(lowerHalf == upperHalf){
                accumulator += i;
                cout << "invalid id: " << lowerHalf << upperHalf << endl;
            }
        }

    }

    cout << accumulator << endl;
    
    return 0;
}
