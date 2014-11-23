
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "gtest/gtest.h"
#include "Life.h"

using namespace std;

/* AbstractCell Tests*/
TEST(AbstractCell, Constructor) {
		Life<Fredkin> a1(20, 20);
		ASSERT_EQ(a1.isDead());
		ASSERT_EQ(a1.getNeighborCount(), 0);
 	}