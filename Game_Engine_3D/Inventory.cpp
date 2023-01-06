#include "Inventory.h"


void Inventory::createSlots()
{

    for (int i = 0; i < numberOfColumns; i++)
    {
        for (int j = 0; j < numberOfRows; j++)
        {
            slots.push_back(ItemSlot(Vector2f(0, 0), Vector2f(50, 50), Color(255, 229, 180, 90)));
        }
    }
}

void Inventory::clear()
{
    for (int i = 0; i < slots.size(); i++)
    {
        slots[i].empty = true;
    }
}

Inventory::Inventory()
{
    navigationKeyPressed = false;
    selectedItem = 1;
    visable = false;
    sizeX = 310;
    sizeY = 430;
    background.setPosition(0, 0);
    background.setSize(Vector2f(sizeX, sizeY));
    background.setFillColor(Color(0, 0, 0, 150));
    //przerwa 10px w szez

    numberOfColumns = 5;
    numberOfRows = 7;
    createSlots();
}

void Inventory::update(bool& itemToEquip, Item& item)
{
    itemToEquip = false;
    slots[selectedItem].slot.setFillColor(Color(255, 229, 180, 90));
    if (navigationKeyPressed == false)
    {
        if (Keyboard::isKeyPressed(Keyboard::U))
        {
            navigationKeyPressed = true;
            if (selectedItem != 0 && selectedItem != 7 && selectedItem != 14 && selectedItem != 21 && selectedItem != 28)
                selectedItem--;
        }
        else if (Keyboard::isKeyPressed(Keyboard::H))
        {
            navigationKeyPressed = true;
            if (!(selectedItem >= 0 && selectedItem <= 6))
                selectedItem -= 7;
        }
        else if (Keyboard::isKeyPressed(Keyboard::K))
        {
            navigationKeyPressed = true;
            if (!(selectedItem <= 34 && selectedItem >= 28))
                selectedItem += 7;
        }
        else if (Keyboard::isKeyPressed(Keyboard::J))
        {
            navigationKeyPressed = true;
            if (selectedItem != 6 && selectedItem != 13 && selectedItem != 20 && selectedItem != 27 && selectedItem != 34)
                selectedItem++;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            navigationKeyPressed = true;
            if (slots[selectedItem].empty == false)
            {
                itemToEquip = true;
                item = slots[selectedItem].item;
                slots[selectedItem].empty = true;
            }

        }
        else if (Keyboard::isKeyPressed(Keyboard::BackSpace))
        {
            navigationKeyPressed = true;
            slots[selectedItem].empty = true;
        }
    }

    if (!(Keyboard::isKeyPressed(Keyboard::U) || Keyboard::isKeyPressed(Keyboard::H) || Keyboard::isKeyPressed(Keyboard::K) || Keyboard::isKeyPressed(Keyboard::J) || Keyboard::isKeyPressed(Keyboard::Enter) || (Keyboard::isKeyPressed(Keyboard::BackSpace))))
    {
        navigationKeyPressed = false;
    }

    if (selectedItem < 0)
        selectedItem = 0;
    else if (selectedItem > 34)
        selectedItem = 34;

    slots[selectedItem].slot.setFillColor(Color(133, 31, 31, 90));




}

void Inventory::addItem(Item tmp)
{
    for (int i = 0; i < slots.size(); i++)
    {
        if (slots[i].empty == true)
        {
            slots[i].setItem(tmp);
            break;
        }
    }

}



void Inventory::show(RenderTarget* target, Vector2f pos)
{
    if (visable)
    {
        float startX = 10;
        float startY = 10;
        int index = 0;
        background.setPosition(pos);
        target->draw(background);

        for (int i = 0; i < numberOfColumns; i++)
        {
            startY = 10;
            for (int j = 0; j < numberOfRows; j++)
            {
                slots[index].setPosition(Vector2f(background.getPosition().x + startX, background.getPosition().y + startY));
                slots[index].render(target);

                startY += 60;
                index++;
            }
            startX += 60;
        }
    }
}
