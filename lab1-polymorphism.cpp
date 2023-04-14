#include <iostream>
#include <vector>

using namespace std;

class Book
{
	string author;
	string name;
public:
	Book(string a, string n)
	{
		author = a;
		name = n;
	}
		
	void Print()
	{
		cout << author << " " << name<< " " << endl;
	}
	
	virtual int isFiction() {}
	virtual ~Book() { cout << "~Book" << endl; }
};

class FictionBook : public Book
{
public:
	FictionBook(string a, string n) : Book(a, n) {}
	int isFiction() { return 1; }
	~FictionBook() { cout << "~FictionBook" << endl; }
};

class TechBook : public Book
{
public:
	TechBook(string a, string n) : Book(a, n) {}
	int isFiction() { return 0; }
	~TechBook() { cout << "~TechBook" << endl; }
};

void TaskV(vector<Book*> library) 
{
	int fiction_counter = 0;
	int tech_counter = 0;

	for(int i=0; i<library.size(); i++)
	{
		fiction_counter += library[i]->isFiction();
	}
	tech_counter = library.size() - fiction_counter; 
	
	cout << "fiction books: " << fiction_counter << endl;
	cout << "tech books: " << tech_counter << endl;
}

int main()
{
	vector<Book*> library = 
	{
		new FictionBook("Sharlotte Bronte", "Jain Air"),
		new FictionBook("Jack London", "White Fang"),
		new FictionBook("Ray Bredberry", "Dandelion Wine"),
		new TechBook("Bjern Straustrup", "C++ programming"),
		new TechBook("Atanasiyan", "Planimetriya"),
	};
	
	for(int i=0; i<library.size(); i++)
	{
		library[i]->Print();
	}
	
	TaskV(library);

	for(int i=0; i<library.size(); i++)
	{
		delete library[i];
	}
	
	return 0;
}
