#include "Singleton.h"

/*
	单例拥有与全局变量相同的优缺点。 尽管它们非常有用， 但却会破坏代码的模块化特性。
	在某些其他上下文中， 你不能使用依赖于单例的类。 你也将必须使用单例类。 绝大多数情况下， 该限制会在创建单元测试时出现。
*/

atomic<Singleton*> Singleton::singleton{nullptr};
mutex Singleton::mutex_;

//大量线程访问的时候，这种效率不高
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
			singleton = new Singleton(value);  //这种方法不好的地方可能是，对象可能没有创建完毕，然后就使用了
	}
	return singleton;
#endif
	Singleton* tmp = singleton.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(mutex_);
		tmp = singleton.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton(value);
			std::atomic_thread_fence(std::memory_order_release);//释放内存fence
			singleton.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}

