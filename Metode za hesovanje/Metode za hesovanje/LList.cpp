#include "LList.h"

LList::LList()
{
	head = nullptr;
}

LList::~LList()
{
	while (!isEmpty())
	{
		deleteFromHead();
	}
}

void LList::AddtoHead(HashObject el)
{
	head = new LLNode(el, head);
}

void LList::deleteFromHead()
{
	if (isEmpty())
	{
		throw "Lista je prazna";
	}
	LLNode* tmp = head;
	head = head->next;
	delete tmp;
}

void LList::deleteEl(int key)
{
	if (!isEmpty())
	{

		if (head->next == nullptr && head->isEqual(key))
		{
			LLNode* tmp = head;
			head = nullptr;
			delete tmp;
		}
		else
		{
			LLNode* i = nullptr, * prev = nullptr;
			for (i = head; i != nullptr && !(i->isEqual(key)); i = i->next)
			{
				prev = i;
			}
			if (i != nullptr)
			{
				prev->next = i->next;
				delete i;
			}
		}
	
	}
}

LLNode* LList::GetHead()
{
	if (isEmpty())
	{
		throw "Lista je prazna";
	}
	return head;
}

HashObject LList::GetHeadEl()
{
	if (isEmpty())
	{
		throw "Lista je prazna";
	}
	return head->vrednost;
}

HashObject LList::GetEl(int key)
{
	if (isEmpty())
	{
		throw "Lista je prazna";
	}
	HashObject el;
	for (LLNode* i = head; i != nullptr; i=i->next)
	{
		if (i->vrednost.key == key)
		{
			el = i->vrednost;
		}
	}
	return el;
}

LLNode* LList::GetNode(int key)
{
	if (isEmpty())
	{
		throw "Lista je prazna";
	}
	LLNode* r = nullptr;
	for (LLNode* i = head; i != nullptr; i = i->next)
	{
		if (i->vrednost.key == key)
		{
			r = i;
		}
	}
	return r;
}

void LList::PrintAll()
{
	for (LLNode* i = head; i != nullptr ; i= i->next)
	{
		i->print();
		std::cout << "-->";
	}
	std::cout << std::endl;
}
