/**
 * OpenCV video streaming over TCP/IP
 * Server: Captures video from a webcam and send it to a client
 * by Isaac Maia
 */

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load the cascade classifier for face detection
    CascadeClassifier face_cascade;
    if (!face_cascade.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml")) {
        cerr << "Error loading face cascade" << endl;
        return -1;
    }

    // Open the default camera
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error: Could not open camera" << endl;
        return -1;
    }

    // Set camera resolution
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    Mat frame;
    while (true) {
        // Capture frame
        cap >> frame;
        if (frame.empty()) break;

        // Convert to grayscale for detection
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, gray);

        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));

        // Draw rectangles around the faces
        for (const auto& face : faces) {
            rectangle(frame, face, Scalar(0, 255, 0), 2);
        }

        // Display the frame
        imshow("Video Stream with Object Detection", frame);

        // Break the loop on 'ESC' key
        if (waitKey(30) == 27) break;
    }

    // Clean up
    cap.release();
    destroyAllWindows();
    return 0;
}