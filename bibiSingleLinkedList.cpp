#include<string>
#include<iostream>
using namespace std;

class bibilist
{
	int ListSize;

public:
	struct Node
	{
		Node(size_t data) {
			this->data = data;
		}

		size_t data;
		Node* next = nullptr;
	};

	Node* head = nullptr;


	int at(int index)
	{
		if (index > ListSize - 1) {
			cout << "your index is bigger than the list" << endl;
		}

		int counter = 0; //counter to get to the right index

		Node* current = head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->next; //iterator for the list
			counter++;
		}

	}

	int get_size() {
		return ListSize;
	}

	void push_back(int value) {
		if (head == nullptr) {
			head = new Node(value);
		}
		else {
			Node* current = this->head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = new Node(value);
		}
		ListSize++;

	}

	void push_front(int value)
	{
		//
		if (head == nullptr) {
			head = new Node(value);
		}
		else {
			//save the data in the head
			Node* current_head = this->head;
			head = new Node(value);
			head->next = current_head;
		}
		ListSize++;
	}

	void insert(size_t value, int index)
	{
		if (index <= ListSize) {
			if (index == 0)
			{
				push_front(value);
			}
			else {
				//get to the index
				Node* previous = this->head;
				for (int i = 0; i < index - 1; i++)
				{
					previous = previous->next;
				}
				//create a new node
				Node* newNode = new Node(value);
				if (previous->next != nullptr) {
					//save the data in the node at index
					Node* current = previous->next;

					//change the address on a previous node
					previous->next = newNode;

					//change the address on the next node
					newNode->next = current;
					ListSize++;
				}
				else
				{
					push_back(value);
				}
			}
		}
		else
		{
			cout << "your index is out of the list" << endl;
		}

	}

	void pop_front()
	{
		if (head != nullptr)
		{
			Node* toDelete = head;
			head = head->next;
			delete toDelete;
		}
		ListSize--;
	}

	void remove_at(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node* previous = this->head; //creating var which will contain the adress to data at the index; 
			for (int i = 0; i < index - 1; i++) //loop to get to the wanted note;
			{
				previous = previous->next;
			}
			Node* toDelete = previous->next; //var to keep data from the deleted node
			previous->next = toDelete->next; //var to change the pointer for a previous node
			delete toDelete;
			ListSize--;
		}
	}

	void pop_back()
	{
		remove_at(ListSize - 1);
	}

};


int main()
{
	bibilist lst;

	//PUSH_FRONT
	lst.push_back(8);
	lst.push_back(11);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(10);

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	//REMOVE_AT
	lst.remove_at(0);

	cout << "\nafter removal\n" << endl;

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	//POP_BACK
	cout << "\npop_back\n" << endl;

	lst.pop_back();

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	//PUSH_FRONT
	cout << "\npush_front\n" << endl;

	lst.push_front(7);

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	cout << "\npush_front\n" << endl;

	lst.push_front(2);

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	//POP_FRONT
	cout << "\npop_front\n" << endl;

	lst.pop_front();

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	cout << "\npop_front\n" << endl;

	lst.pop_front();

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	//INSERT
	cout << "\ninsert\n" << endl;

	lst.insert(22, 3);

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}

	lst.insert(1, 1);

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst.at(i) << endl;
	}


	lst.at(-1);

	return 0;
}
