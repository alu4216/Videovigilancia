#ifndef DETECCION_H
#define DETECCION_H

#include "cvmatandqimage.h"
#include <opencv2/opencv.hpp>

typedef std::vector<cv::Mat> ImagesType;
typedef std::vector<std::vector<cv::Point> > ContoursType;

class Deteccion : public QObject
{
    Q_OBJECT

    signals:
        // Señal emitida cuando el frame ha sido procesado
        void Mandar_imagen(const QImage &image,const QVector<QRect> &VRect);

    public slots:
        // Slot para procesar la imagen
        void Procesador_imagen(const QImage &image);
    public:
        Deteccion();
        void cierre(const bool &x);

    private:
        cv::BackgroundSubtractorMOG2 *backgroundSubtractor;
        cv::Mat foregroundMask;
        QVector<QRect> VRect;
        bool cierre_;
};
#endif
