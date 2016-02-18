#pragma once
#include <string>
#include <vector>
#include "BaseComponent.h"
#include "BaseController.h"


class Entity
{
private:
	std::string id;
	std::vector<BaseComponent*> component;
	std::vector<BaseController*> controller;

public:
	Entity();
	~Entity();
	std::string getId();

	void setId(std::string);

	void add(BaseComponent*);
	void add(BaseController*);

	void remove(BaseComponent*);
	void remove(BaseController*);
	void deleteComponent(std::string);
	void deleteController(std::string);

	bool hasComponent();
	bool hasController();

	BaseComponent* getComponent(std::string);
	BaseController* getController(std::string);
};
