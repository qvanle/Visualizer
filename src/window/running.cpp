#include <window.hpp>
#include <services.hpp>

void MyWindow::run()
{
    status = WINDOW_STATUS::IS_OPEN;
    thread_pool.push_back(std::thread(&MyWindow::rendering, this));
    thread_pool.push_back(std::thread(&MyWindow::getEvent, this));
    //thread_pool.push_back(std::thread(&MyWindow::interacting, this));

    interacting();

    for(auto& thread : thread_pool)
    {
        thread.join();
    }
}
