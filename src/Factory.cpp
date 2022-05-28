#include "Factory.h"


std::unique_ptr<Players> Factory::create(const std::string& name) {
	static bool initial = true;
	if (initial) {

		registerit("Heavy", []() -> std::unique_ptr<Players> { return std::make_unique<Heavy>(); });
		registerit("Simple", []() -> std::unique_ptr<Players> { return std::make_unique<Simple>(); });
		registerit("Light", []() -> std::unique_ptr<Players> { return std::make_unique<Light>(); });

		initial = false;
	}

	auto it = Factory::getMap().find(name);
	if (it == Factory::getMap().end())
		return nullptr;
	return it->second();
}

void Factory::registerit(const std::string& name, pFnc f) {
	Factory::getMap().emplace(name, f);
}