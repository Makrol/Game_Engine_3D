#include "InputEngine.h"
#include <iostream>
void InputEngine::doAction(Event* eventHendler, RenderWindow* window)
{
	if (keyActionContener.count(eventHendler->key.code))
	{
		spamButton = false;
		if (keyClickArea.count(eventHendler->key.code))
		{
			Vector4d tmp4d = keyClickArea.find(eventHendler->key.code)->second;
			int x = Mouse::getPosition(*window).x;
			int y = Mouse::getPosition(*window).y;
			if (x >= tmp4d.px1 && x <= tmp4d.px2 &&
				y >= tmp4d.py1 && y <= tmp4d.py2)
			{
				auto action = keyActionContener.find(eventHendler->key.code)->second;
				action();
			}
		}
		else
		{
			auto action = keyActionContener.find(eventHendler->key.code)->second;
			action();
		}
	}
}

void InputEngine::registerNewAction(int key, void(*func)(), bool spamAble)
{
	keyActionContener.insert(std::make_pair(key, func));
	if (spamAble)
		spamAbleKeys.insert(key);
}

void InputEngine::registerNewActionInArea(int key, void(*func)(), int px1, int py1, int px2, int py2, bool spamAble)
{
	keyClickArea.insert(std::make_pair(key, Vector4d(px1, py1, px2, py2)));
	registerNewAction(key, func, spamAble);
}

void InputEngine::reset()
{
	keyClickArea.clear();
	keyActionContener.clear();
	spamAbleKeys.clear();
}