// Libraries

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "iostream"
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/highgui.h>
#include <string>


// Namespaces

using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::sig::draw;
using namespace cv;
using namespace std;

int main()
{
    //********************
    // Read with Leptonica
    //********************

    // Output char
  /*  char *output_leptonica;

    // Welcome message
    cout<<"Welcome OCR using C++ Tesseract API"<<endl;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    if (api->Init(NULL, "eng")) {
        cout<<"ERROR: Could not start OCR Tesseract"<<endl;
        exit(1);
    }

    // Open image with leptonica library
    cout<<"Loading picture to process with leptonica.."<<endl;
    Pix *image_leptonica = pixRead("./../images/prueba.png");
    api->SetImage(image_leptonica);
    // Get OCR result
    cout<<"Processing picture..."<<endl;
    output_leptonica = api->GetUTF8Text();
    cout<<"OCR Result Output: "<<endl;
    cout<<output_leptonica<<endl;

    // Release dynamic memory
    api->End();
    delete [] output_leptonica;
    pixDestroy(&image_leptonica);*/

  //  return 0;

  cout<<endl;
  cout<<endl;
  Network yarp;
  cout<<"Iniciando red de YARP"<<endl;
  BufferedPort<ImageOf<PixelRgb> > port;
  port.open("/tesseractOCR/img:i");
  cout<<"Esperando fuentes de imagen..."<<endl;


  //******************
  // Read with OpenCV
  //*****************

  // Output string
  string output_opencv;

  tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

  // Open image with leptonica library
  cout<<"Loading picture to process with OpenCV.."<<endl;

  // Initialize tesseract with eng language

  ocr->Init(NULL, "eng", tesseract::OEM_CUBE_ONLY);
  ocr->SetPageSegMode(tesseract::PSM_AUTO);

  while (true) {

  ImageOf<PixelRgb> *img = port.read();
  Mat image_opencv  = cv::cvarrToMat((IplImage *)img->getIplImage());
  // Read image with OpenCV


  // Set image data
  ocr->SetImage(image_opencv.data, image_opencv.cols, image_opencv.rows, 3, image_opencv.step);

  // Get OCR result
  cout<<"Processing picture with OpenCV..."<<endl;
  // Run Tesseract OCR on image
  output_opencv = string(ocr->GetUTF8Text());

  cout<<"OpenCV OCR Result Output: "<<endl;
  // Show processed results
  cout << output_opencv << endl;
}
return 0;
}
