#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int>  datas;
		datas.push_back(9);
		datas.push_back(5);
		datas.push_back(2);
		datas.push_back(7);
		/* 迭代器 */
		list<int>::iterator it;
		it=datas.begin();
    cout << *it << endl;
		it++;
    cout << *it << endl;
    /* 返回最后一个元素 后面的位置对应的
			 迭代器 
    datas.end();*/
		cout << "-------------" << endl;
    it=datas.begin();
		while(it!=datas.end()){
		    cout << *it++ << endl;
		}
}


