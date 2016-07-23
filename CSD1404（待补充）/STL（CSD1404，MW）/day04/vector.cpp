#include <iostream>
#include <vector>
using namespace std;
void print (vector<int>& vec) {
	size_t size = vec.size (); // 获取大小
	cout << "大小：" << size << endl;
	cout << "内容：[ ";
	for (size_t i = 0; i < size; ++i)
		cout << vec[i] << ' '; // 下标访问
	cout << ']' << endl;
}
int main (void) {
	vector<int> v1; // 构造空向量
	print (v1);
	vector<int> v2 (5); // 指定初始大小
	print (v2);
	vector<int> v3 (5, 12); // 指定初始大小
	print (v3);             // 和元素初始值
	int a[] = {13, 14, 15, 16, 17};
//vector<int> v4 (a, a + 5); // 用容器构造
	vector<int> v4 (&a[0], &a[5]);
	print (v4);
	v4.push_back (18);
	print (v4);
	v4.pop_back ();
	print (v4);
	vector<int>::iterator it = v4.begin ();
	++it;
	it = v4.insert (it, 12);
	cout << *it << endl;
	print (v4);
	it = v4.begin ();
	++++++it;
	it = v4.erase (it);
	cout << *it << endl;
	print (v4);
	v4.resize (3);
	print (v4);
	v4.resize (7);
	print (v4);
	v4.clear ();
	print (v4);
	return 0;
}
