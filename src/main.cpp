#define SDL_MAIN_HANDLED
#include "engine.h"
#include "gamestate.h"
#include "menu.h"

// TODO: Art? (Non-moving background. Yellow bucket with sky at the end.)
// TODO: Rotation for crab based on speed?
// TODO: Animations on claws?
int main() {
    Engine engine;
    engine.Init();

    GameState* menu = new Menu;
    engine.ChangeState(menu);
    while (engine.Running()) {
        engine.HandleEvents();
        engine.Update();
        engine.Draw();
    }

    engine.Cleanup();
    return 0;
}