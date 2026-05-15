#include "myapp.hpp"

int main()
{
    MyApp app(1000,800);
    app.event_loop();
    return 0;
}
