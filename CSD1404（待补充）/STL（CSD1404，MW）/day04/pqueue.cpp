#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;
class Student {
public:
	Student (string const& name = "",
		int age = 0, int score = 0) :
		m_name (name), m_age (age),
		m_score (score) {}
	friend ostream& operator<< (ostream& os, 
		Student const& student) {
		return os << student.m_name << "，"
			<< student.m_age << "，"
			<< student.m_score;
	}
	bool operator< (Student const& rhs) const {
		return m_score < rhs.m_score;
	}
private:
	string m_name;
	int m_age;
	int m_score;
	friend class StuCmp;
};
class StuCmp {
public:
	bool operator() (Student const& a,
		Student const& b) const {
		return a.m_age < b.m_age;
	}
};
int main (void) {
//priority_queue<Student,
//	vector<Student> > ps;
	priority_queue<Student,
		vector<Student>, StuCmp> ps;
	ps.push (Student ("张飞", 25, 85));
	ps.push (Student ("赵云", 22, 95));
	ps.push (Student ("关羽", 35, 75));
	ps.push (Student ("刘备", 25, 65));
	ps.push (Student ("曹操", 15, 95));
	while (! ps.empty ()) {
		cout << ps.top () << endl;
		ps.pop ();
	}
	return 0;
}

