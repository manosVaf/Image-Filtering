
#ifndef _PPM
#define _PPM



namespace imaging
{

	Image * ReadPPM(const char * filename);
	bool WritePPM(Image & image, const char * filename);

} //namespace imaging

#endif