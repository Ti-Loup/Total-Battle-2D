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

//mergin camera border space maximum
float overscrollMargin = 150.f;

    void SetMapBounds(float widthInPixels, float heightInPixels, float screenW = 1920.f, float screenH = 1080.f);


    //Zoom multiply by the factor and his restricted between 0.5 and 4
    void Zoom(float factor,float screenW = 1920.f, float screenH = 1080.f);
    void Update(float directiont, float screenW = 1920.f, float screenH = 1080.f);//for the zoom progressive movement
    void Movement(float directionX, float directionY, float screenW = 1920.f, float screenH = 1080.f);
    //For the miniMap
    void CenterOn (float worldX, float worldY, float screenW = 1920.f, float screenH = 1080.f);

    SDL_FRect WorldToScreen(float worldX, float worldY, float width, float height ) const;

    private:
        float anchorWorldX = 0.f;
        float anchorWorldY = 0.f;
        //To delimitate the size of the map for the camera movements.
        float mapWidth = 0.f;
        float mapHeight = 0.f;
        float effectiveMinZoom = MIN_ZOOM;

        void ClampPosition(float screenW, float screenH);
};


#endif //TOTALWAR2D_CAMERA_H
