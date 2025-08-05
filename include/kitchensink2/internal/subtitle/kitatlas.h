#ifndef KITATLAS_H
#define KITATLAS_H

#include <SDL_rect.h>
#include <SDL_render.h>
#include <stdbool.h>

#include "kitchensink/kitconfig.h"

typedef struct Kit_TextureAtlasItem {
    SDL_Rect source; //< Source coordinates on cache surface
    SDL_Rect target; //< Target coordinates on output surface
} Kit_TextureAtlasItem;

typedef struct Kit_Shelf {
    uint16_t width;
    uint16_t height;
    uint16_t count;
} Kit_Shelf;

typedef struct Kit_TextureAtlas {
    int cur_items;               //< Current items count
    int max_items;               //< Maximum items count
    int max_shelves;             //< Maximum shelf count
    int w;                       //< Current atlas width
    int h;                       //< Current atlas height
    Kit_TextureAtlasItem *items; //< Cached items
    Kit_Shelf *shelves;          //< Atlas shelves
} Kit_TextureAtlas;

KIT_LOCAL Kit_TextureAtlas *Kit_CreateAtlas();
KIT_LOCAL void Kit_FreeAtlas(Kit_TextureAtlas *atlas);
KIT_LOCAL void Kit_ClearAtlasContent(Kit_TextureAtlas *atlas);
KIT_LOCAL void Kit_CheckAtlasTextureSize(Kit_TextureAtlas *atlas, SDL_Texture *texture);
KIT_LOCAL int Kit_GetAtlasItems(const Kit_TextureAtlas *atlas, SDL_Rect *sources, SDL_Rect *targets, int limit);
KIT_LOCAL int
Kit_AddAtlasItem(Kit_TextureAtlas *atlas, SDL_Texture *texture, const SDL_Surface *surface, const SDL_Rect *target);

#endif // KITATLAS_H
