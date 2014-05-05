#ifndef CAPTUREBUFFER_H
#define CAPTUREBUFFER_H
#include <QList>
#include <QDebug>
#include <QImage>
#include <QAbstractVideoSurface>


class CaptureBuffer : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit CaptureBuffer(){ }
    ~CaptureBuffer(){ }
    //Formatos soportados
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType =
            QAbstractVideoBuffer::NoHandle) const
    {
        Q_UNUSED (handleType);
        QList<QVideoFrame::PixelFormat> formats;
        formats << QVideoFrame::Format_ARGB32;
        formats << QVideoFrame::Format_ARGB32_Premultiplied;
        formats << QVideoFrame::Format_RGB32;
        formats << QVideoFrame::Format_RGB24;
        formats << QVideoFrame::Format_RGB565;
        formats << QVideoFrame::Format_RGB555;
        return formats;

    }
    bool present(const QVideoFrame &frame);

signals:
    void s_image(const QImage&);
public slots:

};

#endif // CAPTUREBUFFER_H
