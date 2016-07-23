// 实现客户机类
#include <iostream>
using namespace std;
#include "client.h"
// 构造器
Client::Client (
	LogReader& reader, // 日志读取器
	LogSender& sender  // 日志发送器
) : m_reader (reader), m_sender (sender) {}
// 数据采集
void Client::dataMine (void)
	throw (ClientException) {
	cout << "数据采集开始..." << endl;
	// 读取并发送日志
	m_sender.sendLog (m_reader.readLog ());
	cout << "数据采集完成。" << endl;
}
