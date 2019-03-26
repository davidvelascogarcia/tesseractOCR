// Libraries

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "iostream"

// Namespaces
using namespace std;

int main()
{
    // Output char
    char *output;

    // Welcome message
    cout<<"Welcome OCR using C++ Tesseract API"<<endl;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    if (api->Init(NULL, "eng")) {
        cout<<"ERROR: Could not start OCR Tesseract"<<endl;
        exit(1);
    }

    // Open image with leptonica library
    cout<<"Loading picture to process.."<<endl;
    Pix *image = pixRead("/home/tiagoentrenamiento/Imágenes/prueba.png");
    api->SetImage(image);
    // Get OCR result
    cout<<"Processing picture..."<<endl;
    output = api->GetUTF8Text();
    cout<<"OCR Result Output: "<<endl;
    cout<<output<<endl;

    // Release dynamic memory
    api->End();
    delete [] output;
    pixDestroy(&image);
    return 0;
}
