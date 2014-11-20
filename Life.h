#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>

#include "Handle.h"

using namespace std;

//AbstractCell class
class AbstractCell {
	protected:
		bool _dead;
    private:
		int _neighborCount;
	public:
		// Default constructor given for free.

		virtual void print(std::ostream& w) const = 0;

        virtual char set(std::istream& input) = 0;

        int getNeighborCount () { return _neighborCount; }

        void incrementNC () { _neighborCount++; }

        void resetNC () { _neighborCount = 0; }
		
		// evolve = 0; foce conway and fredkin to define.
};

//Cell class
struct Cell : Handle<AbstractCell> {
    Cell (AbstractCell* p) : 
            Handle<AbstractCell> (p)
        {
            p = new FredkinCell();
        }
    void print(ostream& w) const {
        return get()->print(w);
    }
    char set(std::istream& input){
        return get()->set(input);
    }
    string check_regulars() const {
        return get()->check_regulars();
    }
    string check_corners() const {
        return get()->check_corners();
    }
    string check_edges() const {
        return get()->check_edges();
    }
    int kill_revive() {
        return get()->kill_revive();
    }
    void change_types() {
        Cell c = new ConwayCell();
        swap(c);
    }

    void evolve(){
        p = new ConwayCell();
    }


//ConwayCell class
class ConwayCell : public AbstractCell {
	
	public:
		ConwayCell() {}
		void print(ostream& w) const {
			if(_dead){
				w<<".";
			}
			else{
				w<<"*";
			}
			
		}
		char set(std::istream& input){
			char c;
			input>>c;
			if (c == '.'){
				_dead = true;
			}
			else if (c == '*'){
				_dead = false;;
			}
			else {
				cout<<"Bad input for ConwayCell";
				assert(false);
			}
            return c;
        }
        /*Neighbor spots defined by ints (X is current cell):
           2
          1 3
         0 X 4
          7 5
           6
         */
        string check_regulars() const {
            if (_dead) {
                return "";
            }
            else {
                return "01234567";
            }
        }
        string check_corners(int i) const {
            /*Corner spot defined by ints:
             0 1
             2 3
             */
            if (_dead) {
                return "";
            }
            else {
                if (i == 0) {
                    return "456";
                }
                else if (i == 1){
                    return "670";
                }
                else if (i == 2){
                    return "234";
                }
                else if (i == 3){
                    return "012";
                }
                else{
                    cout<<"update count corner i is not 0 - 3";
                    assert(false);
                }
            }
        }


        string check_edges(int i) const {
            /*Edge spot defined by ints
              1
             0 2
              3
             */
            if (_dead) {
                return "";
            }
            else {
                if (i == 0) {
                    return "23456";
                }
                else if (i == 1){
                    return "45670";
                }
                else if (i == 2){
                    return "67012";
                }
                else if (i == 3){
                    return "01234";
                }
                else{
                    cout<<"update count edge i is not 0 - 3";
                    assert(false);
                }
            }
        }

        int kill_revive() {
            int v = 0;
            if (_dead) {
                if (getNeighborCount() == 3) {
                    _dead = false;
                    v = 1;
                }
            }
            else {
                if (getNeighborCount() != 2 && getNeighborCount() != 3) {
                    _dead = true;
                    v = -1;
                }
            }
            resetNC();
            return v;
        }
};

//FredkinCell class
class FredkinCell : public AbstractCell {
	private:
		unsigned int _age;
	public:
		void print(ostream& w) const{
			if(_dead){
				w << "-";
			}
			else if (_age > 9){
				w << "+";
			}
			else{
				w << _age;
			}
		}
		char set(std::istream& input){
			char c;
			input >> c;
			if (c == '-'){
				_dead = true;
				_age = 0;
			}
			else if (c >= '0' && c <= '9') {
				_dead = false;
				_age = c - '0';
			}
			else if (c == '+'){
				_dead = false;
				_age = 10;
			}
			else {
				cout<<"Bad input for FredkinCell";
				assert(false);
			}
            return c;
        }
        /*Neighbor spots defined by ints (X is current cell):
           2
          1 3
         0 X 4
          7 5
           6
         */
        string check_regulars() const{
            if (_dead) {
                return "";
            }
            else {
                return "0246";
            }
        }
        string check_corners(int i) const{
            /*Corner spot defined by ints:
             0 1
             2 3
             */
            if (_dead) {
                return "";
            }
            else {
                if (i == 0) {
                    return "46";
                }
                else if (i == 1){
                    return "60";
                }
                else if (i == 2){
                    return "24";
                }
                else if (i == 3){
                    return "02";
                }
                else{
                    cout<<"update count corner i is not 0 - 3";
                    assert(false);
                }
            }
        }
        string check_edges(int i) const{
            /*Edge spot defined by ints
              1
             0 2
              3
             */
            if (_dead) {
                return "";
            }
            else {
                if (i == 0) {
                    return "246";
                }
                else if (i == 1){
                    return "460";
                }
                else if (i == 2){
                    return "602";
                }
                else if (i == 3){
                    return "024";
                }
                else{
                    cout<<"update count corner i is not 0 - 3";
                    assert(false);
                }
            }
        }

        int kill_revive() {
            int v = 0;
            if (_dead) {
                if (getNeighborCount() == 3 || getNeighborCount() == 1) {
                    _dead = false;
                    v = 1;
                }

            }
            else {
                if (getNeighborCount() == 2 || getNeighborCount() == 0 || getNeighborCount() == 4) {
                    _dead = true;
                    v = -1;
                }
                else {
                    _age++;
                }
            }
            resetNC();
            return v;
        }
};

//Life class
template <typename T>
class Life{
    private:
        unsigned int _rows;
        unsigned int _cols;
		unsigned int _population;
		unsigned int _generation;
        vector<vector<T > > _board;
        vector<vector<unsigned int > > _neighborCount;
	public:
		Life(unsigned int rows, unsigned int columns) : 

            _rows(rows),
            _cols(columns),
            _population(0),
            _generation(0),
			_board(rows, vector<T>(columns)) 
			{}


        void life_set(std::istream& r = std::cin) {
            for (unsigned int i = 0; i < _rows; ++i) {
                for (unsigned int j = 0; j < _cols; ++j) {
                    char c =_board[i][j].set(r);
                    if ((c >= '0' && c <= '9') || c == '*' || c == '+') {
                        _population++;
                    }
                }
            }
        }

        void life_read (istream& r = std::cin) {
            r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            life_set(r);
            r >> ws;
        }

		void life_print(std::ostream& w = std::cout) const {
			w<<"Generation = "<<_generation<<", Population = "<<_population<<"."<<endl;
			for (unsigned int i = 0; i < _rows; i++){
				for (unsigned int j = 0; j < _cols; j++){
					_board[i][j].print(w);
				}
				w<<endl;
			}
			w<<endl;
        }


       /* void count_print(std::ostream& w = std::cout){
            //prints the _neighborCount matrix
            for (int i = 0; i < _rows; i++){
                for (int j = 0; j < _cols; j++){
                    w<< _board[i][j].getNeighborCount();
                }
                w<<endl;
            }
            w<<endl;
        }
*/
        void update_neighbor_count(int row, int col, char neighbor){
            //Given the coordinates of a live cell, updates the neighbor count
            //in the direction of "neighbor".
            if (neighbor == '0') {
                _board[row][col - 1].incrementNC();
            }
            else if (neighbor == '1') {
                _board[row - 1][col - 1].incrementNC();
            }
            else if (neighbor == '2') {
                _board[row - 1][col].incrementNC();
            }
            else if (neighbor == '3') {
                _board[row - 1][col + 1].incrementNC();
            }
            else if (neighbor == '4') {
                _board[row][col + 1].incrementNC();
            }
            else if (neighbor == '5') {
                _board[row + 1][col + 1].incrementNC();
            }
            else if (neighbor == '6') {
                _board[row + 1][col].incrementNC();
            }
            else if (neighbor == '7') {
                _board[row + 1][col - 1].incrementNC();
            }
            
        }


        void update_counts(){
            //Updates the neighbor counts by going through every spot in the board and incrementing
            //corresponding neighbors to live cells (starts with corners, then does edges, then
            //internal cells to avoid checking for boundaries for every node)
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

        void life_kill_revive() {
            for (unsigned i = 0; i < _rows; ++i) {
                for (unsigned j = 0; j < _cols; ++j) {
                    _population += _board[i][j].kill_revive();

                }
            }
        }

        void life_run (unsigned int generations, unsigned int interval = 1) {
            if (_generation == 0) {
                life_print();
            }
            for (unsigned int i = 1; i <= generations; ++i) {
                update_counts();
                life_kill_revive();
                _generation++;
                if (i % interval == 0) {
                    life_print();
                }

            }
        }
        
};



