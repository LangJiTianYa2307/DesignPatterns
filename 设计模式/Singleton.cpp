#include "Singleton.h"

/*
	����ӵ����ȫ�ֱ�����ͬ����ȱ�㡣 �������Ƿǳ����ã� ��ȴ���ƻ������ģ�黯���ԡ�
	��ĳЩ�����������У� �㲻��ʹ�������ڵ������ࡣ ��Ҳ������ʹ�õ����ࡣ �����������£� �����ƻ��ڴ�����Ԫ����ʱ���֡�
*/

Singleton* Singleton::singleton{nullptr};
mutex Singleton::mutex_;

Singleton* Singleton::GetInstance(const string& value)
{
	lock_guard<mutex> lock(mutex_);
	if (singleton == nullptr)
	{
		singleton = new Singleton(value);
	}
	return singleton;
}
