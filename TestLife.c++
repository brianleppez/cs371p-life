
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
	std::ostringstream w;
	ConwayCell cw1;
	cw1.print(w);
	ASSERT_EQ(".", w.str());
 }

TEST(AbstractCell, Constructor1) {
	std::ostringstream w;
	FredkinCell f1;
	f1.print(w);
	ASSERT_EQ("-", w.str());
 }
TEST(AbstractCell, Constructor2) {
	std::ostringstream w;
	Cell c1;
	c1.print(w);
	ASSERT_EQ("-", w.str());
 }
TEST(AbstractCell, Print) {
	std::istringstream i;
	i.str("8");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("8", w.str());
 }
TEST(AbstractCell, Print1) {
	std::istringstream i;
	i.str("5");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("5", w.str());
 }
TEST(AbstractCell, Print2) {
	std::istringstream i;
	i.str("0");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("0", w.str());
 }
TEST(AbstractCell, Set) {
	std::istringstream i;
	i.str("-");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("-", w.str());
 }
TEST(AbstractCell, Set1) {
	std::istringstream i;
	i.str("*");
	std::ostringstream w;
	ConwayCell cw1;
	cw1.set(i);
	cw1.print(w);
	ASSERT_EQ("*", w.str());
 }
TEST(AbstractCell, Set2) {
	std::istringstream i;
	i.str(".");
	std::ostringstream w;
	ConwayCell cw1;
	cw1.set(i);
	cw1.print(w);
	ASSERT_EQ(".", w.str());
 }
TEST(AbstractCell, TryIncrement) {
	FredkinCell f1;
	f1.tryIncrementNC(true);
	ASSERT_EQ(0, f1.getNeighborCount());
 }
TEST(AbstractCell, TryIncrement1) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	ASSERT_EQ(1, f1.getNeighborCount());
 }
TEST(AbstractCell, TryIncrement2) {
	ConwayCell cw1;
	cw1.tryIncrementNC(false);
	ASSERT_EQ(1, cw1.getNeighborCount());
 }
TEST(AbstractCell, TryIncrement3) {
	ConwayCell cw1;
	cw1.tryIncrementNC(true);
	ASSERT_EQ(1, cw1.getNeighborCount());
 }
TEST(AbstractCell, TryIncrement4) {
	ConwayCell cw1;
	cw1.tryIncrementNC(false);
	cw1.tryIncrementNC(false);
	cw1.tryIncrementNC(false);
	cw1.tryIncrementNC(false);
	ASSERT_EQ(4, cw1.getNeighborCount());
 }
TEST(AbstractCell, TryIncrement5) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	ASSERT_EQ(4, f1.getNeighborCount());
 }
TEST(AbstractCell, TryIncrement6) {
	FredkinCell f1;
	f1.tryIncrementNC(true);
	f1.tryIncrementNC(true);
	f1.tryIncrementNC(true);
	f1.tryIncrementNC(true);
	ASSERT_EQ(0, f1.getNeighborCount());
 }
TEST(AbstractCell, TryIncrement7) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(true);
	f1.tryIncrementNC(true);
	f1.tryIncrementNC(true);
	f1.tryIncrementNC(true);
	ASSERT_EQ(4, f1.getNeighborCount());
 }
TEST(AbstractCell, GetAge) {
	ConwayCell cw1;
	ASSERT_EQ(0, cw1.getAge());
 }
TEST(AbstractCell, GetAge1) {
	std::istringstream i;
	i.str("0");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(0, f1.getAge());
 }
TEST(AbstractCell, GetAge2) {
	std::istringstream i;
	i.str("8");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(8, f1.getAge());
 }
TEST(AbstractCell, IsDead) {
	ConwayCell cw1;
	ASSERT_EQ(cw1.isDead(), true);
 }
TEST(AbstractCell, IsDead1) {
	FredkinCell f1;
	ASSERT_EQ(f1.isDead(), true);
 }
TEST(AbstractCell, IsDead2) {
	ConwayCell cw1;
	FredkinCell f1;
	ASSERT_EQ(f1.isDead() && cw1.isDead(), true);
 }
TEST(AbstractCell, GetNeighborCount) {
	ConwayCell cw1;
	ASSERT_EQ(0, cw1.getNeighborCount());
 }
TEST(AbstractCell, GetNeighborCount1) {
	Cell c1;
	ASSERT_EQ(0, c1.getNeighborCount());
 }
 TEST(AbstractCell, GetNeighborCount2) {
	FredkinCell f1;
	ASSERT_EQ(0, f1.getNeighborCount());
 }


/* ConwayCell Tests*/

TEST(ConwayCell, Print) {
	std::ostringstream w;
	ConwayCell cw1;
	cw1.print(w);
	ASSERT_EQ(".", w.str());
 }
TEST(ConwayCell, Print1) {
	std::istringstream i;
	i.str("*");
	std::ostringstream w;
	ConwayCell cw1;
	cw1.set(i);
	cw1.print(w);
	ASSERT_EQ("*", w.str());
 }
TEST(ConwayCell, Print2) {
	std::istringstream i;
	i.str(".");
	std::ostringstream w;
	ConwayCell cw1;
	cw1.set(i);
	cw1.print(w);
	ASSERT_EQ(".", w.str());
 }
 TEST(ConwayCell, Set) {
	std::istringstream i;
	i.str("*");
	std::ostringstream w;
	ConwayCell cw1;
	cw1.set(i);
	cw1.print(w);
	ASSERT_EQ("*", w.str());
 }
TEST(ConwayCell, Set2) {
	std::istringstream i;
	i.str(".");
	std::ostringstream w;
	ConwayCell cw1;
	cw1.set(i);
	cw1.print(w);
	ASSERT_EQ(".", w.str());
 }
 TEST(ConwayCell, Set3) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.isDead(), false);
 }
 TEST(ConwayCell, Set4) {
	std::istringstream i;
	i.str(".");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.isDead(), true);
 }
 TEST(ConwayCell, CheckRegulars) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_regulars(), "01234567");
 }
 TEST(ConwayCell, CheckRegulars1) {
	std::istringstream i;
	i.str(".");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_regulars(), "");
 }
 TEST(ConwayCell, CheckRegulars2) {
	ConwayCell cw1;
	ASSERT_EQ(cw1.check_regulars(), "");
 }
 TEST(ConwayCell, CheckCorners) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_corners(0), "456");
 }
 TEST(ConwayCell, CheckCorners1) {
	std::istringstream i;
	i.str(".");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_corners(0), "");
 }
 TEST(ConwayCell, CheckCorners2) {
	ConwayCell cw1;
	ASSERT_EQ(cw1.check_corners(1), "");
 }
 TEST(ConwayCell, CheckCorners3) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_corners(1), "670");
 }
 TEST(ConwayCell, CheckCorners4) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_corners(2), "234");
 }
 TEST(ConwayCell, CheckCorners5) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_corners(3), "012");
 }
 TEST(ConwayCell, CheckEdges) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_edges(0), "23456");
 }
 TEST(ConwayCell, CheckEdges1) {
	std::istringstream i;
	i.str(".");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_edges(2), "");
 }
 TEST(ConwayCell, CheckEdges2) {
	ConwayCell cw1;
	ASSERT_EQ(cw1.check_edges(3), "");
 }
 TEST(ConwayCell, CheckEdges3) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_edges(1), "45670");
 }
 TEST(ConwayCell, CheckEdges4) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_edges(2), "67012");
 }
 TEST(ConwayCell, CheckEdges5) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	ASSERT_EQ(cw1.check_edges(3), "01234");
 }
TEST(ConwayCell, KillRevive) {
	ConwayCell cw1;
	ASSERT_EQ(0, cw1.kill_revive());
 }
TEST(ConwayCell, KillRevive1) {
	ConwayCell cw1;
	cw1.tryIncrementNC(false);
	cw1.tryIncrementNC(false);
	cw1.tryIncrementNC(false);
	ASSERT_EQ(1, cw1.kill_revive());
	ASSERT_EQ(cw1.isDead(), false);
 }
TEST(ConwayCell, KillRevive2) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	cw1.tryIncrementNC(false);
	ASSERT_EQ(-1, cw1.kill_revive());
	ASSERT_EQ(cw1.isDead(), true);
 }
TEST(ConwayCell, KillRevive3) {
	std::istringstream i;
	i.str("*");
	ConwayCell cw1;
	cw1.set(i);
	cw1.tryIncrementNC(false);
	cw1.tryIncrementNC(false);
	ASSERT_EQ(0, cw1.kill_revive());
	ASSERT_EQ(cw1.isDead(), false);
 }


/* FredkinCell Tests*/

TEST(FredkinCell, Print) {
	std::ostringstream w;
	FredkinCell f1;
	f1.print(w);
	ASSERT_EQ("-", w.str());
 }
TEST(FredkinCell, Print1) {
	std::istringstream i;
	i.str("0");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("0", w.str());
 }
TEST(FredkinCell, Print2) {
	std::istringstream i;
	i.str("-");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("-", w.str());
 }
 TEST(FredkinCell, Set) {
	std::istringstream i;
	i.str("7");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("7", w.str());
 }
TEST(FredkinCell, Set2) {
	std::istringstream i;
	i.str("-");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	f1.print(w);
	ASSERT_EQ("-", w.str());
 }
 TEST(FredkinCell, Set3) {
	std::istringstream i;
	i.str("+");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.isDead(), false);
 }
 TEST(FredkinCell, Set4) {
	std::istringstream i;
	i.str("-");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.isDead(), true);
 }
TEST(FredkinCell, TryIncrement) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(true);
	f1.tryIncrementNC(true);
	ASSERT_EQ(2, f1.getNeighborCount());
 }
TEST(FredkinCell, TryIncrement2) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	ASSERT_EQ(1, f1.getNeighborCount());
 }
TEST(FredkinCell, TryIncrement3) {
	FredkinCell f1;
	f1.tryIncrementNC(true);
	ASSERT_EQ(0, f1.getNeighborCount());
 }
TEST(FredkinCell, TryIncrement4) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(true);
	ASSERT_EQ(3, f1.getNeighborCount());
 }
TEST(FredkinCell, GetAge) {
	std::istringstream i;
	i.str("0");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(0, f1.getAge());
 }
TEST(FredkinCell, GetAge2) {
	std::istringstream i;
	i.str("-");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(0, f1.getAge());
 }
TEST(FredkinCell, GetAge3) {
	std::istringstream i;
	i.str("4");
	std::ostringstream w;
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(4, f1.getAge());
 }
 TEST(FredkinCell, CheckRegulars) {
	std::istringstream i;
	i.str("0");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_regulars(), "0246");
 }
 TEST(FredkinCell, CheckRegulars1) {
	std::istringstream i;
	i.str("-");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_regulars(), "");
 }
 TEST(FredkinCell, CheckRegulars2) {
	FredkinCell f1;
	ASSERT_EQ(f1.check_regulars(), "");
 }
 TEST(FredkinCell, CheckCorners) {
	std::istringstream i;
	i.str("9");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_corners(0), "46");
 }
 TEST(FredkinCell, CheckCorners1) {
	std::istringstream i;
	i.str("-");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_corners(0), "");
 }
 TEST(FredkinCell, CheckCorners2) {
	FredkinCell f1;
	ASSERT_EQ(f1.check_corners(1), "");
 }
 TEST(FredkinCell, CheckCorners3) {
	std::istringstream i;
	i.str("8");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_corners(1), "60");
 }
 TEST(FredkinCell, CheckCorners4) {
	std::istringstream i;
	i.str("7");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_corners(2), "24");
 }
 TEST(FredkinCell, CheckCorners5) {
	std::istringstream i;
	i.str("6");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_corners(3), "02");
 }
 TEST(FredkinCell, CheckEdges) {
	std::istringstream i;
	i.str("5");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_edges(0), "246");
 }
 TEST(FredkinCell, CheckEdges1) {
	std::istringstream i;
	i.str("-");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_edges(1), "");
 }
 TEST(FredkinCell, CheckEdges2) {
	FredkinCell f1;
	ASSERT_EQ(f1.check_edges(2), "");
 }
 TEST(FredkinCell, CheckEdges3) {
	std::istringstream i;
	i.str("4");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_edges(1), "460");
 }
 TEST(FredkinCell, CheckEdges4) {
	std::istringstream i;
	i.str("3");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_edges(2), "602");
 }
 TEST(FredkinCell, CheckEdges5) {
	std::istringstream i;
	i.str("2");
	FredkinCell f1;
	f1.set(i);
	ASSERT_EQ(f1.check_edges(3), "024");
 }
TEST(FredkinCell, KillRevive) {
	FredkinCell f1;
	ASSERT_EQ(0, f1.kill_revive());
 }
TEST(FredkinCell, KillRevive1) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	ASSERT_EQ(1, f1.kill_revive());
	ASSERT_EQ(f1.isDead(), false);
 }
TEST(FredkinCell, KillRevive2) {
	FredkinCell f1;
	f1.tryIncrementNC(false);
	ASSERT_EQ(1, f1.kill_revive());
	ASSERT_EQ(f1.isDead(), false);
 }
TEST(FredkinCell, KillRevive3) {
	std::istringstream i;
	i.str("1");
	FredkinCell f1;
	f1.set(i);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	ASSERT_EQ(-1, f1.kill_revive());
	ASSERT_EQ(f1.isDead(), true);
 }
TEST(FredkinCell, KillRevive4) {
	std::istringstream i;
	i.str("0");
	FredkinCell f1;
	f1.set(i);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	f1.tryIncrementNC(false);
	ASSERT_EQ(0, f1.kill_revive());
	ASSERT_EQ(f1.isDead(), false);
 }


/* Cell Tests*/

TEST(Cell, Print) {
	std::ostringstream w;
	Cell c1;
	c1.print(w);
	ASSERT_EQ("-", w.str());
 }
TEST(Cell, Print1) {
	std::istringstream i;
	i.str("1");
	std::ostringstream w;
	Cell c1;
	c1.set(i);
	c1.print(w);
	ASSERT_EQ("1", w.str());
 }
TEST(Cell, Print2) {
	std::istringstream i;
	i.str("-");
	std::ostringstream w;
	Cell c1;
	c1.set(i);
	c1.print(w);
	ASSERT_EQ("-", w.str());
 }
 TEST(Cell, Set) {
	std::istringstream i;
	i.str("2");
	std::ostringstream w;
	Cell c1;
	c1.set(i);
	c1.print(w);
	ASSERT_EQ("2", w.str());
 }
TEST(Cell, Set2) {
	std::istringstream i;
	i.str("-");
	std::ostringstream w;
	Cell c1;
	c1.set(i);
	c1.print(w);
	ASSERT_EQ("-", w.str());
 }
 TEST(Cell, Set3) {
	std::istringstream i;
	i.str("3");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.getNeighborCount(), 0);
 }
 TEST(Cell, Set4) {
	std::istringstream i;
	i.str("-");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.getNeighborCount(), 0);
 }
 TEST(Cell, CheckRegulars) {
	std::istringstream i;
	i.str("9");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_regulars(), "01234567");
 }
 TEST(Cell, CheckRegulars1) {
	std::istringstream i;
	i.str("-");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_regulars(), "");
 }
 TEST(Cell, CheckRegulars2) {
	Cell c1;
	ASSERT_EQ(c1.check_regulars(), "");
 }
 TEST(Cell, CheckCorners) {
	std::istringstream i;
	i.str("8");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_corners(0), "456");
 }
 TEST(Cell, CheckCorners1) {
	std::istringstream i;
	i.str("-");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_corners(0), "");
 }
 TEST(Cell, CheckCorners2) {
	Cell cw1;
	ASSERT_EQ(cw1.check_corners(1), "");
 }
 TEST(Cell, CheckCorners3) {
	std::istringstream i;
	i.str("7");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_corners(1), "670");
 }
 TEST(Cell, CheckCorners4) {
	std::istringstream i;
	i.str("6");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_corners(2), "234");
 }
 TEST(Cell, CheckCorners5) {
	std::istringstream i;
	i.str("5");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_corners(3), "012");
 }
 TEST(Cell, CheckEdges) {
	std::istringstream i;
	i.str("4");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_edges(0), "23456");
 }
 TEST(Cell, CheckEdges1) {
	std::istringstream i;
	i.str("-");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_edges(2), "");
 }
 TEST(Cell, CheckEdges2) {
	Cell c1;
	ASSERT_EQ(c1.check_edges(3), "");
 }
 TEST(Cell, CheckEdges3) {
	std::istringstream i;
	i.str("2");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_edges(1), "45670");
 }
 TEST(Cell, CheckEdges4) {
	std::istringstream i;
	i.str("1");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_edges(2), "67012");
 }
 TEST(Cell, CheckEdges5) {
	std::istringstream i;
	i.str("0");
	Cell c1;
	c1.set(i);
	ASSERT_EQ(c1.check_edges(3), "01234");
 }
TEST(Cell, TryIncrement) {
	Cell c1;
	c1.tryIncrementNC(false);
	ASSERT_EQ(1, c1.getNeighborCount());
 }
TEST(Cell, TryIncrement2) {
	Cell c1;
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(true);
	c1.tryIncrementNC(false);
	ASSERT_EQ(2, c1.getNeighborCount());
 }
TEST(Cell, TryIncrement3) {
	Cell c1;
	c1.tryIncrementNC(true);
	c1.tryIncrementNC(true);
	c1.tryIncrementNC(true);
	ASSERT_EQ(0, c1.getNeighborCount());
 }
TEST(Cell, KillRevive) {
	Cell c1;
	ASSERT_EQ(0, c1.kill_revive());
 }
TEST(Cell, KillRevive1) {
	Cell c1;
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	ASSERT_EQ(1, c1.kill_revive());
 }
TEST(Cell, KillRevive2) {
	Cell c1;
	c1.tryIncrementNC(false);
	ASSERT_EQ(1, c1.kill_revive());
 }
TEST(Cell, KillRevive3) {
	std::istringstream i;
	i.str("0");
	Cell c1;
	c1.set(i);
	std::ostringstream w;
	c1.print(w);
	ASSERT_EQ("0", w.str());
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	ASSERT_EQ(0, c1.kill_revive());
	c1.print(w);
	ASSERT_EQ("01", w.str());
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	ASSERT_EQ(0, c1.kill_revive());
	c1.print(w);
	ASSERT_EQ("01*", w.str());
 }
 TEST(Cell, getNeighborCount) {
	Cell c1;
	ASSERT_EQ(0, c1.getNeighborCount());
 }
 TEST(Cell, getNeighborCount1) {
	Cell c1;
	c1.tryIncrementNC(false);
	ASSERT_EQ(1, c1.getNeighborCount());
 }
 TEST(Cell, getNeighborCount2) {
	Cell c1;
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(false);
	ASSERT_EQ(3, c1.getNeighborCount());
 }
 TEST(Cell, getNeighborCount3) {
	Cell c1;
	c1.tryIncrementNC(true);
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(true);
	c1.tryIncrementNC(false);
	c1.tryIncrementNC(true);
	ASSERT_EQ(2, c1.getNeighborCount());
 }


/* Life Tests*/

 TEST(Life, LifeSet) {
 	Life<Cell> c1(1, 5);
	std::istringstream i;
	i.str("00000");
	c1.life_set(i);
	std::ostringstream w;
	c1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 5.\n00000\n\n");
 }
  TEST(Life, LifeSet1) {
 	Life<FredkinCell> f1(1, 7);
	std::istringstream i;
	i.str("0-0-0-0");
	f1.life_set(i);
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 4.\n0-0-0-0\n\n");
 }
  TEST(Life, LifeSet2) {
 	Life<ConwayCell> cw1(1, 12);
	std::istringstream i;
	i.str("***......***");
	cw1.life_set(i);
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 6.\n***......***\n\n");
 }
  TEST(Life, LifeRead) {
 	Life<Cell> c1(1, 1);
	std::istringstream i;
	i.str("\n\n\n0");
	c1.life_read(i);
	std::ostringstream w;
	c1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 1.\n0\n\n");
 }
  TEST(Life, LifeRead1) {
 	Life<FredkinCell> f1(1, 3);
	std::istringstream i;
	i.str("\n\n\n0-0");
	f1.life_read(i);
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 2.\n0-0\n\n");
 }
  TEST(Life, LifeRead2) {
 	Life<ConwayCell> cw1(1, 21);
	std::istringstream i;
	i.str("\n\n\n***......***......***");
	cw1.life_read(i);
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 9.\n***......***......***\n\n");
 }
  TEST(Life, UpdateNeighborCount) {
 	Life<Cell> c1(3, 5);
	std::istringstream i;
	i.str("00000\n00000\n00000");
	c1.life_set(i);
	char c = '4';
	c1.update_neighbor_count(1,0,c);
	c1.life_kill_revive();
	std::ostringstream w;
	c1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 1.\n-----\n-1---\n-----\n\n");
 }
  TEST(Life, UpdateNeighborCount1) {
 	Life<FredkinCell> f1(5, 5);
	std::istringstream i;
	i.str("00000\n00000\n00000\n00000\n00000");
	f1.life_set(i);
	char c = '6';
	f1.update_neighbor_count(0,0,c);
	f1.life_kill_revive();
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 1.\n-----\n1----\n-----\n-----\n-----\n\n");
 }
  TEST(Life, UpdateNeighborCount2) {
 	Life<ConwayCell> cw1(2, 12);
	std::istringstream i;
	i.str("***......***\n***......***");
	cw1.life_set(i);
	char c = '6';
	cw1.update_neighbor_count(0,0,c);
	c = '0';
	cw1.update_neighbor_count(1,1,c);
	cw1.life_kill_revive();
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 1.\n............\n*...........\n\n");
 }
  TEST(Life, UpdateCounts) {
 	Life<FredkinCell> f1(4, 6);
	std::istringstream i;
	i.str("------\n--00--\n--00--\n------");
	f1.life_set(i);
	f1.update_counts();
	f1.life_kill_revive();
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 8.\n--00--\n-0--0-\n-0--0-\n--00--\n\n");
 }
  TEST(Life, UpdateCounts1) {
 	Life<FredkinCell> f1(3, 5);
	std::istringstream i;
	i.str("-----\n--0--\n-----");
	f1.life_set(i);
	f1.update_counts();
	f1.life_kill_revive();
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 4.\n--0--\n-0-0-\n--0--\n\n");
 }
  TEST(Life, UpdateCounts2) {
 	Life<ConwayCell> cw1(5, 5);
	std::istringstream i;
	i.str(".....\n..*..\n..*..\n..*..\n.....");
	cw1.life_set(i);
	cw1.update_counts();
	cw1.life_kill_revive();
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 3.\n.....\n.....\n.***.\n.....\n.....\n\n");
 }
  TEST(Life, LifeKillRevive) {
 	Life<FredkinCell> f1(4, 6);
	std::istringstream i;
	i.str("------\n------\n--00--\n------");
	f1.life_set(i);
	f1.update_counts();
	f1.life_kill_revive();
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 8.\n------\n--00--\n-0110-\n--00--\n\n");
 }
  TEST(Life, LifeKillRevive1) {
 	Life<FredkinCell> f1(3, 5);
	std::istringstream i;
	i.str("--0--\n--0--\n--0--");
	f1.life_set(i);
	f1.update_counts();
	f1.life_kill_revive();
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 8.\n-010-\n-0-0-\n-010-\n\n");
 }
  TEST(Life, LifeKillRevive2) {
 	Life<ConwayCell> cw1(5, 5);
	std::istringstream i;
	i.str(".....\n.....\n.***.\n.....\n.....");
	cw1.life_set(i);
	cw1.update_counts();
	cw1.life_kill_revive();
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 3.\n.....\n..*..\n..*..\n..*..\n.....\n\n");
 }
  TEST(Life, LifeKillRevive3) {
 	Life<FredkinCell> f1(4, 6);
	std::istringstream i;
	i.str("--00--\n--00--\n--00--\n--00--");
	f1.life_set(i);
	f1.life_kill_revive();
	std::ostringstream w;
	f1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 0.\n------\n------\n------\n------\n\n");
 }
  TEST(Life, LifeKillRevive4) {
 	Life<ConwayCell> cw1(5, 5);
	std::istringstream i;
	i.str("*****\n*****\n*****\n*****\n*****");
	cw1.life_set(i);
	cw1.life_kill_revive();
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 0.\n.....\n.....\n.....\n.....\n.....\n\n");
 }
  TEST(Life, LifeKillRevive5) {
 	Life<ConwayCell> cw1(5, 5);
	std::istringstream i;
	i.str("**.**\n**.**\n**.**\n**.**\n**.**");
	cw1.life_set(i);
	cw1.life_kill_revive();
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 0.\n.....\n.....\n.....\n.....\n.....\n\n");
 }
  TEST(Life, LifeKillRevive6) {
 	Life<ConwayCell> cw1(5, 5);
	std::istringstream i;
	i.str("***..\n*****\n*****\n*****\n*****");
	cw1.life_set(i);
	cw1.life_kill_revive();
	std::ostringstream w;
	cw1.life_print(w);
	ASSERT_EQ(w.str(), "Generation = 0, Population = 0.\n.....\n.....\n.....\n.....\n.....\n\n");
 }