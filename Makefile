vrau:
	#clang++ -Wall -O2 src/encode.cpp `pkg-config --cflags opencv` -o encode `pkg-config --libs opencv`
	#clang++ -Wall -O2 src/decode.cpp `pkg-config --cflags opencv` -o decode `pkg-config --libs opencv`
	#clang++ -Wall src/view_colors.cpp `pkg-config --cflags opencv` -o view_colors `pkg-config --libs opencv`
	#clang++ -Wall src/random.cpp `pkg-config --cflags opencv` -o random `pkg-config --libs opencv`
	#clang++ -Wall src/rgb_median.cpp `pkg-config --cflags opencv` -o rgb_analysis `pkg-config --libs opencv`
	clang++ -Wall src/img2ascii.cpp `pkg-config --cflags opencv` -o img2ascii `pkg-config --libs opencv`
	#clang++ -Wall testresize.cpp `pkg-config --cflags opencv` -o testresize `pkg-config --libs opencv`

