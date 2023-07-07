#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
{
}

GameObject::~GameObject()
{
}

void GameObject::DrawSub()
{
	Draw();
	for (auuto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->DrawSub();
	}
}