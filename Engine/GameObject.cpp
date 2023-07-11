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
	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->DrawSub();
	}
}

void GameObject::UpdateSub()
{
	Update();//UpdateŠÖ”‚ðŒÄ‚ñ‚Å‚é
	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->UpdateSub();
		if ((*itr)->IsDead() == true)
		{
			(*itr)->ReleaseSub();
			SAFE_DELETE(*itr);
			itr = childList_.erase(itr);
		}
	}
}

void GameObject::ReleaseSub()
{
	Relese();
	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->ReleaseSub();
	}
}

bool GameObject::IsDead()
{
	if (KillMe())
	{
		IsDead = true;
	}
}

void GameObject::KillMe()
{
}
