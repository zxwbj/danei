// DataType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>//微软atl库
#include <comdef.h>//标准c++库
// 1 COM的字符串类型
void TestBSTR()
{
    //1 创建字符串
	BSTR bstrText=SysAllocString(L"Hello");
	//2 使用...
    
	//3 释放字符串
	SysFreeString(bstrText);
	// 4 封装类的使用
	CComBSTR bstrText2("Hello");
	printf("字符串长度:%d\n",bstrText2.Length());
    _bstr_t bstrText3("Hello");
	printf("字符串长度:%d\n",bstrText3.length());
}
// 2 可变类型
void VariantTest()
{
	// 1 使用可变类型表示整数100
    VARIANT varInt;
	varInt.vt=VT_I4;
	varInt.lVal=100;
	// 2 使用可变类型表示指向一个整数值的指针 
    long nValue=125;
	VARIANT varIntPtr;
    varIntPtr.vt= VT_BYREF|VT_I4;
	varIntPtr.plVal=&nValue;
	// 3 封装类的使用
	CComVariant varInt2(100);
    _variant_t varInt3((long)100);
} 
int main(int argc, char* argv[])
{
    TestBSTR();
	return 0;
}

