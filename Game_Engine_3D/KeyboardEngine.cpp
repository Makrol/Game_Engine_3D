#include "KeyboardEngine.h"

void KeyboardEngine::pollEvent(Event* eventHendler, RenderWindow* window)
{
	if (eventHendler->type == Event::KeyPressed)
	{
		if (spamAbleKeys.count(eventHendler->key.code) || spamButton)
		{
			doAction(eventHendler, window);
		}
	}
	else if (eventHendler->type == Event::KeyReleased)
	{
		spamButton = true;
	}
}