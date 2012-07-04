#ifndef ROXLU_RELEMENTH
#define ROXLU_RELEMENTH

/*
#include "Text.h"
//#include "Color.h"
*/

#include <roxlu/experimental/Text.h>
#include <roxlu/graphics/Color.h>

#include <buttons/Types.h>
#include <string>

using namespace roxlu;

using std::string;

namespace buttons {

class Element {
public:	
	Element(int type, const string& name, int valueType);
	~Element();

	virtual void setup(){}
	virtual void update(){}
	virtual void generateStaticText(Text& staticText) {}
	virtual void updateTextPosition(Text& staticText, Text& dynText) {}
	virtual void generateDynamicText(Text& dynText) {};
	virtual void updateDynamicText(Text& dynText) {};
	virtual void generateVertices(ButtonVertices& shapeVertices) = 0;
		
	virtual void onMouseMoved(int mx, int my) { } // global  move
	virtual void onMouseDragged(int mx, int my, int dx, int dy) { } // global drag (check: drag_inside)
	virtual void onMouseDown(int mx, int my) { } // global down
	virtual void onMouseUp(int mx, int my) { } // global up
	virtual void onMouseClick(int mx, int my) { } // when click and released inside
	virtual void onMouseEnter(int mx, int my) { }
	virtual void onMouseLeave(int mx, int my) { }
	
	virtual void onSaved(){}  // gets called once all data has been saved
	virtual void onLoaded(){}  // gets called once all data has been loaded 
	
	
	virtual Element& setColor(const float r, const float g, const float b, const float a = 1.0f);
	
	void setValueType(int valueType);
	int getValueType();
	void needsRedraw();
	void needsTextUpdate(); // when you want to change the dynamic text
	
	int x;
	int y; 
	int w;
	int h;
	int type;
	int value_type; // what kind of data do you store.

	string label;
	string name;
	int state;
	bool is_mouse_inside;
	bool is_mouse_down_inside;
	bool needs_redraw;	
	bool needs_text_update;
	bool drag_inside; // did the drag started from inside the element.
	int num_vertices;
	
	float* bg_top_color;
	float* bg_bottom_color;
	float col_text[4];
	float col_bg_default[4];
	float col_bg_top_hover[4];
	float col_bg_bottom_hover[4];
};

inline void Element::needsRedraw() {
	needs_redraw = true;
}

inline void Element::needsTextUpdate() {
	needs_text_update = true;
}

inline void Element::setValueType(int valueType) {
	value_type = valueType;
}

inline int Element::getValueType() {
	return value_type;
}

inline Element& Element::setColor(const float r, const float g, const float b, const float a) {


	// set default color
	float hue,sat,bright;
//	printf("Col in: %f, %f, %f\n", r,g,b);
	Color::RGBToHLSf(r,g,b,&hue,&bright, &sat);
	BSET_COLOR(col_bg_default, r, g, b, a);
//	float rr,gg,bb;
//	Color::HLSToRGBf(hue,bright, sat, &rr, &gg, &bb);	
//	printf("Col out: %f, %f, %f\n", rr,gg,bb);	

	bg_bottom_color = col_bg_default;
	bg_top_color = col_bg_default;
	
	// top hover is a bit lighter
	//Color::HLSToRGBf(hue, bright * 1.2, sat, &col_bg_top_hover[0], &col_bg_top_hover[1], &col_bg_top_hover[2]);
	Color::HLSToRGBf(hue, bright +0.2, sat +0.2, &col_bg_top_hover[0], &col_bg_top_hover[1], &col_bg_top_hover[2]);
	col_bg_top_hover[3] = 1.0f;
		
	// bottom hover is a bit darker
	//Color::HLSToRGBf(hue, bright * 0.5, sat, &col_bg_bottom_hover[0], &col_bg_bottom_hover[1], &col_bg_bottom_hover[2]);
	Color::HLSToRGBf(hue, bright - 0.2 , sat - 0.2, &col_bg_bottom_hover[0], &col_bg_bottom_hover[1], &col_bg_bottom_hover[2]);
	col_bg_bottom_hover[3] = 1.0f;
	
	// text color
	Color::HLSToRGBf(hue, bright + 0.6, sat + 0.6, &col_text[0], &col_text[1], &col_text[2]);
	col_text[3] = 0.9f;	
	return *this;
}


} // namespace buttons

#endif