#include <iostream>
#include <cstring>
using namespace std;
int main(){
    string  var_a("hello");
		string  var_b="hello";
		if(var_a==var_b){
		    cout << "字符串相等" << endl;
		}
		var_b="test";
		cout << var_b << endl;
    /* 字符串的拼接 */
    var_b=var_b+" hello";
		cout << var_b << endl;
    var_b+=" test";
		cout << var_b << endl;
    cout << var_b[0] << endl;
    /* 求字符串长度 */
		cout << var_b.length() << endl;
    /* 把c++ 的字符串 变成 c字符串 */ 
		const char *mystr=var_b.c_str();
    cout << mystr << endl;
		cout << strlen(mystr) << endl;
}

