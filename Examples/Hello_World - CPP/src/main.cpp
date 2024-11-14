#include <memory>
#include <string>
#include "main.h"

constexpr int TEXT_WIDTH = 86;
constexpr int TEXT_HEIGHT = 16;

    HelloWorld::HelloWorld(PlaydateAPI* api)
    {
        // Initialize member variables
        pd= api;
        fontpath = "/System/Fonts/Asheville-Sans-14-bold.pft";
        x = (400 - TEXT_WIDTH) / 2;
        y = (240 - TEXT_HEIGHT) / 2;
        dx = 1;
        dy = 2;
        
        const char* err;
        font = pd->graphics->loadFont(fontpath.c_str(), &err);

        if (font == nullptr)
        {
            pd->system->error("%s:%i Couldn't load font %s: %s", __FILE__, __LINE__, fontpath.c_str(), err);
        }
    }

    void HelloWorld::Update()
    {
        pd->graphics->clear(kColorWhite);
        pd->graphics->setFont(font);
        pd->graphics->drawText("Hello C++", strlen("Hello C++"), kASCIIEncoding, x, y);

        x += dx;
        y += dy;

        if (x < 0 || x > LCD_COLUMNS - TEXT_WIDTH)
        {
            dx = -dx;
        }
        
        if (y < 0 || y > LCD_ROWS - TEXT_HEIGHT)
        {
            dy = -dy;
        }

        pd->system->drawFPS(0,0);
    }

std::unique_ptr<HelloWorld> helloWorld;

static int gameTick(void* userdata)
{
    helloWorld->Update();
    return 1;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WINDLL
__declspec(dllexport)
#endif

int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg)
{
    eventHandler_pdnewlib(pd, event, arg);

    if (event == kEventInit)
    {
        pd->display->setRefreshRate(20);
        helloWorld = std::make_unique<HelloWorld>(pd);

        pd->system->setUpdateCallback(gameTick, pd);

    }

    if (event == kEventTerminate)
    {
        pd->system->logToConsole("Tearing down...");
        helloWorld = nullptr;
    }
    return 0;
}

#ifdef __cplusplus
}
#endif