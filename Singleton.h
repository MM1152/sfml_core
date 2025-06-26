#pragma once
#include <iostream>
template <typename T>
class Singleton {
protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	//문법 정리 필요
	Singleton(const Singleton& singleton) = delete;
	Singleton(const Singleton&& singleton) = delete;
	Singleton& operator =(const Singleton& singleton) = delete;
	Singleton& operator =(const Singleton&& singleton) = delete;
public:
	static T& instance() {
		// 정적 지역 변수, 일반 지역변수처럼 접근해야 한다. 최초 접근시에 생성되고, 이후에는 생성하지 않고 생성된 변수를 읽고쓴다.
		// 싱글턴에서 보장되어야하는 점중에 멀티쓰레드를 고려해주어야한다.
		// 정적 지역변수가 쓰레드 환경에서 안전을 보장해준다고 생각하면된다.
		static T instance; 
		return instance;
	}
	void print() {
		std::cout << " asd" << std::endl;
	}
};