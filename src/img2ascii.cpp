#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

double average(int red, int blue, int green);

int main(int argc, char **argv) {
	if (argc != 4) {
		cout << "Wrong number of arguments" << endl << "ex: image.jpg sizeX sizeY" << endl;
	}

	Mat image = imread(argv[1]);

	if (image.empty()) {
		cout << "Failed reading image." << endl;
	}

	int x = atoi(argv[2]);
	int y = atoi(argv[3]);

	// change image size
	resize(image, image, Size(x, y), 0, 0, INTER_NEAREST);

	// Possible characters to use when converting to ascii
	string chars = "MNHQ$OC?7>!:-;. ";

	// initialize string which will contain what we want from here
	string res = "";
	vector<int> colors;

	// greyscale image first
	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			Vec3b pixel = image.at<Vec3b>(Point(col, row));

			pixel[0] = average(pixel.val[0], pixel.val[1], pixel.val[2]);
			pixel[1] = average(pixel.val[0], pixel.val[1], pixel.val[2]);
			pixel[2] = average(pixel.val[0], pixel.val[1], pixel.val[2]);

			colors.push_back(pixel[0]);
		}
		colors.push_back(1337);
	}


	// 1337 is the magic number here
	for (auto color : colors) {
		res.push_back(chars[int(color / 256.0 * 16)]);
		if (color == 1337) {
			res.push_back('\n');
		}
	}
	cout << res << endl;
}

inline double average(int red, int blue, int green) {
	return double( (red + blue + green) / 3 );
}
