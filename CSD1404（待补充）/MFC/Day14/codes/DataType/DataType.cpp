// DataType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>//΢��atl��
#include <comdef.h>//��׼c++��
// 1 COM���ַ�������
void TestBSTR()
{
    //1 �����ַ���
	BSTR bstrText=SysAllocString(L"Hello");
	//2 ʹ��...
    
	//3 �ͷ��ַ���
	SysFreeString(bstrText);
	// 4 ��װ���ʹ��
	CComBSTR bstrText2("Hello");
	printf("�ַ�������:%d\n",bstrText2.Length());
    _bstr_t bstrText3("Hello");
	printf("�ַ�������:%d\n",bstrText3.length());
}
// 2 �ɱ�����
void VariantTest()
{
	// 1 ʹ�ÿɱ����ͱ�ʾ����100
    VARIANT varInt;
	varInt.vt=VT_I4;
	varInt.lVal=100;
	// 2 ʹ�ÿɱ����ͱ�ʾָ��һ������ֵ��ָ�� 
    long nValue=125;
	VARIANT varIntPtr;
    varIntPtr.vt= VT_BYREF|VT_I4;
	varIntPtr.plVal=&nValue;
	// 3 ��װ���ʹ��
	CComVariant varInt2(100);
    _variant_t varInt3((long)100);
} 
int main(int argc, char* argv[])
{
    TestBSTR();
	return 0;
}

