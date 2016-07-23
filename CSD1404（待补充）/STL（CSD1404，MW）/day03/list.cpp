// 双向线性链表容器及其迭代器和泛型算法
#include <cstring>
#include <iostream>
#include <stdexcept>
using namespace std;
// 双向线性链表容器
template<typename T>
class List {
public:
	// 构造、析构、拷贝构造、拷贝赋值
	List (void) :
		m_head (NULL), m_tail (NULL) {}
	~List (void) {
		clear ();
	}
	List (List const& that) :
		m_head (NULL), m_tail (NULL) {
		for (Node* node = that.m_head; node;
			node = node->m_next)
			push_back (node->m_data);
	}
	List& operator= (List const& rhs) {
		if (&rhs != this) {
			List temp = rhs;
			swap (m_head, temp.m_head);
			swap (m_tail, temp.m_tail);
		}
		return *this;
	}
	// 获取首元素
	T& front (void) {
		if (empty ())
			throw underflow_error ("链表下溢！");
		return m_head->m_data;
	}
	T const& front (void) const {
		return const_cast<List*> (this)->front ();
	}
	// 向首部压入
	void push_front (T const& data) {
		m_head = new Node (data, NULL, m_head);
		if (m_head->m_next)
			m_head->m_next->m_prev = m_head;
		else
			m_tail = m_head;
	}
	// 从首部弹出
	void pop_front (void) {
		if (empty ())
			throw underflow_error ("链表下溢！");
		Node* next = m_head->m_next;
		delete m_head;
		m_head = next;
		if (m_head)
			m_head->m_prev = NULL;
		else
			m_tail = NULL;
	}
	// 获取尾元素
	T& back (void) {
		if (empty ())
			throw underflow_error ("链表下溢！");
		return m_tail->m_data;
	}
	T const& back (void) const {
		return const_cast<List*> (this)->back ();
	}
	// 向尾部压入
	void push_back (T const& data) {
		m_tail = new Node (data, m_tail);
		if (m_tail->m_prev)
			m_tail->m_prev->m_next = m_tail;
		else
			m_head = m_tail;
	}
	// 从尾部弹出
	void pop_back (void) {
		if (empty ())
			throw underflow_error ("链表下溢！");
		Node* prev = m_tail->m_prev;
		delete m_tail;
		m_tail = prev;
		if (m_tail)
			m_tail->m_next = NULL;
		else
			m_head = NULL;
	}
	// 删除所有匹配元素
	void remove (T const& data) {
		for (Node* node = m_head, *next; node;
			node = next) {
			next = node->m_next;
			if (equal (node->m_data, data)) {
				if (node->m_prev)
					node->m_prev->m_next = node->m_next;
				else
					m_head = node->m_next;
				if (node->m_next)
					node->m_next->m_prev = node->m_prev;
				else
					m_tail = node->m_prev;
				delete node;
			}
		}
	}
	// 清空
	void clear (void) {
		for (Node* next; m_head; m_head = next) {
			next = m_head->m_next;
			delete m_head;
		}
		m_tail = NULL;
	}
	// 判空
	bool empty (void) const {
		return ! m_head && ! m_tail;
	}
	// 大小
	size_t size (void) const {
		size_t counter = 0;
		for (Node* node = m_head; node;
			node = node->m_next)
			++counter;
		return counter;
	}
	/*
	T& at (size_t i) {
		// 返回链表中第i号节点中的数据
	}
	Node* begin (void) {
		// 返回头节点指针
	}
	*/
	// 插入输出流
	friend ostream& operator<< (ostream& os,
		List const& list) {
		for (Node* node = list.m_head; node;
			node = node->m_next)
			os << *node;
		return os;
	}
private:
	// 节点模板
	class Node {
	public:
		Node (T const& data, Node* prev = NULL,
			Node* next = NULL) : m_data (data),
			m_prev (prev), m_next (next) {}
		friend ostream& operator<< (ostream& os,
			Node const& node) {
			return os << '(' << node.m_data << ')';
		}
		T     m_data; // 数据
		Node* m_prev; // 前指针
		Node* m_next; // 后指针
	};
	bool equal (T const& x, T const& y) const {
		return x == y;
	}
	Node* m_head; // 头指针
	Node* m_tail; // 尾指针
public:
	// 正向迭代器
	class Iterator {
	public:
		Iterator (Node* head = NULL,
			Node* tail = NULL, Node* node = NULL) :
			m_head (head), m_tail (tail),
			m_node (node) {}
		bool operator== (
			Iterator const& rhs) const {
			return m_node == rhs.m_node;
		}
		bool operator!= (
			Iterator const& rhs) const {
			return ! (*this == rhs);
		}
		Iterator& operator++ (void) {
			if (m_node)
				m_node = m_node->m_next;
			else
				m_node = m_head;
			return *this;
		}
		const Iterator operator++ (int) {
			Iterator old = *this;
			++*this;
			return old;
		}
		Iterator& operator-- (void) {
			if (m_node)
				m_node = m_node->m_prev;
			else
				m_node = m_tail;
			return *this;
		}
		const Iterator operator-- (int) {
			Iterator old = *this;
			--*this;
			return old;
		}
		T& operator* (void) const {
			return m_node->m_data;
		}
		T* operator-> (void) const {
			return &**this;
		}
	private:
		Node* m_head;
		Node* m_tail;
		Node* m_node;
		friend class List;
	};
	// 获取起始正向迭代器
	// ————指向第一个元素的迭代器
	Iterator begin (void) {
		return Iterator (m_head, m_tail, m_head);
	}
	// 获取终止正向迭代器
	// ————指向最后一个元素的下一个位置的迭代器
	Iterator end (void) {
		return Iterator (m_head, m_tail);
	}
	// 在正向迭代器loc之前插入
	// 同时返回指向新插入元素的迭代器
	Iterator insert (Iterator loc,
		T const& data) {
		if (loc == end ()) {
			push_back (data);
			return Iterator (m_head, m_tail,
				m_tail);
		}
		else {
			Node* node = new Node (data,
				loc.m_node->m_prev, loc.m_node);
			if (node->m_prev)
				node->m_prev->m_next = node;
			else
				m_head = node;
			node->m_next->m_prev = node;
			return Iterator (m_head, m_tail, node);
		}
	}
	// 删除正向迭代器loc所指向的元素
	// 同时返回被删除元素下一个位置的迭代器
	Iterator erase (Iterator loc) {
		if (loc == end ())
			throw invalid_argument ("无效参数！");
		if (loc.m_node->m_prev)
			loc.m_node->m_prev->m_next =
				loc.m_node->m_next;
		else
			m_head = loc.m_node->m_next;
		if (loc.m_node->m_next)
			loc.m_node->m_next->m_prev =
				loc.m_node->m_prev;
		else
			m_tail = loc.m_node->m_prev;
		Node* next = loc.m_node->m_next;
		delete loc.m_node;
		return Iterator (m_head,  m_tail, next);
	}
};
template<>
bool List<char const*>::equal (
	char const* const& x,
	char const* const& y) const {
	return ! strcmp (x, y);
}
// 泛型快速排序算法函数
template<typename iterator>
void quick_sort (iterator begin,
	iterator end) {
	iterator pivot = begin;
	iterator last = end;
	--last;
	for (iterator i = begin, j = last; i != j;){
		while (! (i == pivot || *pivot < *i))
			++i;
		if (i != pivot) {
			swap (*i, *pivot);
			pivot = i;
		}
		while (! (j == pivot || *j < *pivot))
			--j;
		if (j != pivot) {
			swap (*j, *pivot);
			pivot = j;
		}
	}
	iterator it = begin;
	++it;
	if (pivot != begin && pivot != it)
		quick_sort (begin, pivot);
	it = pivot;
	++it;
	if (it != end && it != last)
		quick_sort (it, end);
}
template<typename iterator,
	typename comparator>
void quick_sort (iterator begin,
	iterator end, comparator cmp) {
	iterator pivot = begin;
	iterator last = end;
	--last;
	for (iterator i = begin, j = last; i != j;){
		while (! (i == pivot || cmp (*pivot, *i)))
			++i;
		if (i != pivot) {
			swap (*i, *pivot);
			pivot = i;
		}
		while (! (j == pivot || cmp (*j, *pivot)))
			--j;
		if (j != pivot) {
			swap (*j, *pivot);
			pivot = j;
		}
	}
	iterator it = begin;
	++it;
	if (pivot != begin && pivot != it)
		quick_sort (begin, pivot, cmp);
	it = pivot;
	++it;
	if (it != end && it != last)
		quick_sort (it, end, cmp);
}
void test1 (void) {
	List<int> list1;
	list1.push_front (40);
	list1.push_front (30);
	list1.push_front (20);
	list1.push_front (10);
	cout << list1 << endl; // 10 20 30 40
	list1.pop_front ();
	cout << list1 << endl; // 20 30 40
	list1.front () -= 10;
	cout << list1 << endl; // 10 30 40
	List<int> const& cr = list1;
	cout << cr.front () << endl;
//cr.front () += 10;
	list1.push_back (50);
	list1.push_back (60);
	list1.push_back (70);
	list1.push_back (80);
	cout << list1 << endl;
	// 10 30 40 50 60 70 80
	list1.pop_back ();
	cout << list1 << endl; // 10 30 40 50 60 70
	list1.back () += 10;
	cout << list1 << endl; // 10 30 40 50 60 80
	List<int> const* cp = &list1;
	cout << cp->back () << endl;
//cp->back () -= 10;
	list1.push_front (50);
	list1.push_back (50);
	cout << list1 << endl;
	// 50 10 30 40 50 60 80 50
	list1.remove (50);
	cout << list1 << endl; // 10 30 40 60 80
	cout << list1.size () << endl; // 5
	cout << boolalpha << list1.empty () << endl;
	// false
	list1.clear ();
	cout << list1.size () << endl; // 0
	cout << list1.empty () << endl; // true
	list1.push_back (100);
	list1.push_back (200);
	list1.push_back (300);
	List<int> list2 = list1; // 拷贝构造
	list1.pop_front ();
	list2.pop_back ();
	cout << list1 << endl; // 200 300
	cout << list2 << endl; // 100 200
	list2 = list1; // 拷贝赋值
	list1.push_front (100);
	list2.push_back (400);
	cout << list1 << endl; // 100 200 300
	cout << list2 << endl; // 200 300 400
}
void test2 (void) {
//char const* sa[] = {"北京", "天津", "上海",
//	"重庆"};
	char sa[][32] = {"北京", "天津", "上海",
		"重庆"};
	List<string> list1;
	for (size_t i = 0; i < sizeof (sa) /
		sizeof (sa[0]); ++i)
		list1.push_back (sa[i]);
	cout << list1 << endl;
	list1.remove ("上海");
	cout << list1 << endl;
	List<char const*> list2;
	for (size_t i = 0; i < sizeof (sa) /
		sizeof (sa[0]); ++i)
		list2.push_back (sa[i]);
	cout << list2 << endl;
	list2.remove ("上海");
	cout << list2 << endl;
}
class Student {
public:
	Student (string const& name, int age) :
		m_name (name), m_age (age) {};
	/*
	bool operator< (Student const& rhs) const {
		if (m_name == rhs.m_name)
			return m_age > rhs.m_age;
		return m_name < rhs.m_name;
	}
	*/
	string m_name;
	int m_age;
};
void test3 (void) {
	List<int> list;
	for (int i = 10; i < 100; i += 10)
		list.push_back (i);
	cout << list << endl;
	for (List<int>::Iterator it = list.begin ();
		it != list.end (); ++it)
		*it *= *it;
	cout << list << endl;
	List<Student> ls;
	ls.push_back (Student ("张飞", 25));
	ls.push_back (Student ("赵云", 20));
	ls.push_back (Student ("关羽", 35));
	for (List<Student>::Iterator it =
		ls.begin (); it != ls.end (); ++it)
		cout << '(' << it->m_name << ','
			<< it->m_age << ')';
	cout << endl;
}
void test4 (void) {
	List<int> list;
	list.push_back (10);
	list.push_back (20);
	list.push_back (30);
	list.push_back (40);
	list.push_back (50);
	cout << list << endl;
	List<int>::Iterator it = list.begin ();
	++++it;
	list.insert (
		list.insert (
			list.insert (it, 27), 25), 23);
	cout << list << endl;
	it = list.end ();
	------it;
	list.erase (list.erase (list.erase (it)));
	cout << list << endl;
}
class IntCmp {
public:
	IntCmp (bool raise = true) :
		m_raise (raise) {}
	bool operator() (int const& x,
		int const& y) {
		return m_raise ? (x < y) : (y < x);
	}
private:
	bool m_raise;
};
bool StrCmp (string const& x,
	string const& y) {
	return y < x;
}
class StuCmp {
public:
	bool operator() (Student const& a,
		Student const& b) const {
		if (a.m_name == b.m_name)
			return a.m_age > b.m_age;
		return a.m_name < b.m_name;
	}
};
void test5 (void) {
	int ai[] = {13, 29, 17, 32, 24, 17, 29};
//quick_sort (&ai[0], &ai[7]);
//quick_sort (&ai[0], &ai[7], IntCmp ());
	quick_sort (&ai[0], &ai[7], IntCmp (false));
	for (size_t i = 0; i < sizeof (ai) /
		sizeof (ai[0]); ++i)
		cout << ai[i] << ' ';
	cout << endl;
	List<string> ls;
	ls.push_back ("jinan");
	ls.push_back ("weifang");
	ls.push_back ("heze");
	ls.push_back ("zibo");
	ls.push_back ("binzhou");
	ls.push_back ("heze");
	ls.push_back ("weifang");
//quick_sort (ls.begin (), ls.end ());
	quick_sort (ls.begin (), ls.end (), StrCmp);
	for (List<string>::Iterator it =
		ls.begin (); it != ls.end (); ++it)
		cout << *it << ' ';
	cout << endl;
	List<Student> lt;
	lt.push_back (Student ("张飞", 23));
	lt.push_back (Student ("赵云", 20));
	lt.push_back (Student ("关羽", 40));
	lt.push_back (Student ("赵云", 18));
	lt.push_back (Student ("刘备", 50));
	lt.push_back (Student ("张飞", 44));
	lt.push_back (Student ("刘备", 80));
	lt.push_back (Student ("赵云", 35));
//quick_sort (lt.begin (), lt.end ());
	quick_sort (lt.begin (), lt.end (),
		StuCmp ());
	for (List<Student>::Iterator it =
		lt.begin (); it != lt.end (); ++it)
		cout << it->m_name << "，" << it->m_age
			<< endl;
}
int main (void) {
//test1 ();
//test2 ();
//test3 ();
//test4 ();
	test5 ();
	return 0;
}
