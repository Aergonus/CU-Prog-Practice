/* 
 * ACM 2010 A
 * http://acmgnyr.org/year2010/a.pdf
 * 
 * Authors: KL
 * Version: 0.1 2016/09/11
 */

#include <stdio>
#include <string>

using namespace std;

void penneyGame(int ncoins) {
	int sequences[8]; // 2^ncoins, use vector if extend
	
	int nDataSets, nDataSet, index;
	cin >> nDataSets;
	
	string input;
	
	for (int i = 0; i < nDataSets; ++i){
		memset(sequences, 0, 8); // Reset sequences array
		// fill(sequences.begin(), sequences.end(), 0); // for vector
		
		cin >> nDataSet;
		assert(i == nDataSet);
		
		cin >> input;
		for (int c = 0; c + 2 < input; ++c){
			index = (input[c] == 'H' ? 4 : 0)
				+ (input[c+1] == 'H' ? 2 : 0)
				+ (input[c+2] == 'H' ? 1 : 0);
			
			sequences[index]++;
		}
		
		cout << nDataSet;
		for (int s = 0; s < 8; ++s){
			cout << " " << sequences[s];
		}
		cout << endl;
	}
}

int main(void) {
	penneyGame(3);
	return 0;
}
