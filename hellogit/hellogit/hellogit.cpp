// hellogit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
using namespace std;

template<typename T> inline size_t _sizeof(T p)
{
	return (char*)(&p+1)-(char*)(&p);
}

class MString{
public:
	MString(const char* str = NULL)
	{
		if( NULL == str)
		{
			m_pBuffer = NULL;
		}
		else
		{
			size_t len = _strlen(str);  
			m_pBuffer = new char[len + 1];
			_strcpy(m_pBuffer, str);
		};
	}
	MString(const MString& str):m_pBuffer(NULL)
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
		size_t len = _strlen(str.m_pBuffer);

		char* tmp = new char[len + 1];
		_strcpy(tmp, str.m_pBuffer);
        delete[] m_pBuffer;

        m_pBuffer = tmp;

		return *this;
	}
	operator char* ()
	{
		return m_pBuffer;
	}
	size_t GetLength()
	{
		return _strlen(m_pBuffer);
	}
private:
	char* m_pBuffer;
protected:
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
};

int _tmain(int argc, _TCHAR* argv[])
{
	MString str = "test",t = "t";
	MString str2 = str;
	str2 = t;

	cout<<str2<<endl;

	cout<<str2.GetLength();
	cin.get();
	return 0;
}

