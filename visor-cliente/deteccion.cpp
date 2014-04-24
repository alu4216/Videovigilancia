#include "deteccion.h"
#include <QDebug>

Deteccion::Deteccion()
{
    //crea un backgroundSubtractor y desactiva la detecccion de sombras
    backgroundSubtractor = new cv::BackgroundSubtractorMOG2(500,16,false);
    backgroundSubtractor->set("nmixtures",3);
    cierre_ = false;
}
void Deteccion::cierre(const bool &x)
{
    cierre_ = x;
}

void Deteccion::Procesador_imagen(const QImage &image)
{
    if(!cierre_)
    {

        //procesa la imagen
        cv::Mat img = QtOcv::image2Mat(image);//convierte la imagen en cv::Mat

        // Sustracción del fondo:
        (*backgroundSubtractor)(img, foregroundMask);//Quitamos el fondo

        cv::erode(foregroundMask, foregroundMask, cv::Mat(),cv::Point(-1,-1),3);//encoge las regiones de pequeño tamaño
        cv::dilate(foregroundMask, foregroundMask, cv::Mat(),cv::Point(-1,-1),3);//agranda las regiones de pequeño tamaño

        ContoursType contours;//obtenemos los contornos
        cv::findContours(foregroundMask, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); // (CV_RETR_EXTERNAL) encontradas.


       VRect.clear();//pasamos el vector de contornos a QRect
       for (ContoursType::const_iterator i = contours.begin(); i < contours.end(); ++i)
       {
            cv::Rect recta = cv::boundingRect(*i);
            QRect qrecta(recta.x,recta.y,recta.width,recta.height);
            VRect.push_back(qrecta);

       }

        //manda la imagen ya procesada
        emit Mandar_imagen(image,VRect);
    }
}
