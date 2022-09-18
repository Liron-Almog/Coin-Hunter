#pragma once
#include "Const.h"
#include "GameObject.h"
template<class Type>
class Factory {

public:
	using pFnc = std::unique_ptr<Type>(*)();

	static unique_ptr<Type> create(const char& name);

	static bool registerit(const char& name, pFnc f);

private:

	static auto& getMap();

};
template<class Type>
auto& Factory<Type>::getMap() {
	static map<char, pFnc> map;
	return map;
}

template<class Type>
 unique_ptr<Type> Factory<Type>::create(const char& name) {
	auto it = Factory::getMap().find(name);
	if (it == Factory::getMap().end())
		return nullptr;
	return it->second();
}

template<class Type>
 bool Factory<Type>::registerit(const char& name, pFnc f) {
	Factory::getMap().emplace(name, f);
	return true;
}