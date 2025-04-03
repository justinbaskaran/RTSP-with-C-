# Simple Video Object Detection

A straightforward C++ application that performs real-time object detection using OpenCV. This project demonstrates basic computer vision capabilities with a focus on simplicity and ease of use.

## Features

- Real-time video capture from webcam
- Face detection using OpenCV's Haar Cascade Classifier
- Simple and clean implementation
- Easy to extend for other types of object detection

## Prerequisites

- C++ compiler (g++ recommended)
- OpenCV 4.x
- Make build system

## Installation

1. Install OpenCV development files:
```bash
sudo apt-get install libopencv-dev
```

2. Clone this repository:
```bash
git clone <your-repository-url>
cd <repository-directory>
```

3. Build the project:
```bash
make
```

## Usage

Run the program:
```bash
./video_detector
```

- The program will open your webcam and start displaying the video feed
- Detected faces will be highlighted with green rectangles
- Press 'ESC' to exit the program

## Project Structure

```
.
├── server.cpp          # Main source file
├── Makefile           # Build configuration
└── README.md          # This file
```

## Customization

### Changing Detection Parameters

You can modify the detection parameters in `server.cpp`:

```cpp
face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));
```

Parameters:
- `1.1`: Scale factor
- `3`: Minimum neighbors
- `0`: Flags
- `Size(30, 30)`: Minimum object size

### Using Different Classifiers

To use a different Haar Cascade classifier:

1. Find the classifier file in `/usr/share/opencv4/haarcascades/`
2. Update the path in the code:
```cpp
face_cascade.load("/path/to/your/classifier.xml");
```

## Extending the Project

### Adding Multiple Object Detection

1. Load additional cascade classifiers
2. Create separate detection loops for each object type
3. Use different colors for different objects

### Using Custom Classifiers

To train your own classifier:
1. Collect positive and negative training images
2. Use `opencv_createsamples` to generate samples
3. Train using `opencv_traincascade`
4. Load your custom classifier in the code

## Troubleshooting

Common issues:
1. Camera not found: Check camera permissions and connections
2. OpenCV not found: Ensure OpenCV is properly installed
3. Compilation errors: Verify OpenCV development files are installed

## Contributing

Feel free to submit issues and enhancement requests!