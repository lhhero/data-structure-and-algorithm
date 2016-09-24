char* strcpy(char* dst,const char* src)
{
	assert(dst != NULL && src != NULL);
	char* addr = dst;
	while((*dst++ = *src++) != '\0');
	return addr;
}

char* strcat(char*strDest,const char* strSrc)
{
	char* address = strDest;
	assert(strDest != NULL && strSrc != NULL);
	while(*strDest)
		strDest++;
	while(*strDest++ = *strSrc++)
	return address;
}

int strcmp(const char* str1,const char str2)
{
	assert(str1 != NULL && str2 != NULL);
	int ret = 0;
	while(ret = *(unsigned char*)str1-*(unsigned char*)str2 && *str1)
	{
		str1++;
		str2++;
	}
	if(ret < 0)
		ret = -1;
	else if(ret > 0)
		ret = 1;
	return ret;
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
//递归解法
unsigned int strlen(const char* str)
{
	assert(str != NULL);
	return *str == '\0' : 0 ? (1+strlen(++str));
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


/**
 * 最长回文子串，动态规划
 * 有母串s，我们用c[i, j] = 1表示子串s[i..j]为回文子串，那么就有递推式
c[i,j] = c[i+1,j−1]   if s[i]=s[j]

c[i,j] = 0           if s[i]≠s[j]
递推式表示在s[i] = s[j]情况下，如果s[i+1..j-1]是回文子串，则s[i..j]也是回文子串；如果s[i+1..j-1]不是回文子串，则s[i..j]也不是回文子串。
初始状态：
c[i][i] = 1
c[i][i+1] = 1 if s[i] == s[i+1]
上述式子表示单个字符、两个相同字符均是回文串。
 */
#define MAX_LEN 1024

int longPald(char* str)      //时间复杂度O(n^2)
{
	if(str == NULL)
		return 0;
	int len = strlen(str);
	if(len == 1)
		return 1;

	int c[MAX_LEN][MAX_LEN];
	int longest = 0;

	//初始状态
	for(int i = 0; i < len; ++i)
	{
		c[i][i] = 1;
		if(str[i] == str[i+1])
			c[i][i+1] = 1;
	}

	for(int i = 0; i < len; ++i)
	{
		for(int j = i+2; j < len; ++j)
		{
			if(str[i] == str[j])
			{
				c[i][j] = 1;
				if(c[i][j])
				{
					n = j-i+1;
					if(n > longest)
						longest = n;
				}
			}
			else
				c[i][j] = 0;	
		}
	}
	return longest;
}


/**
 * 最长公共子序列（LCS）
 * 序列X=<X0,X1,...Xm>和Y=<Y0,Y1,...Yn>
 * c[i,j] = 0     if i=0 or j=0
 * c[i,j] = c[i-1,j-1]+1 if i,j>0 and Xi=Yi
 * c[i,j] = max{c[i,j-1],c[i-1,j]} if i,j>0 and Xi != Yi
 */
int LCS(const char* X,const char* Y)
{
	int m = strlen(X);
	int n = strlen(Y);
	if(X == NULL || Y = NULL)
		return 0;
	for(int i = 1; i < m; ++i)
		c[i][0] = 0;
	for(int j = 1; j < n; ++j)
		c[0][j] = 0;
	for(int i = 1; i <=m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(X[i] == Y[j])
				c[i][j] = c[i-1][j-1]+1;
			else
				c[i][j] = max(c[i-1][j],c[i][j-1]);
		}
		return c[m][n];
	}
}
/*字符串匹配*/
