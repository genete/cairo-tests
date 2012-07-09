#include <cairo.h>

int main (int argc, char *argv[])
{
	cairo_surface_t *surface;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 480, 270);
	cairo_surface_flush(surface);
	
	unsigned char* data;
	unsigned char*position;
	int w, h, stride;
	data=cairo_image_surface_get_data(surface);
	w=cairo_image_surface_get_width(surface);
	h=cairo_image_surface_get_height(surface);
	stride=cairo_image_surface_get_stride(surface);
	unsigned char a, r, g, b;
	int x, y;
	a=255;
	r=178;
	g=55;
	b=55;
	for(y=0; y<h; y++)
	{
		for(x=0; x<w*4; x+=4)
		{
			position= (unsigned char*)(((char*)data)+y*stride);
			position[x]=a;
			position[x+1]=r;
			position[x+2]=g;
			position[x+3]=b;
		}
	}
	cairo_surface_mark_dirty(surface);
	
	cairo_surface_write_to_png(surface, "image.png");
	
	cairo_surface_destroy(surface);
	
	return 0;
}