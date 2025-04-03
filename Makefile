CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

all: video_detector

video_detector: rtsp-with-object-detection.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f video_detector

.PHONY: all clean
