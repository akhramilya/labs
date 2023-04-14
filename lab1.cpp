#include <iostream>
#include <vector>

using namespace std;

enum BookType
{
	FICTION,  // 0
	TECH      // 1
};

class Book
{
	string author;
	string name;
	BookType type;
public:
	Book(string a, string n, BookType t)
	{
		author = a;
		name = n;
		type = t;
	}
	
	BookType GetType() { return type; }
	
	void Print()
	{
		cout << author << " " << name<< " ";
		if(type == FICTION) 
			cout << "(Fiction)";
		else if(type == TECH)
			cout << "(Tech)";
		cout << endl;
	}
};

void TaskB(vector<Book*> library) {
	int fiction_counter = 0;
	int tech_counter = 0;

	for(int i=0; i<library.size(); i++)
	{
		switch(library[i]->GetType())
		{
			case FICTION: 
				fiction_counter++;
			break;
			case TECH:
				tech_counter++;
			break;
		}
	}
	cout << "fiction books: " << fiction_counter << endl;
	cout << "tech books: " << tech_counter << endl;
	
}

int main()
{
	vector<Book*> library = 
	{
		new Book("Sharlotte Bronte", "Jain Air", FICTION),
		new Book("Jack London", "White Fang", FICTION),
		new Book("Bjern Straustrup", "C++ programming", TECH),
		new Book("Atanasiyan", "Planimetriya", TECH),
	};
	
	for(int i=0; i<library.size(); i++)
	{
		library[i]->Print();
	}
	
	TaskB(library);
	
	for(int i=0; i<library.size(); i++)
	{
		delete library[i];
	}
	
	return 0;
}
