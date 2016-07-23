// 声明网络日志发送器类
#ifndef _SOCKETSENDER_H
#define _SOCKETSENDER_H
#include "logsender.h"
// 网络日志发送器类
class SocketSender : public LogSender {
public:
	// 构造器
	SocketSender (
		const string& failFile, // 发送失败文件
		short         port,     // 服务器端口号
		const string& ip = "127.0.0.1"
		                        // 服务器IP地址
	);
	// 发送日志
	void sendLog (list<MLogRec>& logs)
		throw (ClientException);
private:
	// 读取发送失败文件
	void readFailFile (list<MLogRec>& logs)
		throw (ReadException);
	// 连接服务器
	void connectServer (void)
		throw (SocketException);
	// 发送数据
	void sendData (list<MLogRec>& logs)
		throw (SendException);
	// 保存发送失败文件
	void saveFailFile (list<MLogRec>& logs)
		throw (SaveException);
	string m_failFile; // 发送失败文件
	short  m_port;     // 服务器端口号
	string m_ip;       // 服务器IP地址
	int    m_sockfd;   // 套接字描述符
};
#endif // _SOCKETSENDER_H
