#include <opencv2/opencv.hpp>

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
using namespace cv;

int generate_random() {
		struct timeval t;
		gettimeofday(&t, NULL);
		pid_t pid = getpid();
		srand(t.tv_usec * t.tv_sec * pid);

		return rand() % 255;
}

int main(int argc, char **argv) {
	Mat image(500, 500, CV_8UC3, Scalar(0, 0, 0));

	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			Vec3b pixel;
			pixel[0] = generate_random();
			pixel[1] = generate_random();
			pixel[2] = generate_random();

			image.at<Vec3b>(Point(row,col)) = pixel;
		}
	}
	imwrite(argv[1], image);
	return 0;
}
