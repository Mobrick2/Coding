#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){

   ifstream infile("wordlist.txt");

   char str[100];
   vector<string> wl;
   std::string tmp;

   while(infile) {
      infile.getline(str, 100);  // delim defaults to '\n'
      string tmp = str;
      if(infile) wl.push_back( tmp );
   }
   infile.close();
   
   int n = wl.size();
   srand(static_cast <unsigned int> (time(0)));
   int compGuess = rand() % n; //Generates number between 1 - 100

   string word = wl[compGuess];
   int m = word.size();

   int countTry = 0 , maxTry = 6, countRight = 0 ;
   char guesschar;
   vector<int> flag (m,0);

   while( countTry < maxTry && countRight != m){
	
        cin >> guesschar;

	for ( int i = 0 ; i < m; ++ i ){
	   if ( flag[i] ) cout << word[i];
	   else{
		if ( word[i] == guesschar ){
			flag[i] = 1;
			countRight ++;
			cout << guesschar;			
		}
		else{
		        cout << "_";
		}
           }
	}

	countTry++;
        cout << endl;
   }

   if ( countRight == m ) cout << "Congradulations!\n";
   else cout << "The word is '" << word << "'." << endl ;

   return 0;
}
