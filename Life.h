#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

//AbstractCell class
class AbstractCell{
	protected:
		bool _dead;
	public:
		AbstractCell() : _dead(true) {}

		virtual void print(ostream& w) = 0;

		bool is_dead () const { return _dead;}
		
		// evolve = 0; foce conway and fredkin to define.
};

//Cell class
class Cell {
	AbstractCell* p;
};


//ConwayCell class
class ConwayCell : public AbstractCell{
	
	public:
		void print(ostream& w) const{
			if(_dead){
				w<<".";
			}
			else{
				w<<"*";
			}
			
		}
		void set(std::istream& input){
			char c;
			input>>c;
			if (c == '.'){
				_dead = true;
			}
			else if (c == '*'){
				_dead = false;
			}
			else {
				cout<<"Bad input for ConwayCell";
				assert(false);
			}
		}
};

//FredkinCell class
class FredkinCell : public AbstractCell{
	private:
		unsigned int _age;
	public:
		void print(ostream& w) const{
			if(_dead){
				w<<"-";
			}
			else if (_age > 9){
				w<<"+";
			}
			else{
				w<<_age;
			}
		}
		void set(std::istream& input){
			char c;
			input>>c;
			if (c == '-'){
				_dead = true;
				_age = 0;
			}
			else if (c >= '0' && c <= '9'){
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
		Life(int rows, int columns) : 
			_population(0),
			_generation(0),
            _rows(rows),
            _cols(columns),
			_board(rows, columns)
            {
                _neighborCount.resize(_rows);
                for (int i = 0; i < _rows; i++) {
                    _neighborCount[i].resize(_cols);
                }
            }
			
		void life_print(std::ostream& w = std::cout){
			w<<"Generation = "<<_generation<<", Population = "<<_population<<"."<<endl;
			for (int i = 0; i < _rows; i++){
				for (int j = 0; j < _cols; j++){
					_board[i][j].print_self(w);
				}
				w<<endl;
			}
			w<<endl;
        }
        void count_print(std::ostream& w = std::cout){
            //prints the _neighborCount matrix
            for (int i = 0; i < _rows; i++){
                for (int j = 0; j < _cols; j++){
                    w<<_neighborCount[i][j];
                }
                w<<endl;
            }
            w<<endl;
        }
        void update_neighbor_count(int row, int col, char neighbor){
            //Given the coordinates of a live cell, updates the neighbor count
            //in the direction of "neighbor".
            if (neighbor == '0') {
                _neighborCount[row][col - 1] += 1;
            }
            else if (neighbor == '1') {
                _neighborCount[row - 1][col - 1] += 1;
            }
            else if (neighbor == '2') {
                _neighborCount[row - 1][col] += 1;
            }
            else if (neighbor == '3') {
                _neighborCount[row - 1][col + 1] += 1;
            }
            else if (neighbor == '4') {
                _neighborCount[row][col + 1] += 1;
            }
            else if (neighbor == '5') {
                _neighborCount[row + 1][col + 1] += 1;
            }
            else if (neighbor == '6') {
                _neighborCount[row + 1][col] += 1;
            }
            else if (neighbor == '7') {
                _neighborCount[row + 1][col - 1] += 1;
            }
            else{
                cout<<"Update_neighbor_count: neighbor input is not 0 - 7, "<<neighbor<<endl;
                int i = 0;
                while (i != -1) {
                    i++;
                }
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
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    cornerNeighborsToUpdate = _board[(i * (_rows - 1))][(j * (_cols - 1))].update_count_corner((2 * i) + j);
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
            for (int i = 0; i < 4; i++) {
                int j = 1;
                while ((j < _rows - 1) && (i % 2 == 0)) {
                    edgeNeighborsToUpdate = _board[j][(i / 2) * (_cols - 1)].update_count_edge(i);
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
                    edgeNeighborsToUpdate = _board[(i / 2) * (_rows - 1)][j].update_count_edge(i);
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
            for (int i = 1; i < _rows - 1; i++) {
                for (int j = 1; j < _cols - 1; j++) {
                    regularNeighborsToUpdate = _board[i][j].update_count_regular();
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
};



