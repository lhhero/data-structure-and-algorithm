char* strcpy(char* dst,const char* src)
{
	assert(dst != NULL && src != NULL);
	char* addr = dst;
	while((*dst++ = *src++) != '\0');
	return addr;
}

unsigned int strlen(const char* str)
{
	assert(str != NULL);
	unsigned int len = 0;
	while(*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

//若dst与src地址重叠，行为未定义
void* mymemcpy(void* dst, void* src, size_t count)
{
   char *ret = (char *)dst;
   char *dst_t = (char*)dst;
   char *src_t = (char *)src;

   while (count--)
       *dst_t++ = *src_t++; 

	return ret;
}      


void *my_memmove(void *dst,const void *src,int count)

{
   char *ret = (char *)dst;
   char *dst_t;
   char *src_t;

   //地址重叠，从后往前复制
   if ((src < dst) && dst < (src+count))
    {
    	dst_t = (char *)dst + count - 1;
		src_t = (char *)src + count - 1;
		while (count--)
    		*dst_t-- = *src_t--;	
	}
	
	else
	{
		dst_t = (char *)dst;
		src_t = (char *)src;
		while (count--)
     		*dst_t++ = *src_t++;
	}
	return ret;
}


/**
 * string 类的简单实现
 */

class String
{
public:
	String(const char *str = NULL);
	String(const String &other);
	~String(void);
	String & operator=(const String &other);
	bool operator==(const String &str);
	friend ostream & operator<<(ostream& o,const String &str);
private:
	char *m_data;
};

/*
	构造、析构、拷贝构造、赋值运、流输出运算
*/

String::String(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data='\0';
	}
	else
	{
		int len=strlen(str);
		m_data = new char[len+1];
		strcpy(m_data,str);
	}
}
String::~String(void)
{
	delete [] m_data;
}

String::String(const String &other)
{
	int len = strlen(other.m_data);
	m_data = new char[len+1];
	strcpy(m_data,other.m_data);
}

String & String::operator=(const String &other)
{
	if (this == &other)
		return *this;

	delete [] m_data;
	m_data = NULL;

	int len = strlen(other.m_data);
	m_data = new char[len+1];
	strcpy(m_data,other.m_data);

	return *this;
}

bool String::operator==(const String &str)
{
	return strcmp(m_data,str.m_data) == 0;
}

ostream & operator<<(ostream &os,const String &str)
{
	os<<str.m_data;
	return os;
}


