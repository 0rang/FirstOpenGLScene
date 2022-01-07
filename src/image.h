#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <QImage>
#include <GL/glu.h>

class Image
{
public:
    Image(const std::string& file_name);

    ~Image();

private:
    GLubyte* _image;

    unsigned int _width;
    unsigned int _height;

    QImage* p_qimage;

};

#endif // IMAGE_H
