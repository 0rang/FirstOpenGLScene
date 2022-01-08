#ifndef FLY_H
#define FLY_H

class QImage;
class SceneWidget;

class Fly
{
public:
    Fly(QImage* tex_qimg) : texture_qimg(tex_qimg), parent(parent) {}


    QImage* texture_qimg;

    SceneWidget* parent;
};

#endif // FLY_H
