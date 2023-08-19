#include <script.hpp>
#include <services.hpp>

Script::Script(SDL_Renderer* render, TTF_Font* f) : Object(render)
{
    this->render = render;
    this->font = f;
}

void Script::linking(std::string name)
{
    this->name = name;
    importFromJson();
}

void Script::importFromJson()
{
    json * mem = JSON::readFile(PATH::ATB::SCRIPT_ + name + ".json");
    if(mem == nullptr) return;

    if(mem->contains("background")) 
        initBackground((*mem)["background"]);
    if(mem->contains("sprite"))
        spriteName = (*mem)["sprite"].get<std::string>();

    if(mem->contains("script"))
    {
        auto lines = FILEE::readFile(PATH::ASSETS::SCRIPT_ + (*mem)["script"].get<std::string>());
        int j = 0;
        for(auto i : lines) 
        {
            sprites.push_back(new Sprite(render));
            sprites.back()->setFont(font);
            sprites.back()->linking(spriteName);
            sprites.back()->setText(i);
            sprites.back()->locatingX(getX());
            sprites.back()->locatingY(getY() + j * 18);
            sprites.back()->aligning(HORIZONTAL_ALIGN::LEFT, VERTICAL_ALIGN::CENTER);
            j++;
        }
    }

}

void Script::initBackground(const json& mem)
{
    Object::importFromJson(mem);
}
