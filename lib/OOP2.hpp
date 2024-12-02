#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
class Cell {
	char now;
	char next;
public:
	char getstate() noexcept;
	void nextstate() noexcept;
	void setstate(char state) noexcept;
};

class Universe {
private:
	vector<vector<Cell>> field; ///two-dimensional vector storing the field of the universe
	char b[9]; ///an array that stores information about the number of neighbors a cell is born with
	char s[9]; ///an array storing information on how many neighbors a cell survives
	string name; ///The name of the universe
	string rules; ///string representation of the rules of the universe
	int sizex; ///the size of the field according to the x coordinate
	int sizey; ///the size of the field according to the y coordinate
	int countiterations; ///The number of iterations since the universe appeared
public:
	void setname(string name) noexcept;
	void nextstate(int y, int x) noexcept;
	void setstate(int y, int x, char state) noexcept;
	void setrules(string rules) noexcept;
	void createfield(int sizex, int sizey) noexcept;
	char getstate(int y, int x) noexcept;
	int size_x() noexcept;
	int size_y() noexcept;
	int count_iterations() noexcept;
	string getname() noexcept;
	string getrules() noexcept;
	int count_neighbours(int y, int x) noexcept;
	void next_generation() noexcept;
};

class Drawer {
public:
	void draw(Universe* universe) noexcept;
};
class Reader {
public:
	void read(Universe* universe, string f);
};
class Writer {
public:
	void write(Universe* universe, string f);
};
class Game {
public:
	void start(int argc, char** argv);
};