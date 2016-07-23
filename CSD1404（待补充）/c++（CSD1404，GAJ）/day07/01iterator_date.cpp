#include <iostream>
#include <list>
using namespace std;
struct Date{
    int  year;
		int  month;
		int  day;
		void  show(){
		    cout << year << '-' << month << '-'
						<< day << endl;
		}
};
/* 构建一个list 对象 里面放Date对象 
   把三个日期对象放入链表 然后使用 迭代器
   取得第一个元素 */
int main(){
    list<Date>   datas;
		Date   datea={2014,7,13};
		Date   dateb={2014,7,14};
		Date   datec={2014,7,15};
		datas.push_back(datea);
		datas.push_back(dateb);
		datas.push_back(datec);
    list<Date>::iterator  it;
		it=datas.begin();
		(*it).show();
		it->show();  // it++
    while(it!=datas.end()){
		    it->show();
				it++;
		}
}











