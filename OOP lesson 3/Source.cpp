#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// ������ 1.
class Client
{
private:
	std::string _name;
	int _id;
	static std::vector<Client*> _clients;
	
	void ShowClient()
	{
		std::cout << "Name: " << _name << "\n";
		std::cout << "Id: " << _id << "\n";
	}

public:
	Client(std::string name, int id) : _name(name), _id(id)
	{
		_clients.push_back(this); // this ������ _id , _name ����������������.
	}

	static void ShowClients()
	{
		for (const auto& it : _clients)
			it->ShowClient();
	}
	
};

std::vector<Client*> Client::_clients; // �������������� ����������� ����������. ��� ��� ���������. 

// ������ 2.
class Vector
{
private:
	int _size;
	int* _massivPrt;
public:
	Vector()
	{
		_size = 0;
		_massivPrt = nullptr;
	}
	
	

	void Push_Back(int element)
	{
		_size++;
		int *newMassiv = new int[_size];
		
		if (_massivPrt == nullptr)
		{
			newMassiv[0] = element;
			_massivPrt = newMassiv;
			return;
		}
		
		for (int i = 0; i < _size - 1; ++i)
			newMassiv[i] = _massivPrt[i];

		newMassiv[_size - 1] = element;

		/*int* temp = _massivPrt;
		delete[]temp;*/

		delete[]_massivPrt;

		_massivPrt = newMassiv;
	}

	void ShowElements()
	{
		for (int i = 0; i < _size - 1; ++i)
			std::cout << i << " element: " << _massivPrt[i] << "\n";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	// ������ 1.
	/*Client* client = new Client("John", 20);
	Client* client2 = new Client("Alex", 35);
	Client* client3 = new Client("Bob", 9);
	Client::ShowClients();
	*/

	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	// �������� SOLID.
	/*

	S - single responsibility principle
	������� ������ ���������������.

	class ClientServer // ������ ������ private, �.� ��� ������� ���������.
	{
	public:
		void ShowClients(std::vector <Client*> clients)
		{
			for (const auto& it : clients)
				it->Pay();
		}
	};
	*/

	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	// �������� SOLIO.

	/* O = open closed principle

	class Animal
	{
	private:
		std::string _type;
	public:
		Animal(std::string type) : _type(type) { }

		// ��� �� ���������� �������.
		/*
		std::string GetSound() const // �� �� ������� �������� ����������� ���.
		{
			return _type;
		}

		virtual std::string GetSound() = 0;
	};

	// ====================================================================

	class Cow : public Animal
	{
	public:
		Cow() : Animal("Cow") {

		}

		std::string GetSound() override {
			return "MYMYM";
		}
	};

	// ====================================================================

	class Cat : public Animal
	{
	public:
		Cat() : Animal("Cat") {

		}

		std::string GetSound() override {
			return "Mya";
		}
	};

	// ====================================================================

	class Dog : public Animal
	{
	public:
		Dog() : Animal("Dog") {

		}

		std::string GetSound() override {
			return "Gawww";
		}
	};

	// ====================================================================

	// ������ ��� ����������, �� ������ ��� �����������.
	void AnimalSound(Animal & animal)
	{
		// ��� ��� �� ����������� ��������.
		if (animal.GetType() == "Lion")
			std::cout << "RRRR";
		else if (animal.GetType() == "Cat")
			std::cout << "MRR";
		else if (animal.GetType() == "Dog")
			std::cout << "GAV";
		else if (animal.GetType() == "Cow")
			std::cout << "MYMYMY";

		// ��� ���������� �������.
		std::cout << animal.GetSound() << "\n";

	}

	// ====================================================================
	
	// int main(){
	Cat* cat = new Cat();
	Dog* dog = new Dog();
	Cow* cow = new Cow();
	AnimalSound(*cat);
	AnimalSound(*dog);
	AnimalSound(*cow);
	}
	*/

	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	// ������ 2.

	Vector* vector = new Vector();
	vector->Push_Back(2);
	vector->Push_Back(3);
	vector->Push_Back(4);
	vector->Push_Back(5);
	vector->Push_Back(6);
	vector->Push_Back(7);
	vector->Push_Back(8);
	vector->ShowElements();

	return {};
}