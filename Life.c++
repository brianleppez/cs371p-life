#include "Life.h"

// ------------
// AbstractCell
// ------------

AbstractCell::AbstractCell () : _dead (true), _neighborCount (0) {}

void AbstractCell::tryIncrementNC (bool angledNeighbor) { _neighborCount++;}

bool AbstractCell::isDead () { return _dead;}

unsigned int AbstractCell::getNeighborCount() { return _neighborCount;}

void AbstractCell::incrementNC () { _neighborCount++;}

void AbstractCell::resetNC () { _neighborCount = 0;}

unsigned int AbstractCell::getAge () const { return 0;}

void AbstractCell::revive () {}

// ----------
// ConwayCell
// ----------

void ConwayCell::print (ostream& w) const {
    if (_dead) { w<<".";}
    else { w<<"*";}
}

char ConwayCell::set (istream& input) {
    char c;
    input>>c;
    assert(c == '*' || c == '.');
    if (c == '.') { _dead = true;}
    else { _dead = false;}
    return c;
}

string ConwayCell::check_regulars () const {
    if (_dead) { return "";}
    else { return "01234567";}
}

string ConwayCell::check_corners (int i) const {
    assert(i >= 0 && i <= 3);
    if (_dead) {
        return "";
    }
    else {
        if (i == 0) { return "456";}
        else if (i == 1) { return "670";}
        else if (i == 2) { return "234";}
        else { return "012";}
    }
}

string ConwayCell::check_edges (int i) const {
    assert(i >= 0 && i <= 3);
    if (_dead) { return "";}
    else {
        if (i == 0) { return "23456";}
        else if (i == 1) { return "45670";}
        else if (i == 2) { return "67012";}
        else { return "01234";}
    }
}

AbstractCell* ConwayCell::clone () const { return new ConwayCell(*this);}

int ConwayCell::kill_revive () {
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

void ConwayCell::revive () { _dead = false;}

// -------
// Fredkin
// -------

void FredkinCell::print (ostream& w) const {
    if(_dead) { w << "-";}
    else if (_age > 9) { w << "+";}
    else{ w << _age;}
}

char FredkinCell::set (std::istream& input) {
    char c;
    input >> c;
    assert(c == '-' || (c >= '0' && c <= '9') || c == '+');
    if (c == '-'){
        _dead = true;
        _age = 0;
    }
    else if (c >= '0' && c <= '9') {
        _dead = false;
        _age = c - '0';
    }
    else {
        _dead = false;
        _age = 10;
    }
    return c;
}

void FredkinCell::tryIncrementNC (bool angledNeighbor) { if (!angledNeighbor) { incrementNC();}}

unsigned int FredkinCell::getAge () const { return _age;}

string FredkinCell::check_regulars () const {
    if (_dead) { return "";}
    else { return "0246";}
}

string FredkinCell::check_corners (int i) const {
    assert(i >= 0 && i <= 3);
    if (_dead) { return "";}
    else {
        if (i == 0) { return "46";}
        else if (i == 1) { return "60";}
        else if (i == 2) { return "24";}
        else { return "02";}
    }
}

string FredkinCell::check_edges (int i) const {
    assert (i >= 0 && i <= 3);
    if (_dead) { return "";}
    else {
        if (i == 0) { return "246";}
        else if (i == 1) { return "460";}
        else if (i == 2) { return "602";}
        else { return "024";}
    }
}

AbstractCell* FredkinCell::clone () const { return new FredkinCell(*this);}

int FredkinCell::kill_revive () {
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

// ----
// Cell
// ----

Cell::Cell (AbstractCell* p) : _p (p) {}

Cell::Cell (const Cell& other) : _p (other._p->clone()) {}

Cell::~Cell () { delete _p;}

Cell& Cell::operator = (const Cell& other) {
    if (this != &other){
        delete _p;
        _p = other._p->clone();
    }
    return *this;
}

void Cell::print (ostream& w) const { return _p->print(w);}

char Cell::set (std::istream& input) { return _p->set(input);}

string Cell::check_regulars () const {
    if (_p->isDead()) { return "";}
    else { return "01234567";}
}

string Cell::check_corners (int i) const {
    assert(i >= 0 && i <= 3);
    if (_p->isDead()) { return "";}
    else {
        if (i == 0) { return "456";}
        else if (i == 1) { return "670";}
        else if (i == 2) { return "234";}
        else { return "012";}
    }
}

string Cell::check_edges (int i) const {
    assert(i >= 0 && i <= 3);        
    if (_p->isDead()) { return "";}
    else {
        if (i == 0) { return "23456";}
        else if (i == 1) { return "45670";}
        else if (i == 2) { return "67012";}
        else { return "01234";}
    }
}

void Cell::tryIncrementNC (bool angledNeighbor) { _p->tryIncrementNC(angledNeighbor);}

int Cell::kill_revive () {
    int v = _p->kill_revive();
    if(v == 0) {
        if(_p->getAge() == 2){
            *this = new ConwayCell();
            _p->revive();
        }
    }
    return v;
}

int Cell::getNeighborCount () { return _p->getNeighborCount();}
