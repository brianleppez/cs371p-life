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

// ----
// main
// ----

int main () {
 

    // -----------------
    // Conway Cell 21x13
    // -----------------
    {
    // cout << "*** Life<ConwayCell> 21x13 ***\n" << endl;
    Life<ConwayCell> conway1(21, 13);
    conway1.life_read();
    // conway1.life_run(12);

    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    // -----------------
    // Conway Cell 20x29
    // -----------------
    }

    {
    cout << "*** Life<ConwayCell> 20x29 ***\n" << endl;
    Life<ConwayCell> conway2(20, 29);
    conway2.life_read();
    //conway2.life_run(28, 4);
    }
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    // ------------------
    // Conway Cell 109x69
    // ------------------
    {
    cout << "*** Life<ConwayCell> 109x69 ***\n" << endl;
    Life<ConwayCell> conway3(109, 69);
    conway3.life_read();
    // conway3.life_run(9);
    // conway3.life_run(274, 274);

    // conway3.life_run(40, 40);
    // conway3.life_run(2177, 2177);
    }
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

    cout << "*** Life<FredkinCell> 20x20 ***\n" << endl;
    {
    Life<FredkinCell> fredkin1(20, 20);
    fredkin1.life_read();
    fredkin1.life_run(5);
    }
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***\n" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    return 0;}
