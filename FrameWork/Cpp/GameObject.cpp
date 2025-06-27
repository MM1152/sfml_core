#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& name)
	:name(name)
	, position({ 0,0 })
	, origin({ 0,0 })
	, active(true)
	, roataion(0)
{

}

GameObject::~GameObject()
{
}
