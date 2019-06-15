#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>

using std::cout;
using std::endl;

using namespace cv;

inline bool is_bit_set(char bit) {
	return (bit & 1) ? true : false;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Wrong arguments. Example: ./decode image.png" << endl;
		return 1;
	}
	
	Mat image = imread(argv[1]);
	if (image.empty()) {
		cout << "Image couldn't be found or it was empty." << endl;
		return 1;
	}
	
	char curr;
	int bit_count = 0;
	bool finished = false;

	while (!finished) {
		for (int row = 0; row < image.rows; row++) {
			for (int col = 0; col < image.cols; col++) {
				for (int color = 0; color < 3; color++) {
					// Vec3b is an alias to a vec of 3 unsigned ints.
					Vec3b	pix = image.at<Vec3b>(row, col);

					pix[color] 
				}
			}
		}
	}
	return 0;
}
