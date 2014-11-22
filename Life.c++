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
int main() {
 ifstream myfile;
 myfile.open("FredkinTest.txt");
 Life<FredkinCell> l(20,20);
 l.life_read(myfile);
 l.update_counts();
 l.count_print(); 
 myfile.close();
 myfile.open("ConwayTest.txt");
 Life<ConwayCell> m(20, 20);
 m.life_read(myfile);
 m.update_counts();
 m.count_print();
 myfile.close();

 return 0;
}
