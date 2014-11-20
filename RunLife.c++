// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include "Life.h"
using namespace std;

template <typename T>
void RunLife_read (Life<T>& l, istream& r = std::cin) {
    r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    l.life_set(r);

    
}


// ----
// main
// ----

int main () {
 

    // -----------------
    // Conway Cell 21x13
    // -----------------

    cout << "*** Life<ConwayCell> 21x13 ***\n" << endl;
    Life<ConwayCell> conway1(21, 13);
    RunLife_read(conway1);
    conway1.life_print();
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    // -----------------
    // Conway Cell 20x29
    // -----------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    // ------------------
    // Conway Cell 109x69
    // ------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    return 0;}
