#include "raylib.h"

#include "Logo.h"
#include "Title.h"

int main()
{
    const int nScreenWidth = 720;
    const int nScreenHeight = 720;
    
    InitWindow(nScreenWidth, nScreenHeight, "Baseball Card Game");
    SetTargetFPS(60);

    enum eGameScreen { LOGO, TITLE, GAMEPLAY, ENDING };

    eGameScreen nCurrentScreen = LOGO;

    cLogo logo(nScreenWidth, nScreenHeight);
    cTitle title(nScreenWidth, nScreenHeight);

    while(!WindowShouldClose())
    {
        switch(nCurrentScreen)
        {
            case LOGO:
            {
				if(logo.IsFinished())
				{
					nCurrentScreen = TITLE;
				}
                else
                {
                    logo.Update();
                }
            }
            break;

            case TITLE:
            {
                if(IsKeyPressed(KEY_ENTER))
                {
                    nCurrentScreen = GAMEPLAY;
                }
            }
            break;

            case GAMEPLAY:
            break;

            case ENDING:
            break;

            default:
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch(nCurrentScreen)
        {
            case LOGO:
            {
                logo.Draw();
            }
            break;

            case TITLE:
            {
                title.Draw();
            }
            break;

            case GAMEPLAY:
            {
                DrawText("GAMEPLAY SCREEN", 20, 20, 40, BLUE);
            }
            break;

            case ENDING:
            {
                DrawText("ENDING SCREEN", 20, 20, 40, RED);
            }
            break;

            default:
            break;
        }

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
