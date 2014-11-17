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
	private:
		bool _dead;
		int _neighborCount;
	public:
		AbstractCell() :
		_dead(true){}
		// void print_self(ostream& w) const {}
		bool is_dead () const{
			return _dead;
		}
		 // evolve = 0; foce conway and fredkin to define.
};

//Cell class
class Cell {
	AbstractCell* p;
};
	
};

//ConwayCell class
class ConwayCell : public AbstractCell{
	
	public:
		void print_self(ostream& w) const{
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
		void print_self(ostream& w) const{
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
		// vector<vector<unsigned int > > _neighborCount;
	public:
		// Life(int rows, int cols) :
		// 	_rows (rows),
		// 	_cols (cols),
		// 	_population(0),
		// 	_generation(0),
		// 	_board (rows, std::vector<T > (cols)),
		// 	_neighborCount (rows, std::vector<unsigned int>(cols)) 
		// {}
		Life(int rows, int columns) : 

			_population(0),
			_generation(0),
			_board(rows, columns), 
			_neighborCount()
			{
				input>>_rows;
				input>>_cols;
				_board.resize(_rows);
				_neighborCount.resize(_rows);
	             for (int i = 0; i < _rows; i++) {
	                 _board[i].resize(_cols);
	                 _neighborCount[i].resize(_cols);
	             }
	             for (int i = 0; i < _rows; i++) {
	             	for (int j = 0; j < _cols; j++){
	             		_board[i][j].set(input); 
	             	}
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
};

