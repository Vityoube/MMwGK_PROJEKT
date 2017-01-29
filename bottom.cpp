#include "bottom.h"

Bottom::Bottom()
{

}

void Bottom::draw(){
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex3f(center_x-9,center_y,-2.0f);
    glVertex3f(center_x+9,center_y,-2.0f);
    glVertex3f(center_x+9,center_y, -20.0f);
    glVertex3f(center_x-9,center_y,-20.0f);
    glEnd();
}

GLuint Bottom::load_texture(FIBITMAP * bitmap){
    GLuint tex_id=0;
    int x=0, y=0;
    int height,width;
    RGBQUAD rgbquad;
    FREE_IMAGE_TYPE image_type;
    BITMAPINFOHEADER * header;
    image_type=FreeImage_GetImageType(bitmap);
    height=FreeImage_GetHeight(bitmap);
    width=FreeImage_GetWidth(bitmap);
    header=FreeImage_GetInfoHeader(bitmap);
    int scanLineWidth=((3*width)%4 == 0) ? 3*width : ((3*width/4)*4)+4;
    unsigned char * texels=(GLubyte*)calloc(height*scanLineWidth,sizeof(GLubyte));
    for (x=0;x<width;x++)
        for (y=0;y<height;y++){
            FreeImage_GetPixelColor(bitmap,x,y,&rgbquad);
            texels[y*scanLineWidth+3*x]=((GLbyte*)&rgbquad)[2];
            texels[y*scanLineWidth+3*x+1]=((GLbyte*)&rgbquad)[1];
            texels[y*scanLineWidth+3*x+2]=((GLbyte*)&rgbquad)[0];
        }
    glGenTextures(1,&tex_id);
    glBindTexture(GL_TEXTURE_2D,tex_id);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,texels);
    free(texels);
    FreeImage_Unload(bitmap);
    return tex_id;
}
