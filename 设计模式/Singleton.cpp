#include "Singleton.h"

/*
	����ӵ����ȫ�ֱ�����ͬ����ȱ�㡣 �������Ƿǳ����ã� ��ȴ���ƻ������ģ�黯���ԡ�
	��ĳЩ�����������У� �㲻��ʹ�������ڵ������ࡣ ��Ҳ������ʹ�õ����ࡣ �����������£� �����ƻ��ڴ�����Ԫ����ʱ���֡�
*/

atomic<Singleton*> Singleton::singleton{nullptr};
mutex Singleton::mutex_;

//�����̷߳��ʵ�ʱ������Ч�ʲ���
Singleton* Singleton::GetInstance(const string& value)
{
#if 0
	lock_guard<mutex> lock(mutex_);
	if (singleton == nullptr)
	{
		singleton = new Singleton(value);
	}
#endif
#if 0
	if (singleton == nullptr)
	{
		lock_guard<mutex> lock(mutex_);
		if(singleton == nullptr)
			singleton = new Singleton(value);  //���ַ������õĵط������ǣ��������û�д�����ϣ�Ȼ���ʹ����
	}
	return singleton;
#endif
	Singleton* tmp = singleton.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//��ȡ�ڴ�fence
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(mutex_);
		tmp = singleton.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton(value);
			std::atomic_thread_fence(std::memory_order_release);//�ͷ��ڴ�fence
			singleton.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}

