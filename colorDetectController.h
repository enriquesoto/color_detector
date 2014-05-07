#if !defined CD_CNTRLLR
#define CD_CNTRLLR

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

#include "colordetector.h"

#define WIDTHONLOAD 1024
#define HEIGHTONLOAD 768


class ColorDetectController {

  private:

 	static ColorDetectController *singleton; // pointer to the singleton

	ColorDetector *cdetect;

	// The image to be processed
    cv::Mat patternImage;
    cv::Mat targetImage;
    cv::Mat result;
    float difference;


	
  public:
	ColorDetectController() { // private constructor

		  //setting up the application
		  cdetect= new ColorDetector();
	}

	  // Sets the color distance threshold
	  void setColorDistanceThreshold(int distance) {

		  cdetect->setColorDistanceThreshold(distance);
	  }

	  // Gets the color distance threshold
	  int getColorDistanceThreshold() const {

		  return cdetect->getColorDistanceThreshold();
	  }

	  // Sets the color to be detected
      void setInputColor(unsigned char red, unsigned char green, unsigned char blue) {

          cdetect->setPatternColor(red,green,blue);
	  }

	  // Gets the color to be detected
      void getInputColor(unsigned char &red, unsigned char &green, unsigned char &blue) const {

          cv::Vec3b color= cdetect->getPatternColor();

		  red= color[2];
		  green= color[1];
		  blue= color[0];
	  }

	  // Sets the input image. Reads it from file.
      bool setPatternImage(std::string filename) {

          patternImage= cv::imread(filename);

          if (!patternImage.data)
			  return false;
          else{
              cv::resize(patternImage,patternImage,cv::Size(WIDTHONLOAD,HEIGHTONLOAD));
              setAverageColorPatternImage(patternImage);
              return true;
          }

	  }

      bool setTargetImage(std::string filename){

          targetImage= cv::imread(filename);



          if (!targetImage.data)
              return false;
          else{
              cv::resize(targetImage,targetImage,cv::Size(WIDTHONLOAD,HEIGHTONLOAD));
              setAverageColorTargetImage(targetImage);
              return true;
          }


      }

      //setAverageColor from Pattern Image Left Side!

      void setAverageColorPatternImage(const cv::Mat &image){

        cv::Scalar avgPixelIntensity = cv::mean(image);

        int blue= avgPixelIntensity.val[0];
        int green= avgPixelIntensity.val[1];
        int red = avgPixelIntensity.val[2];


        cdetect->setPatternColor(red,green,blue);


      }


      void setAverageColorTargetImage(const cv::Mat &image){
          cv::Scalar avgPixelIntensity = cv::mean(image);
          int blue= avgPixelIntensity.val[0];
          int green= avgPixelIntensity.val[1];
          int red = avgPixelIntensity.val[2];
          cdetect->setTargetColor(red,green,blue);

      }

	  // Returns the current input image.
      const cv::Mat getPatternImage() const {

          return patternImage;
	  }

      const cv::Mat getTargetImage() const {

          return targetImage;

      }

	  // Performs image processing.
	  void process() {

          result= cdetect->process(targetImage);
          difference = cdetect->getDifference();

	  }
	  

	  // Returns the image result from the latest processing.
	  const cv::Mat getLastResult() const {

		  return result;
	  }

      // Get difference in percentage

      const float getDifference() const {
          return difference;
      }

	  // Deletes all processor objects created by the controller.
	  ~ColorDetectController() {

		  delete cdetect;
	  }

	  // Singleton static members
	  static ColorDetectController *getInstance() {

		  if (singleton == 0)
			singleton= new ColorDetectController;

		  return singleton;
	  }

	  // Releases the singleton instance of this controller.
	  static void destroy() {

		  if (singleton != 0) {
			  delete singleton;
			  singleton= 0;
		  }
	  }
};

#endif
