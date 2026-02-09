#include <fstream>
#include <string>
using namespace std; 

int main(){
    ifstream input("input.txt");

    int answer = 0;
    int dial = 1000000000 + 50;

    string line;
    while (getline(input, line) && !line.empty())
    {
        const int rotateBy = stoi(line.substr(1));
        for (int i = 0; i < rotateBy; i++)
        {
            if (line[0] == 'L')
            {
                dial -= 1;
            }
            else
            {
                dial += 1;
            }

            //printf("Rotating %c by %d, dial now at position: %d\n", line[0], 1, dial % 100);

            if ((dial % 100) == 0)
            {
                answer++;
            }
        }
    }

    printf("Answer: %d\n", answer);
}
