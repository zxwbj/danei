// 实现控制台日志发送器类
#include <iostream>
using namespace std;
#include "consolesender.h"
// 发送日志
void ConsoleSender::sendLog (
	list<MLogRec>& logs) throw () {
	cout << "发送日志开始..." << endl;
	// 遍历匹配日志记录集，逐条打印输出
	for (list<MLogRec>::iterator it =
		logs.begin (); it != logs.end (); ++it)
		cout << *it << endl;
	cout << "发送日志完成。" << endl;
}
