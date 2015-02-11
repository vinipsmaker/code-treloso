#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_opengl.h>

using namespace std;

/* Our program's entry point */
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *mainwindow; /* Our window handle */
    SDL_GLContext maincontext; /* Our opengl context handle */

    /* Turn on double buffering with a 24bit Z buffer.
     * You may need to change this to 16 or 32 for your system */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    /* Create our window centered at 512x512 resolution */
    mainwindow = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer* render = SDL_CreateRenderer(mainwindow, -1,
                           SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);

    /* Create our opengl context and attach it to our window */
    maincontext = SDL_GL_CreateContext(mainwindow);

    cout << reinterpret_cast<const char*>(glGetString(GL_VERSION)) << endl;

    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);

    bool exitp = false;
    SDL_Event event;

    SDL_SetRenderDrawColor(render, 250, 250, 250, 250);

    int fpsCount = 0;

    GLfloat colorVector[3][4] = {{1.0, 0.0, 0.0, 1.0 },
                                 {0.0, 1.0, 0.0, 1.0 },
                                 {0.0, 0.0, 1.0, 1.0}};
    unsigned posColor = 0;

    while(!exitp)
    {
      fpsCount++;
      SDL_PollEvent(&event);

      if(event.type == SDL_QUIT)
        exitp= true;

      SDL_RenderClear(render);

      if(fpsCount%60 == 0)
        ++posColor;

      glClearColor(colorVector[posColor%3][0], colorVector[posColor%3][1],
                   colorVector[posColor%3][2], colorVector[posColor%3][3]);

      glClear (GL_COLOR_BUFFER_BIT);

      SDL_RenderPresent(render);

      if(fpsCount == 60)
        fpsCount = 0;
     }

    SDL_GL_DeleteContext(maincontext);
    SDL_DestroyWindow(mainwindow);
    SDL_Quit();
}
