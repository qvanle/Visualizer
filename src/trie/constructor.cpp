#include <data_structures/trie.hpp>
#include <queue>

Trie::Node::Node(int k, Sprite* spr)
{
    key = k;
    sprite = spr;
    endOfWords = 0;
    numberOfWords = 0;
    for(int i = 0; i < 26; i++)
        childs[i] = nullptr;
};

Trie::Trie(SDL_Renderer* r, std::mutex& m, TTF_Font* f, SDL_Rect v, int cap) : ds_mutex(m)
{
    render = r;
    font = f;
    viewport = v;
    capacity = cap;
    size = 0;
    root = nullptr;
    edgesColor = {255, 255, 255, 255};
    fontColor = {255, 255, 255, 255};
    nodeColor = {20, 85, 185, 255};
    shiftX = 20;
    shiftX = 20;
    distanceX = 60;
    distanceY = 80;
    isMoving = false;

    isQueue = false;
    isPause = false;
    stepWait = 600;
    isAnimate = false;

    std::string fontpath = PATH::ASSETS::FONTS_ + "nimbus-sans-l/regular.otf";
    scriptFont = TTF_OpenFont(fontpath.c_str(), 18);

    currentScript = nullptr;
    Script* insert = new Script(render, scriptFont);
    insert->linking("trie/insert");
    scripts[DATA_STRUCTURES_OPERATOR::INSERT] = insert;

    Script* remove = new Script(render, scriptFont);
    remove->linking("trie/remove");
    scripts[DATA_STRUCTURES_OPERATOR::DELETE] = remove;

    Script* search = new Script(render, scriptFont);
    search->linking("trie/search");
    scripts[DATA_STRUCTURES_OPERATOR::SEARCH] = search;

    Script* init = new Script(render, scriptFont);
    init->linking("trie/init");
    scripts[DATA_STRUCTURES_OPERATOR::INIT] = init;
}

int Trie::locating(Node* node, int shiftDown, int shiftRight)
{
    if(node == nullptr) return 0;

    int j = 0;
    for(int i = 0; i < 26; i++) 
        if(node->childs[i] != nullptr) j++;
    j /= 2;

    int i = 0;

    for(; j > 0; i++)
    {
        if(node->childs[i] == nullptr)
            continue;
        j--;

        shiftRight = locating(node->childs[i], shiftDown + 1, shiftRight);
    }

    node->sprite->locatingX(shiftX + shiftRight * distanceX);
    node->sprite->locatingY(shiftY + shiftDown * distanceY);
    node->sprite->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);
    shiftRight++;

    for(; i < 26; i++)
    {
        if(node->childs[i] == nullptr)
            continue;
        shiftRight = locating(node->childs[i], shiftDown + 1, shiftRight);
    }

    return shiftRight;
}

void Trie::setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4)
{
    bgColor = c1;   
    nodeColor = c2;
    fontColor = c3;
    edgesColor = c4;

    std::queue<Node*> q;
    if(root != nullptr)
        q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        node->sprite->coloring(nodeColor);
        node->sprite->setFontColor(fontColor);
        node->sprite->coloring(nodeColor);

        for(int i = 0; i < 26; i++)
            if(node->childs[i] != nullptr)
                q.push(node->childs[i]);
    }
}
