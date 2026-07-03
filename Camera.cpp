//
// Created by Louis-Philippe on 4/21/2026.
//

#include "Camera.h"

void Camera::SetMapBounds(float widthInPixels, float heightInPixels, float screenW, float screenH) {
    mapWidth = widthInPixels;
    mapHeight = heightInPixels;

    float minZoomToFitW = screenW / mapWidth;
    float minZoomToFitH = screenH / mapHeight;
    float minZoomToFit  = std::max(minZoomToFitW, minZoomToFitH);

    effectiveMinZoom = std::max(MIN_ZOOM, minZoomToFit);

    zoom = std::max(zoom, effectiveMinZoom);
    targetZoom = std::max(targetZoom, effectiveMinZoom);
}

void Camera::ClampPosition(float screenW, float screenH) {
    if (mapWidth <= 0.f || mapHeight <= 0.f) return;

    float visibleWorldW = screenW / zoom;
    float visibleWorldH = screenH / zoom;

    // X axis
    if (visibleWorldW >= mapWidth) {
        // Map narrower than the view: force exact center, no overscroll wiggle.
        startX = (mapWidth - visibleWorldW) / 2.f;
    } else {
        float maxStartX = mapWidth - visibleWorldW;
        startX = std::clamp(startX, -overscrollMargin, maxStartX + overscrollMargin);
    }

    // Y axis
    if (visibleWorldH >= mapHeight) {
        startY = (mapHeight - visibleWorldH) / 2.f;
    } else {
        float maxStartY = mapHeight - visibleWorldH;
        startY = std::clamp(startY, -overscrollMargin, maxStartY + overscrollMargin);
    }

    anchorWorldX = startX + (screenW / 2.f) / zoom;
    anchorWorldY = startY + (screenH / 2.f) / zoom;
}

//Zoom multiply by the factor and his restricted between 0.5 and 4
void Camera::Zoom(float factor, float screenW, float screenH) {
    // Anchor, under the screen and fix
    anchorWorldX = startX + (screenW / 2.f) / zoom;
    anchorWorldY = startY + (screenH / 2.f) / zoom;

    targetZoom = std::clamp(targetZoom * factor, MIN_ZOOM, MAX_ZOOM);
}

void Camera::Update(float dt, float screenW, float screenH) {
    // smooth
    float prevZoom = zoom;
    zoom += (targetZoom - zoom) * std::min(ZOOM_SPEED * dt, 1.f);

    float dz = zoom - prevZoom;
    if (std::abs(dz) > 0.00001f) {
        startX = anchorWorldX - (screenW / 2.f) / zoom;
        startY = anchorWorldY - (screenH / 2.f) / zoom;
    }
    ClampPosition(screenW, screenH);
}

void Camera::Movement(float directionX, float directionY, float screenW, float screenH) {
    startX += directionX / zoom;
    startY += directionY / zoom;

    anchorWorldX += directionX / zoom;
    anchorWorldY += directionY / zoom;

    ClampPosition(screenW, screenH);
}

SDL_FRect Camera::WorldToScreen(float worldX, float worldY, float width, float height) const {
    return {
        (worldX - startX) * zoom,
        (worldY - startY) * zoom,
        width * zoom,
        height * zoom
    };
}