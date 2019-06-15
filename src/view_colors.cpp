#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "wrong num of args" << endl;
		return 1;
	}

	Mat image = imread(argv[1]);

	// duplicate image
	hconcat(image, image, image);
	hconcat(image, image, image);
	// hconcat(image, image, image);

	for (int col = 0; col < image.cols / 4; col++) {
		for (int row = 0; row < image.rows; row++) {
			Vec3b  pixel = image.at<Vec3b>(Point(col,row));

			uint8_t tmp_blu = pixel.val[0];
			uint8_t tmp_gre = pixel.val[1];

			// red
			pixel.val[0] = 0;
			pixel.val[1] = 0;

			image.at<Vec3b>(Point(col + image.cols / 4, row)) = pixel;

			// blue
			pixel.val[1] = 0;
			pixel.val[2] = 0;

			pixel.val[0] = tmp_blu;

			image.at<Vec3b>(Point(col + image.cols / 2, row)) = pixel;

			// green
			pixel.val[0] = 0;
			pixel.val[2] = 0;

			pixel.val[1] = tmp_gre;

			image.at<Vec3b>(Point(col + (image.cols / 4 * 3), row)) = pixel;
		}
	}

  namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
  imshow( "Display window", image );                   // Show our image inside it.

	waitKey(0);

	imwrite(argv[2], image);
	return 0;
}
