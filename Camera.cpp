//
// Created by Louis-Philippe on 4/21/2026.
//

#include "Camera.h"


//Zoom multiply by the factor and his restricted between 0.5 and 4
void Camera::Zoom(float factor, float screenW, float screenH) {
    // Anchor, under the screen and fix
    anchorWorldX = startX + (screenW / 2.f) / zoom;
    anchorWorldY = startY + (screenH / 2.f) / zoom;

    targetZoom = std::clamp(targetZoom * factor, MIN_ZOOM, MAX_ZOOM);
}

// Update : everyframe moves there
void Camera::Update(float dt, float screenW, float screenH) {
    // smooth
    float prevZoom = zoom;
    zoom += (targetZoom - zoom) * std::min(ZOOM_SPEED * dt, 1.f);

    float dz = zoom - prevZoom;
    if (std::abs(dz) > 0.00001f) {
        startX = anchorWorldX - (screenW / 2.f) / zoom;
        startY = anchorWorldY - (screenH / 2.f) / zoom;
    }
}

void Camera::Movement(float directionX, float directionY) {
    startX += directionX / zoom;
    startY += directionY / zoom;
    //follow the anchor has well
    anchorWorldX += directionX / zoom;
    anchorWorldY += directionY / zoom;
}

SDL_FRect Camera::WorldToScreen(float worldX, float worldY, float width, float height) const {
    return {
        (worldX - startX) * zoom,
        (worldY - startY) * zoom,
        width * zoom,
        height * zoom
    };
}