#pragma once
#include <unordered_map>
#include <utility>
#include "Singleton.h"

template <typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>> {
	//지워 봐야할듯?
	friend Singleton<ResourceMgr<T>>;
protected:
	ResourceMgr() = default;
	virtual ~ResourceMgr() override{
		for (auto pair : resources) {
			delete pair.second;
		}
		resources.clear();
	};

	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr(const ResourceMgr&&) = delete;
	ResourceMgr& operator=(const ResourceMgr&) = delete;
	ResourceMgr& operator=(const ResourceMgr&&) = delete;

	std::unordered_map<std::string, T*> resources;

	static T Empty;
public:	
	bool Load(const std::string& filePathid) {
		auto it = resources.find(filePathid);
		if (it != resources.end()) {
			return false;
		}

		T* res = new T();
		bool success = res->loadFromFile(filePathid);
		if (!success) {
			return false;
		}

		resources.insert({ filePathid , res });
		return true;
	}
	bool UnLoad(std::string& id) {
		auto it = resources.find(id);
		if (it == resources.end()) {
			return false;
		}

		delete resources[id];
		resources.erase(it);
		return true;
	}
	T& Get(const std::string& id) {
		auto it = resources.find(id);
		if (it != resources.end()) {
			return *(it->second);
		}
		return Empty;
	}
};

template<typename T>
T ResourceMgr<T>::Empty;