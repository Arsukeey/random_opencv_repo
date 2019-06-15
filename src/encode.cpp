#include <opencv2/opencv.hpp>

#include <fstream>
#include <iostream>

using namespace cv;

using std::cout;
using std::endl;

// TODO: I need to do an RGB comparer, to compare how much the values
// have changed between the original and the modified image

int main(int argc, char **argv) {
	/*
		 ./encode image.png textfile.txt output_image.png
		 argv[0] = ./encode
		 argv[1] = image.png
		 argv[2] = textfile.txt
		 argv[3] = output_image.png
		 */		

	if (argc != 4) {
		cout << "Invalid number of arguments. Example: ./encode image.png text.txt output.png" << endl;
		return 1;
	}	

	// https://docs.opencv.org/3.1.0/d3/d63/classcv_1_1Mat.html
	// open original image
	Mat image = imread(argv[1]);

	// check if anything went wrong
	if (image.empty()) {
		cout << "The image is empty, or we couldn't find it." << endl;
		return 1;
	}

	// open text file
	std::ifstream txt;
	txt.open(argv[2]);

	// check if anything went wrong
	if (!(txt.is_open())) {
		cout << "Error opening text file." << endl;
		return 1;
	}

	char curr;
	// which bit it is now
	int bit_count = 0;
	// check if file has ended already
	bool eof_check = false;
	// check if it already finished writing text to image
	bool finished = false;
	
	char bit;

	/*
		 To hide text into images, we are taking one char (8 bits) and each of the 8 bits are stored
		 in the Least Significant Bits (LSB) of the pixel values (Red,Green,Blue).
		 We are manipulating bits in such way that changing LSB of the pixel values will not make a huge difference.
		 The image will still look similiar to the naked eye.
		 */

	while (!finished) {
		for (int row = 0; row < image.rows; row++) {
			for (int col = 0; col < image.cols; col++) {
				for (int color = 0; color < 3; color++) {

					}
				}
			}
		}
	}

	if (!finished) {
		cout << "An error occurred." << endl;
		return 1;
	}

	imwrite(argv[3], image);
	return 0;
}
