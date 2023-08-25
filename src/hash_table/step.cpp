#include <data_structures/hash_table.hpp>
void HashTable::waitForStep()
{
    if(isAnimate) 
    {
        ds_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(stepWait));
        ds_mutex.lock();
        {
            std::lock_guard<std::mutex> lk(pause_mutex);
            if(!pause) return ;
        }
        ds_mutex.unlock();
        std::unique_lock<std::mutex> lk(pause_mutex);
        queue_cv.wait(lk, [this]{return !pause;});
        ds_mutex.lock();
    }
}

void HashTable::goBack()
{
}

void HashTable::goNext()
{
    {
        std::lock_guard<std::mutex> lk(pause_mutex);
        if(!pause) return ;
    }
    goOff();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    goOff();
}

void HashTable::goOn()
{
}

void HashTable::goOff()
{
    {
        std::lock_guard<std::mutex> lk(pause_mutex);
        pause ^= true;
    }
    queue_cv.notify_one();
}

void HashTable::speedUp()
{
    if(stepWait >= 100) stepWait = stepWait / 2;
}

void HashTable::slowDown()
{
    if(stepWait <= 2000) stepWait = stepWait * 2;
}



void HashTable::highlight(std::vector<int> l)
{
    if(isAnimate)
    {
        animate_mutex.lock();
        for(int i = 0; i < l.size(); i++)
        {
            currentScript->highlight(l[i]);
        }
        animate_mutex.unlock();
    }
}

void HashTable::unhighlight(std::vector<int> l)
{
    if(isAnimate)
    {
        animate_mutex.lock();
        for(int i = 0; i < l.size(); i++)
        {
            currentScript->unhighlight(l[i]);
        }
        animate_mutex.unlock();
    }
}


