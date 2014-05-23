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

#include "colordetector.h"
#include <QDebug>

#define MAXVALUEDIFFERENCE 254;

void ColorDetector::paint(cv::Vec3b &color)
{
    color[0]= blueColor;
    color[1]= greenColor;
    color[2]= redColor;

}


cv::Mat ColorDetector::process(const cv::Mat &image) {
	
	  // re-allocate binary map if necessary
	  // same size as input image, but 1-channel
      //result.create(image.rows,image.cols,CV_8U);
        result = image.clone();
	  // re-allocate intermediate image if necessary
        cv::imshow("resultado",result);
	  converted.create(image.rows,image.cols,image.type());

	  // Converting to Lab color space 
	  cv::cvtColor(image, converted, CV_BGR2Lab);

      //difference = 100 - 100*getDistance(targetColor)/MAXVALUEDIFFERENCE;



//      qDebug()<<"diferencia"<<100*getDistance(targetColor)/MAXVALUEDIFFERENCE;

//      qDebug()<<"dccc"<<difference;

      float countDifference = 0;

	  // get the iterators
	  cv::Mat_<cv::Vec3b>::iterator it= converted.begin<cv::Vec3b>();
	  cv::Mat_<cv::Vec3b>::iterator itend= converted.end<cv::Vec3b>();
      //cv::Mat_<uchar>::iterator itout= result.begin<uchar>();
      cv::Mat_<cv::Vec3b>::iterator itout= result.begin<cv::Vec3b>();

	  // for each pixel
	  for ( ; it!= itend; ++it, ++itout) {

		// process each pixel ---------------------

		  // compute distance from target color
          if (getDistance(*it)>maxDist) {
              //qDebug()<<"distancia:"<<getDistance(*it)<<endl;
              paint(*itout);
              countDifference++;
          }

//          else {
//			  *itout= 0;
//		  }

        // end of pixel processing ----------------
      }
      qDebug()<<countDifference;
      int totalPixels = image.rows*image.cols;
      qDebug()<<"pixeles totales " << image.rows*image.cols;
      double division = countDifference/totalPixels*100;
      qDebug()<<"division " << division;
      difference= 100 - countDifference/totalPixels*100;
      return result;
}

void ColorDetector::calculeOppositeColor() //calcular color opuesto para pintar panel ! :D
{

    int threshold=150;
    cv::Vec3b redLab,greenLab,bluelab;
    redLab[0] = 54; redLab[1] = 209 ; redLab[2]=198;
    greenLab[0] = 224; greenLab[1] = 42; greenLab[3] = 211;
    bluelab[0] = 29; bluelab[1] = 196; bluelab[3] = 11;
    //green[0] = 0; green[1] = 255 ; green[2] = 0;
    int MAX = 255;
    redColor = greenColor = blueColor =0;

    cv::Mat tmp(1,1,CV_8UC3);
    tmp.at<cv::Vec3b>(0,0) = patternColor;
    cv::cvtColor(tmp,tmp,CV_Lab2BGR);
    cv::imshow("xD",tmp);
    qDebug()<<"valor l"<<tmp.at<cv::Vec3b>(0,0)[0]<<"valor a"<<tmp.at<cv::Vec3b>(0,0)[1]<<"valor b"<<tmp.at<cv::Vec3b>(0,0)[2];
    if(getDistance(redLab)>threshold){
        redColor = MAX;
    }else
        if(getDistance(greenLab)<threshold){
            greenColor=MAX; //green
        }else
            blueColor=MAX;

}



