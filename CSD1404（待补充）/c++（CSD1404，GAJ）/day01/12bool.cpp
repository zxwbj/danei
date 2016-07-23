%:include <iostream>
using namespace std;
int main()<%
    bool  flag;
    flag="abc";
		//flag=NULL;
		if(flag)<%
		    cout << "flag is true" << endl;
		}else{
		    cout << "flag is false" << endl;
		}
    int  x=28;
		x=x+flag;
    cout << x << endl;
		cout << &x << endl;
		cout << bitand x << endl;
		/* 默认作为整数输出 */
		cout << flag << endl;
		/* 以true false 的形式输出 */
		cout << boolalpha << flag << endl;
}


