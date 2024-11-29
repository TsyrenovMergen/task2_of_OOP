#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class Cell {
	char now; ///the current state of the cell
	char next; ///the state of the cell in the next iteration
public:
	/*returns the current state of the cell*/
	char getstate() { return this->now; };
	/*the current state of the cell becomes equal to the state in the next iteration*/
	void nextstate()
	{
		this->now = this->next;
		return;
	}
	/*sets the state on the next iteration*/
	void setstate(char state)
	{
		this->next = state;
		return;
	}
};

class Universe;

class Drawer {
public:
	void draw(Universe* universe);
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
private:
	friend void Reader::read(Universe*, string);
	friend void Writer::write(Universe*, string);
	friend void Drawer::draw(Universe*);
	friend void Game::start(int, char**);
private:
	/*Sets the name of the universe*/
	void setname(string name)
	{
		this->name = name;
		return;
	}
	/*the current state of the cell, which has x and y coordinates, becomes equal to the state in the next iteration*/
	void nextstate(int y, int x)
	{
		this->field[y][x].nextstate();
		return;
	}
	/*sets the next state of the cell, which has x and y coordinates*/
	void setstate(int y, int x, char state)
	{
		this->field[y][x].setstate(state);
		return;
	}
	/*Sets the rules of the universe*/
	void setrules(string rules)
	{
		int flag = 0;
		this->rules = rules;
		for (int i = 0; i < 9; i++)
		{
			b[i] = '0';
			s[i] = '0';
		}
		for (int i = 0; i < rules.length(); i++)
		{
			if (rules[i] == '/')
			{
				flag = 1;
				continue;
			}
			if (flag == 0 && (int)rules[i] >= 48 && (int)rules[i] <= 57)
			{
				this->b[(int)rules[i] - 48] = '1';
			}
			if (flag == 0 && (int)rules[i] >= 48 && (int)rules[i] <= 57)
			{
				this->s[(int)rules[i] - 48] = '1';
			}
		}
		return;
	}
	/*creates a field of the universe, initially all cells are dead*/
	void createfield(int sizex, int sizey)
	{
		this->sizex = sizex;
		this->sizey = sizey;
		this->countiterations = 0;
		this->field.resize(this->sizey);
		for (int i = 0; i < this->sizey; i++)
		{
			this->field[i].resize(this->sizex);
		}
		for (int i = 0; i < this->sizey; i++)
		{
			for (int j = 0; j < this->sizex; j++)
			{
				this->setstate(i, j, '0');
				this->nextstate(i, j);
			}
		}
		return;
	}
	/*returns the current state of a cell that has x and y coordinates*/
	char getstate(int y, int x)
	{
		return this->field[y][x].getstate();
	}
	/*returns the size of the field by the x coordinate*/
	int size_x() { return this->sizex; };
	/*returns the size of the field by the x coordinate*/
	int size_y() { return this->sizey; };
	/*Returns the number of iterations after the universe appeared*/
	int count_iterations() { return this->countiterations; };
	/*Returns the name of the universe*/
	string getname() { return this->name; };
	/*Returns the rules of the universe*/
	string getrules() { return this->rules; };
	/*Returns the number of neighbors of a cell that has x and y coordinates*/
	int count_neighbours(int y, int x)
	{
		int count = 0;
		char cell;
		if (y + 1 >= this->sizey)
		{
			cell = this->getstate(0, x);
		}
		else
		{
			cell = this->getstate(y + 1, x);
		}
		if (cell == '1')
		{
			count++;
		}
		if (y - 1 < 0)
		{
			cell = this->getstate(this->sizey - 1, x);
		}
		else
		{
			cell = this->getstate(y - 1, x);
		}
		if (cell == '1')
		{
			count++;
		}
		if (x + 1 >= this->sizex)
		{
			cell = this->getstate(y, 0);
		}
		else
		{
			cell = this->getstate(y, x + 1);
		}
		if (cell == '1')
		{
			count++;
		}
		if (x - 1 < 0)
		{
			cell = this->getstate(y, this->sizex - 1);
		}
		else
		{
			cell = this->getstate(y, x - 1);
		}
		if (cell == '1')
		{
			count++;
		}
		if (x + 1 >= this->sizex)
		{
			if (y + 1 >= this->sizey)
			{
				cell = this->getstate(0, 0);
			}
			else
			{
				cell = this->getstate(y + 1, 0);
			}
			if (cell == '1')
			{
				count++;
			}
			if (y - 1 < 0)
			{
				cell = this->getstate(this->sizey - 1, 0);
			}
			else
			{
				cell = this->getstate(y - 1, 0);
			}
			if (cell == '1')
			{
				count++;
			}
		}
		else
		{
			if (y + 1 >= this->sizey)
			{
				cell = this->getstate(0, x + 1);
			}
			else
			{
				cell = this->getstate(y + 1, x + 1);
			}
			if (cell == '1')
			{
				count++;
			}
			if (y - 1 < 0)
			{
				cell = this->getstate(this->sizey - 1, x + 1);
			}
			else
			{
				cell = this->getstate(y - 1, x + 1);
			}
			if (cell == '1')
			{
				count++;
			}
		}
		if (x - 1 < 0)
		{
			if (y + 1 >= this->sizey)
			{
				cell = this->getstate(0, this->sizex - 1);
			}
			else
			{
				cell = this->getstate(y + 1, this->sizex - 1);
			}
			if (cell == '1')
			{
				count++;
			}
			if (y - 1 < 0)
			{
				cell = this->getstate(this->sizey - 1, this->sizex - 1);
			}
			else
			{
				cell = this->getstate(y - 1, this->sizex - 1);
			}
			if (cell == '1')
			{
				count++;
			}
		}
		else
		{
			if (y + 1 >= this->sizey)
			{
				cell = this->getstate(0, x - 1);
			}
			else
			{
				cell = this->getstate(y + 1, x - 1);
			}
			if (cell == '1')
			{
				count++;
			}
			if (y - 1 < 0)
			{
				cell = this->getstate(this->sizey - 1, x - 1);
			}
			else
			{
				cell = this->getstate(y - 1, x - 1);
			}
			if (cell == '1')
			{
				count++;
			}
		}
		return count;
	}
	/*Generates the field of the universe after one iteration*/
	void next_generation()
	{
		int countcells;
		char cell;
		for (int i = 0; i < this->sizey; i++)
		{
			for (int j = 0; j < this->sizex; j++)
			{
				cell = this->getstate(i, j);
				countcells = this->count_neighbours(i, j);
				if (cell == '0')
				{
					if (this->b[countcells] == '1')
					{
						this->setstate(i, j, '1');
					}
				}
				else
				{
					if (this->s[countcells] == '0')
					{
						this->setstate(i, j, '0');
					}
				}
			}
		}
		for (int i = 0; i < this->sizey; i++)
		{
			for (int j = 0; j < this->sizex; j++)
			{
				this->nextstate(i, j);
			}
		}
		this->countiterations++;
		return;
	}
};

/*draws the universe in the terminal*/
void Drawer::draw(Universe* universe)
{
	char cell;
	int sizex = universe->size_x();
	int sizey = universe->size_y();
	cout << universe->getname() << endl;
	cout << universe->getrules() << endl;
	cout << universe->count_iterations() << endl;
	for (int i = 0; i < sizex + 2; i++)
	{
		cout << '#';
	}
	cout << endl;
	for (int i = 0; i < sizey; i++)
	{
		cout << '#';
		for (int j = 0; j < sizex; j++)
		{
			cell = universe->getstate(i, j);
			if (cell == '1')
			{
				cout << (char)219;
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '#' << endl;
	}
	for (int i = 0; i < sizex + 2; i++)
	{
		cout << '#';
	}
	cout << endl;
	return;
}

/*reads the description of the universe from the input file*/
void Reader::read(Universe* universe, string f)
{
	ifstream in;
	in.open(f);
	if (!in.is_open())
	{
		throw "the file not be could be opened for reading";
	}
	string x, y;
	int sizex = 0, sizey = 0;
	string name;
	string rules;
	string format;
	string comment;
	char spase;
	getline(in, format);
	if (format != "#Life 1.06")
	{
		in.close();
		throw "wrong format of the file";
	}
	in >> comment;
	while (comment[0] == '#')
	{
		if (comment == "#Size")
		{
			in >> sizex >> sizey;
			universe->createfield(sizex, sizey);
		}
		if (comment == "#N")
		{
			in >> spase;
			getline(in, name);
			universe->setname(name);
		}
		if (comment == "#R")
		{
			in >> rules;
			universe->setrules(rules);
		}
		in >> comment;
	}
	x = comment;
	in >> y;
	universe->setstate(stoi(y), stoi(x), '1');
	universe->nextstate(stoi(y), stoi(x));
	if (sizex <= 0 || sizey <= 0)
	{
		in.close();
		throw "file doesn't contain information about of size or sizes are negative";
	}
	while (1)
	{
		in >> x;
		if (x[0] == '\0')
		{
			break;
		}
		in >> y;
		universe->setstate(stoi(y), stoi(x), '1');
		universe->nextstate(stoi(y), stoi(x));
		x[0] = '\0';
	}
	in.close();
	return;
}

/*writes the description of the universe to the output file*/
void Writer::write(Universe* universe, string f)
{
	ofstream out;
	out.open(f);
	if (!out.is_open())
	{
		throw "the file not be opened for writing";
	}
	char cell;
	int sizex = universe->size_x();
	int sizey = universe->size_y();
	out << "Life 1.06" << endl;
	out << "#Size " << sizex << ' ' << sizey << endl;
	out << "#N " << universe->getname() << endl;
	out << "#R " << universe->getrules() << endl;
	for (int i = 0; i < sizey; i++)
	{
		for (int j = 0; j < sizex; j++)
		{
			cell = universe->getstate(i, j);
			if (cell == '1')
			{
				out << j << ' ' << i << endl;
			}
		}
	}
	out.close();
	return;
}

/*Starts game of life*/
void Game::start(int argc, char** argv)
{
	Reader r;
	Writer w;
	Drawer d;
	Universe u;
	string comand;
	string outfile;
	string iterations;
	string help = "dump <filename> - saves the universe to the file,"
		"tick <n = 1> (t <n = 1>) - calculates n iterations and prints the result"
		"exit – ends the game, help – prints the help about the commands\n";
	int number;
	if (argc == 1)
	{
		vector <string> files;
		files.push_back("input.txt");
		files.push_back("input1.txt");
		files.push_back("input2.txt");
		files.push_back("input4.txt");
		files.push_back("input5.txt");
		files.push_back("input6.txt");
		files.push_back("input7.txt");
		files.push_back("input8.txt");
		int number = rand() % 9;
		string file = files[number];
		r.read(&u, file);
		while (1)
		{
			cin >> comand;
			if (comand == "exit")
			{
				break;
			}
			if (comand == "help")
			{
				cout << help;
				continue;
			}
			if (comand == "dump")
			{
				cin >> outfile;
				w.write(&u, outfile);
				continue;
			}
			if (comand == "tick" || comand == "t")
			{
				number = 1;
				cin >> iterations;
				number = stoi(iterations);
				for (int i = 0; i < number; i++)
				{
					u.next_generation();
				}
				d.draw(&u);
				continue;
			}
			cout << "Use exit, help, dump <filename>, tick <n=1> (t<n=1>)" << endl;
		}
	}
	if (argc == 2)
	{
		r.read(&u, argv[1]);
		while (1)
		{
			cin >> comand;
			if (comand == "exit")
			{
				break;
			}
			if (comand == "help")
			{
				cout << help;
				continue;
			}
			if (comand == "dump")
			{
				cin >> outfile;
				w.write(&u, outfile);
				continue;
			}
			if (comand == "tick" || comand == "t")
			{
				number = 1;
				cin >> iterations;
				number = stoi(iterations);
				for (int i = 0; i < number; i++)
				{
					u.next_generation();
				}
				d.draw(&u);
				continue;
			}
			cout << "Use exit, help, dump <filename>, tick <n=1> (t<n=1>)" << endl;
		}
	}
	if (argc == 6 || argc == 4)
	{
		int iterations = 0;
		string outfile;
		string iterationsword = argv[2];
		string outputword = argv[3];
		r.read(&u, argv[1]);
		if (argc == 6 && argv[2][0] == '-' && argv[2][1] == 'i')
		{
			iterations = stoi(argv[3]);
		}
		if (iterationsword.find("--iterations=") == 0)
		{
			iterations = stoi(&iterationsword[13]);
		}
		for (int i = 0; i < iterations; i++)
		{
			u.next_generation();
		}
		if (argc == 6 && argv[4][0] == '-' && argv[4][1] == 'o')
		{
			outfile = argv[5];
		}
		if (outputword.find("--output=") == 0)
		{
			outfile = &outputword[9];
		}
		if (outfile[0] == '\0')
		{
			throw "The outputfile isn't in arguments";
		}
		w.write(&u, outfile);
	}
}
int main(int argc, char** argv)
{
	Game game;
	game.start(argc, argv);
	return 0;
}