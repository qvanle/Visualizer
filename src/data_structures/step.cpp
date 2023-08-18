#include <data_structures.hpp>
// goBack
void DataStructures::goBack()
{

}

// goNext
void DataStructures::goNext()
{
    
}

// goOn
void DataStructures::goOn()
{

}

// goOff
void DataStructures::goOff()
{
    switch(type)
    {
        case DATA_STRUCTURES_TYPE::AVL:
            if(avl == nullptr) return ;
            avl->goOff();
            break;
        default:
            break;
    }
}

// speedUp 
void DataStructures::speedUp()
{

}

// slowDown
void DataStructures::slowDown()
{

}
