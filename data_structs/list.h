

#include <utility>

template <typename T>
class ListNode
{
public:
	ListNode(const T& value, ListNode<T>* prev_node, ListNode<T>* next_node)
		: value(value),
		prev_node(prev_node),
		next_node(next_node)
	{
	}

	explicit ListNode(const T& value)
		: value(value)
	{
	}

	ListNode(const ListNode& other)
		: value(other.value),
		prev_node(other.prev_node),
		next_node(other.next_node)
	{
	}

	ListNode(ListNode&& other) noexcept
		: value(std::move(other.value)),
		prev_node(other.prev_node),
		next_node(other.next_node)
	{
	}

	ListNode& operator=(const ListNode& other)
	{
		if (this == &other)
			return *this;
		value = other.value;
		prev_node = other.prev_node;
		next_node = other.next_node;
		return *this;
	}

	ListNode& operator=(ListNode&& other) noexcept
	{
		if (this == &other)
			return *this;
		value = std::move(other.value);
		prev_node = other.prev_node;
		next_node = other.next_node;
		return *this;
	}

public:
	T value;
	ListNode* prev_node = nullptr;
	ListNode* next_node = nullptr;
};

template <typename T>
class List
{
public:
	ListNode<T>* insert(uint64_t pos, T value);
	bool delete_at(uint64_t pos);
	void push_back(T value);
	void push_front(T value);
	void pop_back();
	void pop_front();

private:
	ListNode<T>* head = nullptr;
	ListNode<T>* tail = nullptr;
};

template <typename T>
ListNode<T>* List<T>::insert(uint64_t pos, T value)
{
	if (!head)
	{
		head = new ListNode<T>(value);
		tail = head;

		return head;
	}
	else
	{
		uint64_t counter = 0;
		ListNode<T>* current = head, * node_after_insert = nullptr, * new_node = new ListNode<T>(value);
		do
		{
			current = current->next_node;
			counter++;
		} while (counter < pos && current->next_node != nullptr);

		if (current->next_node == nullptr)
		{
			current->next_node = new_node;
			new_node->prev_node = current;
			tail = new_node;
		}
		else
		{
			node_after_insert = current->next_node;

			current->next_node = new_node;
			new_node->prev_node = current;
			node_after_insert->prev_node = new_node;
			new_node->next_node = node_after_insert;
		}

		return new_node;
	}
}

template <typename T>
bool List<T>::delete_at(uint64_t pos)
{
	if (!head)
		return false;

	uint64_t counter = 0;
	ListNode<T>* current = head;
	while(current && counter <= pos)
	{
		counter++;
		current = current->next_node;
	}

	if (current == nullptr)
		return false;

	if (current == tail && current->prev_node)
		tail = current->prev_node;

	if (current == head && current->next_node)
		head = current->next_node;

	current->prev_node->next_node = current->next_node;
	delete current;
	return true;
}

template <typename T>
void List<T>::push_back(T value)
{
	if (!tail || !head)
	{
		tail = new ListNode<T>(value);
		head = tail;
	}
	else
	{
		ListNode<T>* prev_tail = tail;
		prev_tail->next_node = new ListNode<T>(value);
		prev_tail->next_node->prev_node = prev_tail;
		tail = prev_tail->next_node;
	}

}

template <typename T>
void List<T>::push_front(T value)
{
	if (!tail || !head)
	{
		head = new ListNode<T>(value);
		tail = head;
	}
	else
	{
		ListNode<T>* prev_head = head;
		prev_head->prev_node = new ListNode<T>(value);
		prev_head->prev_node->next_node = prev_head;
		head = prev_head->prev_node;
	}
}

template <typename T>
void List<T>::pop_back()
{
	if (!tail)
		return;
	else
	{
		ListNode<T>* tmp = tail, * prev_to_tail = tmp->prev_node;
		prev_to_tail->next_node = nullptr;
		tail = prev_to_tail;
		delete tmp;
	}
}

template <typename T>
void List<T>::pop_front()
{
	if (!head)
		return;
	else
	{
		ListNode<T>* tmp = head, * next_to_head = tmp->next_node;
		next_to_head->prev_node = nullptr;
		head = next_to_head;
		delete tmp;
	}
}
