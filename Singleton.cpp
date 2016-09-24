/*静态成员实例懒汉式*/
class Singleton
{
private:
    static Singleton* m_instance;
    Singleton(){}
public:
    static Singleton* getInstance();
};
Singleton* Singleton::m_instance = NULL;
Singleton* Singleton::getInstance()
{
    if(NULL == m_instance)
    {
        Lock();//借用其它类来实现，如boost
        if(NULL == m_instance)
        {
            m_instance = new Singleton;
        }
        UnLock();
    }
    return m_instance;
}
/*上面代码很简单，但是会存在内存泄漏的问题，new出来的东西始终没有释放，下面是一种饿汉式的一种改进。*/
class CSingleton  
{  
private:  
    CSingleton()  
    {  
    }  
    static CSingleton *m_pInstance;  
    class CGarbo   
    {  
    public:  
        ~CGarbo()  
        {  
            if(CSingleton::m_pInstance)  
                delete CSingleton::m_pInstance;  
        }  
    };  
    static CGarbo Garbo;   
public:  
    static CSingleton * GetInstance()  
    {  
        if(m_pInstance == NULL)  
            m_pInstance = new CSingleton();  
        return m_pInstance;  
    }  
};

/*饿汉式，以空间换时间；饿汉式是线程安全的,在类创建的同时就已经创建好一个静态的对象供系统使用,以后不再改变。*/
class Singleton
{
private:
    Singleton(){}
public:
    static Singleton* getInstance()
    {
        static Singleton instance;
        return &instance; 
    }
};
