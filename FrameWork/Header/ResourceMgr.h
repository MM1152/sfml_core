#pragma once
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
			std::cout << "FAIL" << std::endl;
			delete res;
			return false;
		}

		std::cout << "True" << std::endl;
		resources.insert({ filePathid , res });
		return true;
	}
	void Load(const std::vector<std::string>& filePathid) {
		for (const std::string& i : filePathid) {
			Load(i);
		}
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

#define TEXTURE_MGR (ResourceMgr<sf::Texture>::instance())
#define FONT_MGR (ResourceMgr<sf::Font>::instance())
#define SOUNDBUFFER_MGR (ResourceMgr<sf::SoundBuffer>::instance())