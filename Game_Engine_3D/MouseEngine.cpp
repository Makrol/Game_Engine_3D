#include "MouseEngine.h"
#include <iostream>
void MouseEngine::pollEvent(Event* eventHendler, RenderWindow* window)
{
	if (eventHendler->type == Event::MouseButtonPressed)
	{
		if (spamAbleKeys.count(eventHendler->mouseButton.button) || spamButton)
		{
			doAction(eventHendler, window);
		}
	}
	else if (eventHendler->type == Event::MouseButtonReleased)
	{
		spamButton = true;
	}
}

