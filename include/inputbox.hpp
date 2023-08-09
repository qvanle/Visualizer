#include <string>
#include <vector> 

#include <SDL2/SDL.h>

#include <object.hpp>
#include <sprite.hpp>
#include <button.hpp>

class InputBox : private Object
{
private:
    SDL_Renderer* render;
    std::string name;
    TTF_Font* font;

    DATA_STRUCTURES_OPERATOR op;

    std::vector<Button*> buts;
    std::vector<Sprite*> inputs;
    int typingIndex = 0;
protected:
    void initBackground(const json& mem);
    void initButtons(const json& mem);
    void initSprites(const json& mem);
    void initOperator(const json& mem);
    void importFromJson();
    bool isButtonReceiveEvent(SDL_Event& event);
    bool isInputReceiveEvent(SDL_Event& event);
public:        
    InputBox(SDL_Renderer* render, TTF_Font* font);
    ~InputBox();

    void linking(std::string n);
    DATA_STRUCTURES_OPERATOR getOperator();
    bool isReceiveEvent(SDL_Event& e);
    Button* react(SDL_Event& e);
    std::string getText(int index);
    void setText(int index, std::string text);
    void setText(std::string text);
    void rendering();
};
