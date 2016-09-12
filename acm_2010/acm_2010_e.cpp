// Name : Brenda So
// Date : 09-11-2016
// Description : A dynamic programming solution to ACM 2010 problem 
// BUG REPORT : integer overflow for 40, 41 etc. 


#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(){

    ifstream in_file;
    ofstream of_file;

    int num_of_tests;
    in_file.open("e.in");
    of_file.open("e.out");
    in_file >> num_of_tests;
    map<int, int> start_mapping;
    map<int, int> new_mapping;
    int test_number;
    int num_of_digits;
    unsigned int result;

    start_mapping[0] = 10;
    start_mapping[1] = 9;
    start_mapping[2] = 8;
    start_mapping[3] = 7;
    start_mapping[4] = 6;
    start_mapping[5] = 5;
    start_mapping[6] = 4;
    start_mapping[7] = 3;
    start_mapping[8] = 2;
    start_mapping[9] = 1;
    
    for (int i = 0 ; i < num_of_tests; i++){
        in_file >> test_number;
        in_file >> num_of_digits;
        
        if (num_of_digits == 1){
            result = 9;
        }else{
            // update the numbers with dynamic programming
            new_mapping = start_mapping;
            result = 0;
            while (num_of_digits != 1){
            
                for (int j = 8; j >= 0 ; j--){
                    new_mapping[j] = new_mapping[j] + new_mapping[j+1];
                }

                num_of_digits -= 1;
            }

            for (int j = 0 ; j <= 9; j++){
                result += new_mapping[j];
            }
        }
            of_file << test_number << " " << result << endl;
    }

    in_file.close();
    of_file.close();

    return 0;
}
