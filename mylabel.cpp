
#include "mylabel.h"
void MyLabel::mouseReleaseEvent(QMouseEvent *)
{
    emit clicked(this);
}
