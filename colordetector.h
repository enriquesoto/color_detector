/*------------------------------------------------------------------------------------------*\
   This file contains material supporting chapter 3 of the cookbook:  
   Computer Vision Programming using the OpenCV Library. 
   by Robert Laganiere, Packt Publishing, 2011.

   This program is free software; permission is hereby granted to use, copy, modify, 
   and distribute this source code, or portions thereof, for any purpose, without fee, 
   subject to the restriction that the copyright notice may not be removed 
   or altered from any source or altered source distribution. 
   The software is released on an as-is basis and without any warranties of any kind. 
   In particular, the software is not guaranteed to be fault-tolerant or free from failure. 
   The author disclaims all warranties with regard to this software, any use, 
   and any consequent failure, is purely the responsibility of the user.
 
   Copyright (C) 2010-2011 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#if !defined COLORDETECT
#define COLORDETECT

#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


class ColorDetector {

  private:

	  // minimum acceptable distance
	  int minDist; 

      //difference in %
      float difference;

      // pattern and target color
      cv::Vec3b patternColor;
      cv::Vec3b targetColor;


	  // image containing resulting binary map
	  cv::Mat result;

	  // image containing color converted image
	  cv::Mat converted;

	  // inline private member function
	  // Computes the distance from target color.
      float getDistance(const cv::Vec3b& color) const {
		 // return static_cast<int>(cv::norm<int,3>(cv::Vec3i(color[0]-target[0],color[1]-target[1],color[2]-target[2])));
          return sqrt(pow(abs(color[0]-patternColor[0]),2)+
                 pow(abs(color[1]-patternColor[1]),2)+
                 pow(abs(color[2]-patternColor[2]),2));
	  }

  public:




	  // empty constructor
	  ColorDetector() : minDist(100) { 

		  // default parameter initialization here
          patternColor[0]= patternColor[1]= patternColor[2]= 0;
	  }

	  // Getters and setters

	  // Sets the color distance threshold.
	  // Threshold must be positive, otherwise distance threshold
	  // is set to 0.
	  void setColorDistanceThreshold(int distance) {

		  if (distance<0)
			  distance=0;
		  minDist= distance;
	  }

	  // Gets the color distance threshold
	  int getColorDistanceThreshold() const {

		  return minDist;
	  }

	  // Sets the color to be detected
      void setPatternColor(unsigned char red, unsigned char green, unsigned char blue) {

		  cv::Mat tmp(1,1,CV_8UC3);
          tmp.at<cv::Vec3b>(0,0)[0]= blue;
          tmp.at<cv::Vec3b>(0,0)[1]= green;
          tmp.at<cv::Vec3b>(0,0)[2]= red;

  	      // Converting the target to Lab color space 
	      cv::cvtColor(tmp, tmp, CV_BGR2Lab);

          patternColor= tmp.at<cv::Vec3b>(0,0);
	  }

	  // Sets the color to be detected
      void setPatternColor(cv::Vec3b color) {

		  cv::Mat tmp(1,1,CV_8UC3);
          tmp.at<cv::Vec3b>(0,0)= color;

  	      // Converting the target to Lab color space 
	      cv::cvtColor(tmp, tmp, CV_BGR2Lab);

          patternColor= tmp.at<cv::Vec3b>(0,0);
	  }

      void setTargetColor(unsigned char red, unsigned char green, unsigned char blue){

          cv::Mat tmp(1,1,CV_8UC3);
          tmp.at<cv::Vec3b>(0,0)[0]= blue;
          tmp.at<cv::Vec3b>(0,0)[1]= green;
          tmp.at<cv::Vec3b>(0,0)[2]= red;

          // Converting the target to Lab color space
          cv::cvtColor(tmp, tmp, CV_BGR2Lab);
          targetColor= tmp.at<cv::Vec3b>(0,0);

      }

	  // Gets the color to be detected
      cv::Vec3b getPatternColor() const {

          return patternColor;
	  }
      //get difference in %
      int getDifference() const {
        return difference;
      }

	  // Processes the image. Returns a 1-channel binary image.
	  cv::Mat process(const cv::Mat &image);
};


#endif
