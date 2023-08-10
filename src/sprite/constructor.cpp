#include <fstream>
#include <iostream>

#include <sprite.hpp>
#include <GLOBAL.hpp>
#include <services.hpp>


Sprite::Sprite(SDL_Renderer* r) : Object(r) 
{
    render = r;
    textBox = nullptr;
    alignH = HORIZONTAL_ALIGN::CENTER;
    alignV = VERTICAL_ALIGN::CENTER;
    receiveDigit = true;
    receiveLetter = true;
    receiveSymbol = true;
    maxSize = 50;
}

void Sprite::linking(std::string n)
{
    name = n;
    importFromJson();
}
void Sprite::setFont(TTF_Font* f) 
{
    font = f;
    Object::setFont(f);
}
void Sprite::setTextBox(TTF_Font* f)
{
    if(textBox == nullptr)
    {
        objects.push_back(new Object(render));
        textBox = objects.back();
    }
    textBox->setFont(f);
}

std::string Sprite::getText()
{
    if(textBox == nullptr) return "";
    return textBox->getText();
}

void Sprite::initBackground(const json& mem)
{
    Object::importFromJson(mem);
    if(Object::getColor() == nullptr) return ;
    cacheColor = *Object::getColor();
}

void Sprite::initObjects(const json &mem)
{
    objects.clear();
    for(auto& i : mem)
    {
        Object* obj = new Object(render);
        if(i.contains("name")) obj->linking(i["name"]);

        obj->importFromJson(i);

        obj->moveX(getX());
        obj->moveY(getY());

        objects.push_back(obj);
    }
}

void Sprite::initTextBox(const json& mem)
{
    if(textBox == nullptr)
    {
        objects.push_back(new Object(render));
        textBox = objects.back();
    }
    textBox->importFromJson(mem);
    textBox->setFont(this->font);
    textBox->moveX(getX());
    textBox->moveY(getY());
    if(mem.contains("text")) textBox->setText(mem["text"].get<std::string>());
    aligning();
}

void Sprite::initInput(const json& mem)
{
    if(textBox == nullptr) return;
    if(mem.contains("digit")) receiveDigit = mem["digit"].get<bool>();
    if(mem.contains("letter")) receiveLetter = mem["letter"].get<bool>();
    if(mem.contains("symbol")) receiveSymbol = mem["symbol"].get<bool>();
    if(mem.contains("lower")) numberLower = mem["lower"].get<std::string>();
    if(mem.contains("upper")) numberUpper = mem["upper"].get<std::string>();
    if(mem.contains("maxsize")) maxSize = mem["maxsize"].get<int>();
}

void Sprite::importFromJson()
{
    json* mem = JSON::readFile(PATH::ATB::SPRITE_ + name + ".json");

    initBackground((*mem)["background"]);

    if(mem->contains("objects")) initObjects((*mem)["objects"]);
    if(mem->contains("text-box")) initTextBox((*mem)["text-box"]);
    if(mem->contains("input")) initInput((*mem)["input"]);
    delete mem;
}
