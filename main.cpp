#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_opengl.h>

using namespace std;

void foobar(SDL_Window *window)
{
    /* Clear our buffer with a red background */
    glClearColor ( 1.0, 0.0, 0.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    /* Swap our back buffer to the front */
    SDL_GL_SwapWindow(window);
    /* Wait 2 seconds */
    SDL_Delay(2000);
 
    /* Same as above, but green */
    glClearColor ( 0.0, 1.0, 0.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    SDL_GL_SwapWindow(window);
    SDL_Delay(2000);
 
    /* Same as above, but blue */
    glClearColor ( 0.0, 0.0, 1.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    SDL_GL_SwapWindow(window);
    SDL_Delay(2000);
}
 
/* Our program's entry point */
int main(int argc, char *argv[])
{
    SDL_Window *mainwindow; /* Our window handle */
    SDL_GLContext maincontext; /* Our opengl context handle */
 
    /* Turn on double buffering with a 24bit Z buffer.
     * You may need to change this to 16 or 32 for your system */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
 
    /* Create our window centered at 512x512 resolution */
    mainwindow = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  512, 512, SDL_WINDOW_OPENGL);
 
    /* Create our opengl context and attach it to our window */
    maincontext = SDL_GL_CreateContext(mainwindow);

    cout << reinterpret_cast<const char*>(glGetString(GL_VERSION)) << endl;
  
    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);
 
    foobar(mainwindow);

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(maincontext);
    SDL_DestroyWindow(mainwindow);
    SDL_Quit();
}
