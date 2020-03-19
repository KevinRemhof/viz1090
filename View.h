#ifndef VIEW_H
#define VIEW_H

#include "AppData.h"
#include "Map.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h" 

//defs - should all move to config file setup
#define ROUND_RADIUS 3 //radius of text box corners

#define CENTEROFFSET .375 //vertical offset for middle of screen

#define TRAIL_LENGTH 120
#define TRAIL_TTL   240.0 
#define DISPLAY_ACTIVE   30 
#define TRAIL_TTL_STEP   2

#define MIN_MAP_FEATURE 2

#define FRAMETIME 33

#define PAD 5



//
// This should go to a full theming class
//
typedef struct Style {
    SDL_Color backgroundColor;

    SDL_Color selectedColor;
    SDL_Color planeColor;
    SDL_Color planeGoneColor;

    SDL_Color mapInnerColor;
    SDL_Color mapOuterColor;
    SDL_Color scaleBarColor;

    SDL_Color buttonColor;
} Style;



class View {

	private:
		AppData *appData;

		//for cursor drawing
	    uint64_t mouseMovedTime;
	    int mousex;
	    int mousey;

	    uint64_t clickTime;
	    int clickx;
	    int clicky;

	    TTF_Font* loadFont(char *name, int size);
	    void closeFont(TTF_Font *font);
		void drawString(char * text, int x, int y, TTF_Font *font, SDL_Color color);
		void drawStringBG(char * text, int x, int y, TTF_Font *font, SDL_Color color, SDL_Color bgColor);
		void drawStatusBox(int *left, int *top, char *label, char *message, SDL_Color color);
		void drawStatus();

		Aircraft *selectedAircraft;

		Style style;

	public:
		int screenDist(float d);
		void pxFromLonLat(float *dx, float *dy, float lon, float lat);
		void latLonFromScreenCoords(float *lat, float *lon, int x, int y);
		void screenCoords(int *outX, int *outY, float dx, float dy);
		int outOfBounds(int x, int y);
		void drawPlaneOffMap(int x, int y, int *returnx, int *returny, SDL_Color planeColor);
		void drawPlaneIcon(int x, int y, float heading, SDL_Color planeColor);
		void drawTrail(Aircraft *p);
		void drawScaleBars();
		void drawPolys(float screen_lat_min, float screen_lat_max, float screen_lon_min, float screen_lon_max);
		void drawGeography();
		void drawSignalMarks(Aircraft *p, int x, int y);
		void drawPlaneText(Aircraft *p);
		void drawSelectedAircraftText(Aircraft *p);
		void resolveLabelConflicts();
		void drawPlanes();
		void animateCenterAbsolute(float x, float y);
		void moveCenterAbsolute(float x, float y);
		void moveCenterRelative(float dx, float dy);
		void zoomMapToTarget();
		void moveMapToTarget();
		void drawMouse();
		void drawClick();
		void registerClick(int tapcount, int x, int y);
		void registerMouseMove(int x, int y);
		void draw();
		
		void SDL_init();
		void font_init();

		View(AppData *appData);
		~View();


	////////////////
		bool metric;

	    float maxDist;

	    float centerLon;
	    float centerLat;
	   
	    float mapTargetMaxDist;
	    float mapTargetLat;
	    float mapTargetLon;

	    int mapMoved;
	    uint64_t lastFrameTime;

	    Map map;

	    int screen_upscale;
	    int screen_uiscale;
	    int screen_width;
	    int screen_height;
	    int screen_depth;
	    int fullscreen;
	    int screen_index;

		SDL_Window		*window;
		SDL_Renderer	*renderer;
		SDL_Texture 	*mapTexture;

		TTF_Font		*mapFont;
		TTF_Font		*mapBoldFont;	
		TTF_Font		*listFont;	

		TTF_Font		*messageFont;	
		TTF_Font		*labelFont;		

		int mapFontWidth;
		int mapFontHeight;
		int labelFontWidth;
		int labelFontHeight;	
		int messageFontWidth;
		int messageFontHeight;
};

#endif