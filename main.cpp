#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Window *window = nullptr;
    SDL_Surface *screen = nullptr;
    bool running = true;

    int init = SDL_Init(SDL_INIT_VIDEO);

    if (init < 0)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    window = SDL_CreateWindow("Win", 0, 0, 800, 600, SDL_WINDOW_RESIZABLE);

    SDL_Surface *image = SDL_LoadBMP("./images/3D-Window_BBB_Blender_2.bmp");

    screen = SDL_GetWindowSurface(window);
    SDL_BlitSurface(image, NULL, screen, NULL);
    SDL_UpdateWindowSurface(window);

    int curentWidth;
    int curentHeight;

    while (running)
    {
        SDL_Event event;

        SDL_PollEvent(&event);

        SDL_GetWindowSize(window, &curentWidth, &curentHeight);

        int mouseX;
        int mouseY;

        screen = SDL_GetWindowSurface(window);
        SDL_BlitSurface(image, NULL, screen, NULL);
        SDL_UpdateWindowSurface(window);

        if (event.type == SDL_MOUSEMOTION)
        {
            SDL_GetMouseState(&mouseX, &mouseY);
            std::cout << "Width: " << curentWidth << std::endl;
            std::cout << "Height: " << curentHeight << std::endl;
            std::cout << "Mouse position X: " << mouseX << std::endl;
            std::cout << "Mouse position Y: " << mouseY << std::endl;
        }

        if (event.type == SDL_QUIT)
        {
            running = false;
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_UP)
            {
                std::cout << "Key up was pressed" << std::endl;
            }

            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_RestoreWindow(window);
            }
        }

        if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_UP)
            {
                std::cout << "Key Up was unpressed" << std::endl;
            }
        }
    }

    SDL_FreeSurface(image);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}