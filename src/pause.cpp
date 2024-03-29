#include "pause.h"

void Pause::HandleEvent(Engine *engine, SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        engine->PopState();
    }
    if (event.type == SDL_MOUSEBUTTONDOWN && bback.MouseIsOver()) {
        engine->PopState();
        engine->PopState();
    }
    if (event.type == SDL_MOUSEBUTTONDOWN && bresume.MouseIsOver()) {
        engine->PopState();
    }
}

void Pause::Update(Engine *engine, double frame_delta) {

};

void Pause::Draw(Engine *engine) {
    if (caller != nullptr) {
        caller->Draw(engine);
        SDL_SetRenderDrawColor(engine->renderer, 0, 0, 0, 50);
        SDL_RenderFillRect(engine->renderer, nullptr);

        bresume.Draw(engine->renderer);
        bback.Draw(engine->renderer);
    }
};
