#include <iostream>

template<typename T>
struct ListNode
{
	T val;
	ListNode* next;
};

template<typename T>
void appendList(ListNode<T>*& head, const T& val)
{
	ListNode<T>* newNode = new ListNode<T>;
	newNode->val = val;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		ListNode<T>* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

template <typename T>
void printList(ListNode<T>*& head)
{
	ListNode<T> *current = head;
	while (current != nullptr)
	{
		std::cout << current->val << " ";
		current = current->next;
	}
}

template<typename T>
void reorderList(ListNode<T>* head)
{
	ListNode<T>* nElement = head;
	ListNode<T>* firstElement = head;
	ListNode<T>* ptr_preLast = head;

	if (head != nullptr)
	{
		//получение n элемента
		while (nElement->next != nullptr)
		{
			nElement = nElement->next;
		}

		//получение предпоследнего элемента
		while (ptr_preLast != nElement)
		{
			if (ptr_preLast->next != nElement) 
				ptr_preLast = ptr_preLast->next;
			else break;
		}
	}
	else 
	{
		std::cerr << "Node is empty.\n";
		return;
	}

	if (ptr_preLast == nElement || firstElement == ptr_preLast) 
	{
		std::cerr << "Node must have 3 or more elements to use this function\n";
		return;
	}

	//перестановка n элемента 
	ptr_preLast->next = nullptr; 
	nElement->next = head->next; 
	head->next = nElement;
}

template <typename T>
void deleteList(ListNode<T>*& head)
{
	ListNode<T>* current = head;
	ListNode<T>* next;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

void main()
{
	uint16_t size = 5; //размер списка
	ListNode<uint16_t> *head = nullptr;

	for (uint16_t i = 1; i <= size; i++)
	{
		appendList<uint16_t>(head, uint16_t(i));
	}

	std::cout << "head = [ ";
	printList(head);
	std::cout << "]\n";

	reorderList(head);

	if (size > 2)
	{
		std::cout << "reodered list = [ ";
		printList(head);
		std::cout << "]\n";
	}
	
	deleteList(head);
	std::cout << "enter something to close programm..\n"; //чтобы программа в .exe не закрывалась сразу
	std::cin >> size;
}
