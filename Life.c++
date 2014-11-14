#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include "Life.h"

using namespace std;
 int main(){
 	ifstream myfile;
 // 	myfile.open("FredkinTest.txt");
 // 	Life<FredkinCell> l(myfile);
 // 	myfile.close();
	// l.life_print();
	myfile.open("ConwayTest.txt");
	Life<ConwayCell> l(myfile);
	myfile.close();
	l.life_print();

	return 0;
}
