//
//  Tracker.hpp
//  Projet
//
//  Created by Benoît Guillard on 18/03/2017.
//
//
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>


#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/video.hpp>

#include <iostream>

#include <fstream>
#include <queue>

#include "Balle.h"

#ifndef Tracker_hpp
#define Tracker_hpp

#include <stdio.h>

#endif /* Tracker_hpp */

class Tracker{
public:
    // Current frame
    cv::Mat trackerFrame;
    // Create the capture object from the webcam
    cv::VideoCapture capWebcam;
    // Frame size and type
    double frameWidth;
    double frameHeight;
    int frameType;
    // The kernels for morphology transformations :
    cv::Mat kernel1;
    // MOG2 Background subtractor
    cv::Ptr<cv::BackgroundSubtractor> pMOG2;
    // FG mask generated by MOG2 method
    cv::Mat fgMaskMOG2;
    // Homography matrix
    cv::Mat H;
    
    Tracker();
    
    ~Tracker();
    
    std::vector<cv::RotatedRect> getRectangles(Balle b);
    bool initHomography();
};
