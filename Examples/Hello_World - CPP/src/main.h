#ifndef _MAIN_H_
#include <pdcpp/pdnewlib.h>

class HelloWorld
{
    public:
        explicit HelloWorld(PlaydateAPI* api);
        void Update();
    private:
        PlaydateAPI* pd;
        std::string fontpath;
        LCDFont* font;
        int x, y, dx, dy;

};

#endif // _MAIN_H_