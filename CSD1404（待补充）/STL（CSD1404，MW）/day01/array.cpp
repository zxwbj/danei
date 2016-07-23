#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class Array {
public:
	Array (void) : m_array (NULL), m_size (0) {}
	Array (size_t size) : m_array (new T[size]),
		m_size (size) {}
	Array (Array const& that) : m_array (NULL),
		m_size (0) {
		if (that.m_array) {
			m_array = new T[that.m_size];
			for (size_t i = 0; i < that.m_size; ++i)
				m_array[i] = that.m_array[i];
			m_size = that.m_size;
		}
	}
	Array& operator= (Array const& rhs) {
		if (&rhs != this) {
			Array<T> temp = rhs;
			swap (m_array, temp.m_array);
			swap (m_size, temp.m_size);
		}
		return *this;
	}
	~Array (void) {
		if (m_array) {
			delete[] m_array;
			m_array = NULL;
		}
		m_size = 0;
	}
	size_t size (void) const {
		return m_size;
	}
	T& operator[] (size_t i) {
		if (i >= m_size)
			throw out_of_range ("数组下标越界！");
		return m_array[i];
	}
	T const& operator[] (size_t i) const {
		return const_cast<Array&> (*this)[i];
	}
	friend ostream& operator<< (ostream& os,
		Array const& array) {
		for (size_t i = 0; i < array.m_size; ++i)
			os << '(' << array[i] << ')';
		return os;
	}
private:
	T* m_array;
	size_t m_size;
};
class Student {
public:
	Student (string const& name = "",
		int age = 0, float score = 0) :
		m_name (name), m_age (age),
		m_score (score) {}
	friend ostream& operator<< (ostream& os,
		Student const& student) {
		return os << student.m_name << ','
			<< student.m_age << ','
			<< student.m_score;
	}
private:
	string m_name;
	int m_age;
	float m_score;
};
int main (void) {
	Array<int> ai (10);
	for (size_t i = 0; i < ai.size (); ++i)
		ai[i] = i;
	cout << ai << endl;
	Array<double> ad (5);
	ad[0] = 1.23;
	ad[1] = 2.34;
	ad[2] = 3.45;
	ad[3] = 4.56;
	ad[4] = 5.67;
	cout << ad << endl;
	Array<string> as (4);
	as[0] = "北京";
	as[1] = "天津";
	as[2] = "上海";
	as[3] = "重庆";
	cout << as << endl;
	Array<Student> at (3);
	at[0] = Student ("张飞", 25, 69);
	at[1] = Student ("赵云", 23, 85);
	at[2] = Student ("关羽", 35, 53);
	cout << at << endl;
	// 用类模板的实例化类实例化该类模板自身
	// ————递归实例化
	Array<Array<int> > aa (3);
	aa[0] = Array<int> (4);
	aa[1] = Array<int> (4);
	aa[2] = Array<int> (4);
	for (int i = 0; i < aa.size (); ++i)
		for (int j = 0; j < aa[i].size (); ++j)
				aa[i][j] = (i+1)*10+(j+1);
	cout << aa << endl;
	// 3页4行5列的三维数组
	Array<Array<Array<int> > > aaa (3);
	for (int i = 0; i < aaa.size (); ++i) {
		aaa[i] = Array<Array<int> > (4);
		for (int j = 0; j < aaa[i].size (); ++j)
				aaa[i][j] = Array<int> (5);
	}
	for (int i = 0; i < aaa.size (); ++i)
		for (int j = 0; j < aaa[i].size (); ++j)
				for (int k = 0; k < aaa[i][j].size ();
						++k)
						aaa[i][j][k] = (i+1)*100+(j+1)*10+
							(k+1);
	cout << aaa << endl;
	return 0;
}
