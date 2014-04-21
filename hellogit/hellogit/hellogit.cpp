// hellogit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

template<typename T> size_t _sizeof(T p)                       //去掉inline
{
	return (char*)(&p+1)-(char*)(&p);
}
char* _strcpy(char* dst, const char* src) 
{
	assert(dst !=NULL || src != NULL);
	char* r = dst;
	while ((*dst++ = *src++) != '\0');

	return r;
}
size_t _strlen(const char* str) 
{
	size_t len = 0;
	while(*str++)
		++len;
	return len;

}

class MString{
	friend ostream& operator <<(ostream& out, const MString& str)
	{
		out<<str.m_pBuffer;
		return out;
	}
public:
	MString(const char* str = NULL)
	{
		if( NULL == str)
		{
			m_pBuffer = NULL;
		}
		else
		{
			m_nLen = _strlen(str);  
			m_pBuffer = new char[m_nLen + 1];
			_strcpy(m_pBuffer, str);
		};
	}
	MString(const MString& str):m_pBuffer(NULL),m_nLen(0)
	{
		*this = str;
	}
	~MString()
	{
		delete[] m_pBuffer;
	}
	MString& operator =(const MString& str)
	{
		if(this == &str)
			return *this;
		m_nLen = str.m_nLen;

		char* tmp = new char[m_nLen + 1];
		_strcpy(tmp, str.m_pBuffer);
        delete[] m_pBuffer;

        m_pBuffer = tmp;

		return *this;
	}
	int GetLength() const  //在内部定义可以省略inline 编译器自动内联
	{
		return m_nLen;
	}
	char& operator [](int i) 
	{
		return m_pBuffer[i];
	}
	const char& operator [](int i) const
	{
		return m_pBuffer[i];
	}
	const char* c_str() const
	{
		return m_pBuffer;
	}
private:
	char* m_pBuffer;
	size_t m_nLen;
};
int _tmain(int argc, _TCHAR* argv[])
{
	
}

