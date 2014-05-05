#if !defined CD_CNTRLLR
#define CD_CNTRLLR

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

#include "colordetector.h"

class ColorDetectController {

  private:

 	static ColorDetectController *singleton; // pointer to the singleton

	ColorDetector *cdetect;

	// The image to be processed
    cv::Mat patternImage;
    cv::Mat targetImage;
	cv::Mat result;
	
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
      void setTargetColor(unsigned char red, unsigned char green, unsigned char blue) {

		  cdetect->setTargetColor(red,green,blue);
	  }

	  // Gets the color to be detected
	  void getTargetColor(unsigned char &red, unsigned char &green, unsigned char &blue) const {

		  cv::Vec3b color= cdetect->getTargetColor();

		  red= color[2];
		  green= color[1];
		  blue= color[0];
	  }

	  // Sets the input image. Reads it from file.
	  bool setInputImage(std::string filename) {

          patternImage= cv::imread(filename);

          if (!patternImage.data)
			  return false;
          else{
              setAverageColorPatternImage(patternImage);
              return true;
          }

	  }

      bool setTargetImage(std::string filename){

          targetImage= cv::imread(filename);



          if (!targetImage.data)
              return false;
          else
              return true;

      }

      //getLabAverage

      void setAverageColorPatternImage(const cv::Mat &image){

        cv::Scalar avgPixelIntensity = cv::mean(image);

        int blue= avgPixelIntensity.val[0];
        int green= avgPixelIntensity.val[1];
        int red = avgPixelIntensity.val[2];


        cdetect->setTargetColor(red,green,blue);


      }

	  // Returns the current input image.
      const cv::Mat getInputImage() const {

          return patternImage;
	  }

      const cv::Mat getTargetImage() const {

          return targetImage;

      }

	  // Performs image processing.
	  void process() {

          result= cdetect->process(targetImage);
	  }
	  

	  // Returns the image result from the latest processing.
	  const cv::Mat getLastResult() const {

		  return result;
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
