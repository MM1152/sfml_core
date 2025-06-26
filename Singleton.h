#pragma once
#include <iostream>
template <typename T>
class Singleton {
protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	//���� ���� �ʿ�
	Singleton(const Singleton& singleton) = delete;
	Singleton(const Singleton&& singleton) = delete;
	Singleton& operator =(const Singleton& singleton) = delete;
	Singleton& operator =(const Singleton&& singleton) = delete;
public:
	static T& instance() {
		// ���� ���� ����, �Ϲ� ��������ó�� �����ؾ� �Ѵ�. ���� ���ٽÿ� �����ǰ�, ���Ŀ��� �������� �ʰ� ������ ������ �а���.
		// �̱��Ͽ��� ����Ǿ���ϴ� ���߿� ��Ƽ�����带 ������־���Ѵ�.
		// ���� ���������� ������ ȯ�濡�� ������ �������شٰ� �����ϸ�ȴ�.
		static T instance; 
		return instance;
	}
	void print() {
		std::cout << " asd" << std::endl;
	}
};