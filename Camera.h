#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#ifndef TOTALWAR2D_CAMERA_H
#define TOTALWAR2D_CAMERA_H

class Camera {
public:
float startX = 0.f;
float startY = 0.f;
float zoom = 1.f;
float targetZoom = 1.f;

static constexpr float MIN_ZOOM = 0.8f;
static constexpr float MAX_ZOOM = 4.f;
static constexpr float ZOOM_SPEED = 5.f;


    //Zoom multiply by the factor and his restricted between 0.5 and 4
    void Zoom(float factor,float screenW = 1920.f, float screenH = 1080.f);
    void Update(float directiont, float screenW = 1920.f, float screenH = 1080.f);//for the zoom progressive movement
    void Movement(float directionX, float directionY);

    SDL_FRect WorldToScreen(float worldX, float worldY, float width, float height ) const;

    private:
        float anchorWorldX = 0.f;
        float anchorWorldY = 0.f;
};


#endif //TOTALWAR2D_CAMERA_H
