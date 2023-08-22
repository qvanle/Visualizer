#include <data_structures/trie.hpp>
#include <thread>


void Trie::waitForStep()
{
    if(isAnimate) 
    {
        ds_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(stepWait));
        ds_mutex.lock();
    }
    std::lock_guard<std::mutex> pause_lock(pause_mutex);
    if(isPause == false) 
    {
        return ;
    }

    ds_mutex.unlock();
    std::unique_lock<std::mutex> lk(step_mutex);
    step_cv.wait(lk, [&]{return isQueue == true;});
    isQueue = false;
    ds_mutex.lock();
}

void Trie::highlight(std::vector<int> l)
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

void Trie::unhighlight(std::vector<int> l)
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
