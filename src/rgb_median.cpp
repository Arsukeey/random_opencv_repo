#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

double average(vector<int> arr);

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Wrong number of arguments" << endl;
	}

	Mat image = imread(argv[1]);

	if (image.empty()) {
		cout << "Failed reading image." << endl;
	}

	vector<int> red;
	vector<int> blue;
	vector<int> green;


	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			// BGR
			for (int color = 0; color < 3; color++) {
				Vec3b pixel = image.at<Vec3b>(Point(row,col));

				blue.push_back(pixel.val[0]);	
				green.push_back(pixel.val[1]);	
				red.push_back(pixel.val[2]);	
			}
		}
	}

	cout << "Red: " << average(red) << endl;
	cout << "Blue: " << average(blue) << endl;
	cout << "Green: " << average(green) << endl;
}

double average(vector<int> arr) {
	int i, sum = 0;       
	double avg;          

	for (i = 0; i < arr.size(); ++i) {
		sum += arr[i];
	}
	avg = double(sum) / arr.size();

	return avg;
}
