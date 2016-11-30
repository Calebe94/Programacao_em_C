#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include<unistd.h>
class display{
	public:
			Display                 *display;
   			Visual                  *visual;
			XSetWindowAttributes    frame_attributes;
			Window                  frame_window;
			XFontStruct             *fontinfo;
			XGCValues               gr_values;
			GC                      graphical_context;
    		XKeyEvent               event;

			int                     depth;
    		int                     text_x;
   			int                     text_y;
		void Create(){
			display = XOpenDisplay(NULL);
			visual = DefaultVisual(display, 0);
			depth  = DefaultDepth(display, 0);
    	
			frame_attributes.background_pixel = XWhitePixel(display, 0);
			/* create the application window */
			frame_window = XCreateWindow(display, XRootWindow(display, 0),
                                 0, 0, 300, 200, 5, depth,
                                 InputOutput, visual, CWBackPixel,
                                 &frame_attributes);
			XStoreName(display, frame_window, "VeiWatch");
			XSelectInput(display, frame_window, ExposureMask | StructureNotifyMask);

			fontinfo = XLoadQueryFont(display, "10x20");
		    gr_values.font = fontinfo->fid;
			gr_values.foreground = XBlackPixel(display, 0);
			graphical_context = XCreateGC(display, frame_window, 
                                  GCFont+GCForeground, &gr_values);
			XMapWindow(display, frame_window);
		}
		void Print(unsigned int bpm,float temp){
			char                    hello_string[30];
			char 					bpm_string[30];
			snprintf(hello_string,30,"Temperatura:%.1f°C",temp);
			snprintf(bpm_string,30,"BPM:        %dBPM",bpm);
			int 					bpm_lenght=strlen(bpm_string);
			int                     hello_string_length = strlen(hello_string);
			XNextEvent(display, (XEvent *)&event);
			switch ( event.type ) {
				case Expose:{	
				XWindowAttributes window_attributes;
				int font_direction, font_ascent, font_descent;
				XCharStruct text_structure;
				XTextExtents(fontinfo, hello_string, hello_string_length,&font_direction, &font_ascent, &font_descent, 
                             &text_structure);

				XGetWindowAttributes(display, frame_window, &window_attributes);
				text_x = (window_attributes.width - text_structure.width)/2;
				text_y = (window_attributes.height - (text_structure.ascent+text_structure.descent))/2;
				XDrawString(display, frame_window, graphical_context,text_x, text_y, hello_string, hello_string_length);
				printf("X:%d\tY:%d\n",text_x,text_y);
				XDrawString(display, frame_window, graphical_context,text_x, text_y+50, bpm_string,bpm_lenght);
				break;
			}
			default:
			break;
			}
		}
		void Println(unsigned int bpm,float temp){
				char                    hello_string[30];
				char 					bpm_string[30];
				snprintf(hello_string,30,"Temperatura:%.1f°C",temp);
				snprintf(bpm_string,30,"BPM:        %dBPM",bpm);
				int 					bpm_lenght=strlen(bpm_string);
				int                     hello_string_length = strlen(hello_string);
			XWindowAttributes window_attributes;
				int font_direction, font_ascent, font_descent;
				XCharStruct text_structure;
				
				XGetWindowAttributes(display, frame_window, &window_attributes);
				text_x = (window_attributes.width - text_structure.width)/2;
				text_y = (window_attributes.height - (text_structure.ascent+text_structure.descent))/2;
				XDrawString(display, frame_window, graphical_context,text_x, text_y, hello_string, hello_string_length);
				printf("X:%d\tY:%d\n",text_x,text_y);
				XDrawString(display, frame_window, graphical_context,text_x, text_y+50, bpm_string,bpm_lenght);
		}
		
};
int main(void){
	display x11;
	x11.Create();
	int bpm = 65;
	float temp = 36.6;
	x11.Print(65,36.6);
	while(1){
		x11.Println(bpm,temp);
		//x11.Print(bpm,temp);
		usleep(100*100);
		bpm = bpm + 5;
		temp = temp + 3;
	}	
}
