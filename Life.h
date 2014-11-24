#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <limits>
using namespace std;

/**
 * AbstractCell is a class that contains many methods that are implemented by its children.
 */
class AbstractCell {
protected:

    /**
    * A characteristic which tells us whether the cell is dead or alive
    */
    bool _dead;
private:

    /**
    * Each cell has a count of its alive neighbors
    */
    unsigned int _neighborCount;
public:

    /**
    * Constructor for AbstractCell. We want to initiate our Cell to be dead at the beginning.
    */
    AbstractCell ();

    virtual ~AbstractCell () {}

    /**
    * virtual methods to be implemented by Conway and Fredkin. It prints the cell status.
    */
    virtual void print (std::ostream& w) const = 0;

    /**
    * Sets cell's attribute according to what is being read.
    */
    virtual char set (std::istream& input) = 0;

    /**
    * Helps Fredkin ignore angledneighbors
    */
    virtual void tryIncrementNC (bool);

    /**
    * A getter that allows Cell to see Fredkin's age
    */
    virtual unsigned int getAge () const;

    /**
    * It check neighbors ofregular cells i.e not a corner or edge cell, and 
    * increments neighbor counts
    */
    virtual string check_regulars () const = 0;

    /**
    * Checks corner cells.
    */
    virtual string check_corners (int i) const = 0;

    /**
    * Checks edge cells
    */
    virtual string check_edges (int i) const = 0;

    /**
    * Creates a new AbstractCell Object with same attributes.
    */
    virtual AbstractCell* clone () const = 0;

    /**
    * A method that kills or revives cells based
    */
    virtual int kill_revive () = 0;

    /**
    * revives the cell
    */
    virtual void revive ();

    /**
    * Getter for _dead
    */
    bool isDead ();

    /**
    * Getter for _neighborCount
    */
    unsigned int getNeighborCount ();

    /**
    * Setter for _neighborCount that only increments
    */
    void incrementNC ();

    /**
    * Resets the neighborcount
    */
    void resetNC ();
};

/**
* Cell based on Conway's rules. Inherits from AbstractCell
*/
class ConwayCell : public AbstractCell {
public:

    /**
    * Prints the symbol of the cell based on its status
    */
    void print (ostream&) const;

    /**
    * sets the status of the cell based on what it's reading.
    */
    char set (istream&);

    /**
    *  Checks the regular cells
    *
    * Neighbor spots defined by ints (X is current cell)
    *  2
    *  1 3
    * 0 X 4
    *  7 5
    *   6
    */
    string check_regulars () const;

    /**
    * Checks corner cells
    * Corner spot defined by ints:
    * 0 1
    * 2 3
    */
    string check_corners (int) const;

    /**
    * Checks edge cells
    * Edge spot defined by ints
    *    1
    *   0 2
    *    3
    */
    string check_edges (int) const;

    /**
    * Clones the cell
    */
    AbstractCell* clone () const;

    /**
    * Kills or revives the cell based on its neighbors
    */
    int kill_revive ();

    /**
    * Revives the cell
    */
    void revive ();
};

/**
* Class based on the rules of Fredkin
*/
class FredkinCell : public AbstractCell {
private:

    /**
    * Tells you the age of the cell
    */
    unsigned int _age;
public:

    /**
    * Prints the status of the cell based on whether it's dead or alive
    */
    void print (ostream&) const;

    /**
    * Sets the attributes of the cell based on what it's reading.
    */
    char set (istream&);

    /**
    * Increments its neighbor
    */
    void tryIncrementNC (bool);

    /**
    * Getter for the age
    */
    unsigned int getAge () const;

    /**
    * Checks regular cells
    * Neighbor spots defined by ints (X is current cell):
    *   2
    *  1 3
    * 0 X 4
    *  7 5
    *   6
    */
    string check_regulars () const;

    /**
    * Checks the corner cells
    * Corner spot defined by ints:
    * 0 1
    * 2 3
    */
    string check_corners (int) const;

    /**
    * Checks edge cells
    * Edge spot defined by ints
    *      1
    *     0 2
    *      3
    */
    string check_edges (int) const;

    /**
    * Clones the attributes of the cell into another cell
    */
    AbstractCell* clone () const;

    /**
    * Kills or revives the cell based on its neighbor count
    */
    int kill_revive ();
};
/**
* Cell class that it used as a wrapper for AbstractCell
*/
class Cell {
public:

    /**
    * A pointer to the original cell to manage.
    */
    AbstractCell* _p;

    /**
    * Default constructor for Cell
    */
    Cell (AbstractCell* = new FredkinCell());

    /**
    * Copy constructor of the Cell class
    */
    Cell (const Cell&);

    /**
    * Destructor for the Cell Class
    */
    ~Cell ();

    /**
    * Copy assignment for the Cell Class
    */
    Cell& operator = (const Cell&);

    /**
    * Prints the cell based on what type of Cell it's being instantiated
    */
    void print (ostream&) const;
    /**
    * Sets the cell based on what it's reading and what cell it's being instantiated
    */
    char set (istream&);

    /**
    * Checks regular Cells
    * Neighbor spots defined by ints (X is current cell):
    *    2
    *   1 3
    *  0 X 4
    *   7 5
    *    6
    */
    string check_regulars () const;

    /**
    * Check corner cells.
    * Corner spot defined by ints:
    * 0 1
    * 2 3
    */
    string check_corners (int) const;

    /**
    * Checks edge cells
    * Edge spot defined by ints
    *  1
    * 0 2
    *  3
    */
    string check_edges (int) const;

    /**
    * Tries to increment it's diangonal neighbors
    */
    void tryIncrementNC (bool);

    /**
    * Kills or revives cell based on its neighbor counts
    */
    int kill_revive ();

    /**
    * Gets neighbor count
    */
    int getNeighborCount ();
};

/**
* Class life that handles different types of cells.
*/
template <typename T>
class Life {
private:

    /**
    * Number of rows of Life board
    */
    unsigned int _rows;

    /**
    * Number of columns of Life board
    */
    unsigned int _cols;

    /**
    * The amount of alive cells in the board
    */
    unsigned int _population;

    /**
    * How many iterations of the game have been played
    */
    unsigned int _generation;

    /**
    * The board where to place the cells
    */
    vector <vector <T > > _board;
public:

    /**
    * Constructor of Life with rows and columns given
    */
    Life (unsigned int rows, unsigned int columns) :
        _rows (rows),
        _cols (columns),
        _population (0),
        _generation (0),
        _board (rows, vector<T> (columns))
        {}

    /**
    * Calls the set for the appropriate cell
    */
    void life_set (istream& r) {
        for (unsigned int i = 0; i < _rows; ++i) {
            for (unsigned int j = 0; j < _cols; ++j) {
                char c =_board[i][j].set(r);
                    if ((c >= '0' && c <= '9') || c == '*' || c == '+') {
                        _population++;
                    }
            }
        }
    }

    /**
    * Prints the board
    */
    void life_read (istream& r = cin) {
        r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        life_set(r);
        r >> ws;
    }

    /**
    * Prints the board
    */
    void life_print (ostream& w = cout) const {
        w << "Generation = " << _generation << ", Population = " << _population<< "." <<endl;
        for (unsigned int i = 0; i < _rows; i++) {
            for (unsigned int j = 0; j < _cols; j++) {
                _board[i][j].print(w);
            }
            w << endl;
        }
        w << endl;
    }

    /**
    * Given the coordinates of a live cell, updates the neighbor count
    * in the direction of "neighbor".
    */
    void update_neighbor_count (unsigned int row, unsigned int col, char neighbor) {
        assert(neighbor >= '0' && neighbor <= '7');
        if (neighbor == '0') { _board[row][col - 1].tryIncrementNC(false);}
        else if (neighbor == '1') { _board[row - 1][col - 1].tryIncrementNC(true);}
        else if (neighbor == '2') { _board[row - 1][col].tryIncrementNC(false);}
        else if (neighbor == '3') { _board[row - 1][col + 1].tryIncrementNC(true);}
        else if (neighbor == '4') { _board[row][col + 1].tryIncrementNC(false);}
        else if (neighbor == '5') { _board[row + 1][col + 1].tryIncrementNC(true);}
        else if (neighbor == '6') { _board[row + 1][col].tryIncrementNC(false);}
        else { _board[row + 1][col - 1].tryIncrementNC(true);}
    }

    /**
    * Updates the neighbor counts by going through every spot in the board and incrementing
    * corresponding neighbors to live cells (starts with corners, then does edges, then
    * internal cells to avoid checking for boundaries for every node)
    */
    void update_counts () {
        string cornerNeighborsToUpdate = "";
        string neighbor = "";
        int len = 0;
        //Update corners
        for (unsigned int i = 0; i < 2; i++) {
            for (unsigned int j = 0; j < 2; j++) {
                cornerNeighborsToUpdate = _board[(i * (_rows - 1))][(j * (_cols - 1))].check_corners((2 * i) + j);
                len = cornerNeighborsToUpdate.length();
                if (len != 0) {
                    neighbor = cornerNeighborsToUpdate;
                    int k = 0;
                    while (k < len) {
                        update_neighbor_count((i * (_rows - 1)), (j * (_cols - 1)), neighbor.at(k));
                        ++k;
                    }
                }
            }
        }
        //Update edges
        string edgeNeighborsToUpdate = "";
        for (unsigned int i = 0; i < 4; i++) {
            unsigned int j = 1;
            while ((j < _rows - 1) && (i % 2 == 0)) {
                edgeNeighborsToUpdate = _board[j][(i / 2) * (_cols - 1)].check_edges(i);
                len = edgeNeighborsToUpdate.length();
                if (len != 0) {
                    neighbor = edgeNeighborsToUpdate;
                    int k = 0;
                    while (k < len) {
                        update_neighbor_count(j, ((i / 2) * (_cols - 1)), neighbor.at(k));
                        ++k;
                    }
                }
                j++;
            }
            while ((j < _cols - 1) && (i % 2 == 1)) {
                edgeNeighborsToUpdate = _board[(i / 2) * (_rows - 1)][j].check_edges(i);
                len = edgeNeighborsToUpdate.length();
                if (len != 0) {
                    neighbor = edgeNeighborsToUpdate;
                    int k = 0;
                    while (k < len) {
                        update_neighbor_count(((i / 2) * (_rows - 1)), j, neighbor.at(k));
                        ++k;
                    }
                }
                j++;
            }
        }
        //Update everything else
        string regularNeighborsToUpdate = "";
        for (unsigned int i = 1; i < _rows - 1; i++) {
            for (unsigned int j = 1; j < _cols - 1; j++) {
                regularNeighborsToUpdate = _board[i][j].check_regulars();
                len = regularNeighborsToUpdate.length();
                if (len != 0) {
                    neighbor = regularNeighborsToUpdate;
                    int k = 0;
                    while (k < len) {
                        update_neighbor_count(i, j, neighbor.at(k));
                        ++k;
                    }
                }
            }
        }
    }

    /**
    * Kills or revives the board
    */
    void life_kill_revive() {
        for (unsigned i = 0; i < _rows; ++i) {
            for (unsigned j = 0; j < _cols; ++j) {
                _population += _board[i][j].kill_revive();
            }
        }
    }

    /**
    * Runs the game
    */
    void life_run (unsigned int generations, unsigned int interval = 1) {
        if (_generation == 0) { life_print();}
        for (unsigned int i = 1; i <= generations; ++i) {
            update_counts();
            life_kill_revive();
            _generation++;
            if (i % interval == 0) { life_print();}
        }
    }
};