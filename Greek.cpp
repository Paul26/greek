#include <iostream>
#include <string>
using namespace std;


// Class Gamma
class Gamma
{
	private:
		char id;

	public:
		Gamma(char a_id) : id(a_id) {}

		void display()
		{
			cout << "ID: " << id << endl;
		}
};


// Class Beta
class Beta
{
	private:
		double cost;

	public:
		Beta(double a_cost) : cost(a_cost) {}

		void display()
		{
			cout << "Cost: " << cost << endl;
		}
};


// Class Alpha
class Alpha
{
	private:
		Beta* myBeta = nullptr;
		Gamma myGamma;
		string name;
		int part;

	public:
		Alpha(string a_name, int a_part, char a_id) : name(a_name), part(a_part), myGamma(a_id), myBeta(nullptr) {}

		~Alpha()
		{
			if (myBeta != nullptr)
			{
				delete myBeta;
			}
		}

		void setBeta(double a_cost)
		{
			if (myBeta != nullptr)
			{
				delete myBeta;
			}
			myBeta = new Beta(a_cost);
		}

		void display()
		{
			cout << "Alpha: " << name << " Part: " << part << endl;
			myGamma.display();
			myBeta->display();
		}
};


// Class Delta
class Delta : public Alpha
{
	private:
		string desc;

	public:
		Delta(string a_name, string a_desc, int a_part, char a_id) 
			: Alpha(a_name, a_part, a_id), desc(a_desc) {}

		void display()
		{
			Alpha::display();
			cout << "Desc: " << desc << endl;  // ******************************** Is this part correct???????
		}
};


int main()
{
	Delta* d = new Delta("paul", "desc", 2, 'D');

	d->setBeta(25);

	d->display();

	system("pause");
	return 0;
}