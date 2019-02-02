#include <algorithm>
#include "Blur.h"

using namespace imaging;
using namespace filters;

Image& Blur::operator<< (Image& source) {
	temp = new Vec3<float>[source.getHeight()*source.getWidth()];
	int sum = 0;
	Vec3<float>  tmp;
	for (int j = 0; j < source.getHeight(); j++) {
		for (int i = 0; i < source.getWidth(); i++) {
			for (int k = -1; k <= 1; k++) {
				for (int m = -1; m <= 1; m++) {
					if ((i + k) >= 0 && (i + k) <= source.getWidth() - 1) {
						if ((j + m) >= 0 && (j + m) <= source.getHeight() - 1) {
							tmp += source.getPixel(i+k, j+m);
							sum++;


						}
					}
				}
			}
			tmp /= sum;
			temp[j*source.getWidth() + i] = tmp;
			sum = 0;
			tmp = 0;
		}
	}
	memcpy(source.getRawDataPtr(), temp, source.getHeight()*source.getWidth()*sizeof(Vec3<float>));
	delete[] temp;
	return source;
	
}