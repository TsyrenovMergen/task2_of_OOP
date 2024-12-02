#include <gtest/gtest.h>
#include "C:\Users\tsire\source\repos\googletest2\lib\OOP2.hpp"

TEST(CellTest, get_state)
{
	Cell a;
	a.setstate('1');
	a.nextstate();
	EXPECT_EQ(a.getstate(), '1');
	a.setstate('0');
	a.nextstate();
	EXPECT_EQ(a.getstate(), '0');
}

TEST(CellTest, next_state)
{
	Cell a;
	a.setstate('1');
	a.nextstate();
	EXPECT_EQ(a.getstate(), '1');
	a.setstate('0');
	a.nextstate();
	EXPECT_EQ(a.getstate(), '0');
}

TEST(CellTest, set_state)
{
	Cell a;
	a.setstate('1');
	a.nextstate();
	EXPECT_EQ(a.getstate(), '1');
	a.setstate('0');
	a.nextstate();
	EXPECT_EQ(a.getstate(), '0');
}

TEST(UniverseSetTest, setnameTest)
{
	Universe u;
	u.setname("Universe");
	EXPECT_EQ(u.getname(), "Universe");
}

TEST(UniverseSetTest, setrulesTest)
{
	Universe u;
	u.setrules("B23/S3");
	EXPECT_EQ(u.getrules(), "B23/S3");
}

TEST(UniverseGetTest, getnameTest)
{
	Universe u;
	u.setname("Universe");
	EXPECT_EQ(u.getname(), "Universe");
}

TEST(UniverseGetTest, getrulesTest)
{
	Universe u;
	u.setrules("B23/S3");
	EXPECT_EQ(u.getrules(), "B23/S3");
}

TEST(UniverseGetTest, size_xTest)
{
	Universe u;
	u.createfield(5, 5);
	EXPECT_EQ(u.size_x(), 5);
}

TEST(UniverseGetTest, size_yTest)
{
	Universe u;
	u.createfield(5, 5);
	EXPECT_EQ(u.size_y(), 5);
}

TEST(UniverseGetTest, count_iterationsTest)
{
	Universe u;
	u.createfield(5, 5);
	u.setrules("B23/S3");
	EXPECT_EQ(u.count_iterations(), 0);
	for (int i = 0; i < 5; i++)
	{
		u.next_generation();
	}
	EXPECT_EQ(u.count_iterations(), 5);
}

TEST(UniverseCellTest, get_state)
{
	Universe u;
	u.createfield(5, 5);
	u.setstate(0, 0, '1');
	u.nextstate(0, 0);
	EXPECT_EQ(u.getstate(0, 0), '1');
	u.setstate(0, 0, '0');
	u.nextstate(0, 0);
	EXPECT_EQ(u.getstate(0, 0), '0');
}

TEST(UniverseCellTest, set_state)
{
	Universe u;
	u.createfield(5, 5);
	u.setstate(0, 0, '1');
	u.nextstate(0, 0);
	EXPECT_EQ(u.getstate(0, 0), '1');
	u.setstate(0, 0, '0');
	u.nextstate(0, 0);
	EXPECT_EQ(u.getstate(0, 0), '0');
}

TEST(UniverseCellTest, next_state)
{
	Universe u;
	u.createfield(5, 5);
	u.setstate(0, 0, '1');
	u.nextstate(0, 0);
	EXPECT_EQ(u.getstate(0, 0), '1');
	u.setstate(0, 0, '0');
	u.nextstate(0, 0);
	EXPECT_EQ(u.getstate(0, 0), '0');
}

TEST(UniverseCreatefield, create_fieldTest)
{
	Universe u;
	u.createfield(3, 3);
	EXPECT_EQ(u.getstate(0, 0), '0');
	EXPECT_EQ(u.getstate(0, 1), '0');
	EXPECT_EQ(u.getstate(0, 2), '0');
	EXPECT_EQ(u.getstate(1, 0), '0');
	EXPECT_EQ(u.getstate(1, 1), '0');
	EXPECT_EQ(u.getstate(1, 2), '0');
	EXPECT_EQ(u.getstate(2, 0), '0');
	EXPECT_EQ(u.getstate(2, 1), '0');
	EXPECT_EQ(u.getstate(2, 2), '0');
}

TEST(UniverseCount_neighboors, count_neighborsTest)
{
	Universe u;
	u.createfield(3, 3);
	u.setrules("B23/S3");
	u.setstate(1, 1, '1');
	u.nextstate(1, 1);
	u.setstate(0, 0, '1');
	u.nextstate(0, 0);
	u.setstate(2, 2, '1');
	u.nextstate(2, 2);
	EXPECT_EQ(u.count_neighbours(0, 0), 3);
	EXPECT_EQ(u.count_neighbours(1, 1), 3);
	EXPECT_EQ(u.count_neighbours(2, 2), 3);
	EXPECT_EQ(u.count_neighbours(0, 1), 2);
	EXPECT_EQ(u.count_neighbours(0, 2), 1);
	EXPECT_EQ(u.count_neighbours(1, 0), 2);
	EXPECT_EQ(u.count_neighbours(1, 2), 2);
	EXPECT_EQ(u.count_neighbours(2, 0), 1);
	EXPECT_EQ(u.count_neighbours(2, 1), 2);
}

TEST(Universe_next_generation, next_generationTest)
{
	Universe u;
	u.createfield(3, 3);
	u.setrules("B23/S3");
	u.setstate(1, 1, '1');
	u.nextstate(1, 1);
	u.setstate(0, 1, '1');
	u.nextstate(0, 1);
	u.setstate(2, 1, '1');
	u.nextstate(2, 1);
	u.next_generation();
	EXPECT_EQ(u.getstate(0, 0), '0');
	EXPECT_EQ(u.getstate(0, 1), '0');
	EXPECT_EQ(u.getstate(0, 2), '0');
	EXPECT_EQ(u.getstate(1, 0), '1');
	EXPECT_EQ(u.getstate(1, 1), '1');
	EXPECT_EQ(u.getstate(1, 2), '1');
	EXPECT_EQ(u.getstate(2, 0), '0');
	EXPECT_EQ(u.getstate(2, 1), '0');
	EXPECT_EQ(u.getstate(2, 2), '0');
}
